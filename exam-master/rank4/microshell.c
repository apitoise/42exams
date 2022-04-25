/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:04:01 by fcadet            #+#    #+#             */
/*   Updated: 2020/02/13 13:22:23 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_PARAM	100

int		in_out[2];

void	put_str(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		write(fd, str++, 1);
}

void	reset_in_out(int in, int out)
{
	if (in_out[0] != 0)
		close(in_out[0]);
	in_out[0] = in;
	if (in_out[1] != 1)
		close(in_out[1]);
	in_out[1] = out;
}

int		error(char *fcn, char *msg, char *var)
{
	reset_in_out(0, 1);
	put_str("error: ", 2);
	put_str(fcn, 2);
	if (fcn)
		put_str(": ", 2);
	put_str(msg, 2);
	if (var)
		put_str(" ", 2);
	put_str(var, 2);
	put_str("\n", 2);
	return (-1);
}

void	cd(char **args, int end)
{
	if (end != 2)
		error("cd", "bad arguments", NULL);
	else if (chdir(args[1]) == -1)
		error("cd", "cannot change directory to", args[1]);
}

void	launch_exec(char **args, char **par, char **env)
{
	pid_t	pid;
	int		ret;

	if (!(pid = fork()))
	{
		dup2(in_out[0], 0);
		dup2(in_out[1], 1);
		ret = execve(*args, par, env);
		close(0);
		close(1);
		if (ret == -1)
			exit(error(NULL, "cannot execute", *args));
		exit(0);
	}
	else if (pid < 0)
		exit(error(NULL, "fatal", NULL));
	else
		waitpid(pid, NULL, 0);
}

void	exec_cmd(char ***args, int end, char **env)
{
	char	*par[MAX_PARAM];
	int		new_pipe[2];

	if (end == 0);
	else if (!strcmp(**args, "cd"))
		cd(*args, end);
	else
	{
		for (int i = 0; i < end; ++i)
			par[i] = (*args)[i];
		par[end] = NULL;
		if ((*args)[end] && !strcmp((*args)[end], "|"))
		{
			if (pipe(new_pipe) == -1)
				exit(error(NULL, "fatal", NULL));
			in_out[1] = new_pipe[1];
			launch_exec(*args, par, env);
			reset_in_out(new_pipe[0], 1);
			*args += end;
			return ;
		}
		else
			launch_exec(*args, par, env);
	}
	reset_in_out(0, 1);
	*args += end;
}

int		main(int ac, char **av, char **env)
{
	int		i;

	(void)ac;
	in_out[0] = 0;
	in_out[1] = 1;
	while (*(av++))
	{
		for (i = 0; av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"); ++i);
		exec_cmd(&av, i, env);
	}
	reset_in_out(0, 1);
	return (0);
}
