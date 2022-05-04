#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

typedef struct	s_cli {
	int	id;
	int	sock;
	char	*buff;
	struct s_cli	*next;
}				t_cli;

typedef struct	s_sets {
	fd_set	rd;
	fd_set	wr;
	fd_set	sav;
}				t_sets;

typedef struct	s_glob {
	int		main_sock;
	int		last_id;
	t_cli	*cli_lst;
	t_sets	sets;
	char	*cut_msg;
	char	*snd_msg;
}				t_glob;

t_glob	glob;

int	get_max_fd(void) {
	t_cli	*cli;
	int		max = -1;

	for (cli = glob.cli_lst; cli; cli = cli->next)
		if (cli->sock > max)
			max = cli->sock;
	return (max < 0 ? glob.main_sock : max);
}

void	del_msg(void) {
	if (glob.cut_msg)
		free(glob.cut_msg);
	glob.cut_msg = NULL;
	if (glob.snd_msg)
		free(glob.snd_msg);
	glob.snd_msg = NULL;
}

int		rm_cli(int sock) {
	t_cli	*prev = NULL;
	t_cli	*cli;
	int		id;

	for (cli = glob.cli_lst; cli->sock != sock; cli = cli->next)
		prev = cli;
	if (prev)
		prev->next = cli->next;
	else
		glob.cli_lst = cli->next;
	id = cli->id;
	close(cli->sock);
	if (cli->buff)
		free(cli->buff);
	free(cli);
	FD_CLR(sock, &glob.sets.sav);
	return (id);
}

void	fat_err(void) {
	write(2, "Fatal error\n", 12);
	if (glob.main_sock != -1)
		close(glob.main_sock);
	while (glob.cli_lst)
		rm_cli(glob.cli_lst->sock);
	del_msg();
	exit(1);
}

int	add_cli(int sock) {
	t_cli	*new = malloc(sizeof(t_cli));

	if (!new) {
		close(sock);
		fat_err();
	}
	new->sock = sock;
	new->id = glob.last_id++;
	new->buff = NULL;
	new->next = glob.cli_lst;
	glob.cli_lst = new;
	FD_SET(sock, &glob.sets.sav);
	return (new->id);
}

void	str_add(char **dst, char *src) {
	char	*res = calloc(1, sizeof(char) * ((*dst ? strlen(*dst) : 0) + strlen(src) + 1));

	if (!res)
		fat_err();
	if (*dst) {
		strcat(res, *dst);
		free(*dst);
	}
	strcat(res, src);
	*dst = res;
}

int		get_msg(char **msgs) {
	char	*rem;
	int		i;

	for (i = 0; (*msgs)[i]; ++i) {
		if ((*msgs)[i] == '\n') {
			if (!(rem = calloc(1, sizeof(char) * (strlen(&(*msgs)[i + 1]) + 1))))
				fat_err();
			strcpy(rem, &(*msgs)[i + 1]);
			(*msgs)[i + 1] = '\0';
			glob.cut_msg = *msgs;
			*msgs= rem;
			return (1);
		}
	}
	return (0);
}

void	broadcast(char *msg, int from) {
	t_cli	*cli;

	for (cli = glob.cli_lst; cli; cli = cli->next) {
		if (FD_ISSET(cli->sock, &glob.sets.wr) && cli->sock != from)
			send(cli->sock, msg, strlen(msg), 0);
	}
}

void	init_main_sock(int port) {
	struct sockaddr_in	serv_addr = { 0 };

	if (port <= 0 || (glob.main_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		fat_err();
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(0x7f000001);
	serv_addr.sin_port = htons(port);
	if (bind(glob.main_sock, (const struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) || listen(glob.main_sock, 10))
		fat_err();
}

void	new_cli(void) {
	int		cli_sock;
	char	msg[64];

	if (FD_ISSET(glob.main_sock, &glob.sets.rd) && (cli_sock = accept(glob.main_sock, NULL, NULL)) >= 0) {
		fcntl(cli_sock, F_SETFL, O_NONBLOCK);
		sprintf(msg, "server: client %d just arrived\n", add_cli(cli_sock));
		broadcast(msg, cli_sock);
	}
}

int	main(int ac, char **av) {
	t_cli	*cli;
	t_cli	*cli_next;
	char	buff[4097];
	char	msg[64];
	int		recv_ret;
	int		size;

	if (ac != 2) {
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	bzero(&glob, sizeof(t_glob));
	init_main_sock(atoi(av[1]));
	FD_ZERO(&glob.sets.sav);
	FD_SET(glob.main_sock, &glob.sets.sav);
	while (42) {
		glob.sets.rd = glob.sets.sav;
		glob.sets.wr = glob.sets.sav;
		select(get_max_fd() + 1, &glob.sets.rd, &glob.sets.wr, NULL, NULL);
		new_cli();
		for(cli = glob.cli_lst; cli; cli = cli_next) {
			cli_next = cli->next;
			if (FD_ISSET(cli->sock, &glob.sets.rd)) {
				size = 0;
				while ((recv_ret = recv(cli->sock, buff, 4096, 0)) > 0) {
					buff[recv_ret] = '\0';
					size+= recv_ret;
					str_add(&cli->buff, buff);
				}
				if (size) {
					while (get_msg(&cli->buff)) {
						if (!(glob.snd_msg = calloc(1, sizeof(char) * (20 + strlen(glob.cut_msg)))))
							fat_err();
						sprintf(glob.snd_msg, "client %d: %s", cli->id, glob.cut_msg);
						broadcast(glob.snd_msg, cli->sock);
						del_msg();
					}
				}
				else {
					sprintf(msg, "server: client %d just left\n", rm_cli(cli->sock));
					broadcast(msg, -1);
				}
			}
		}
	}
	return (0);
}
