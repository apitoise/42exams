/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:41:54 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/02 15:45:54 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(char* str) {
	int	len;

	len = 0;
	while (str[len])
		len++;
	return len;
}

char*	ft_strchr(char* str, int c) {
	while (*str != (char)c) {
		if (*str == '\0' && (char)c != '\0')
			return NULL;
		str++;
	}
	return (str);
}

char*	ft_strjoin(char* s1, char* s2) {
	int		len;
	char*	res;
	int		i;

	if (!s1 || !s2)
		return NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return NULL;
	i = 0;
	while (*s1) {
		res[i] = *s1;
		i++;
		s1++;
	}
	while (*s2) {
		res[i] = *s2;
		i++;
		s2++;
	}
	res[i] = '\0';
	return res;
}

char*	ft_get_line(char* file) {
	int		i;
	char*	str;

	i = 0;
	if (!file[i])
		return NULL;
	while (file[i] && file[i] != '\n')
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 2))))
		return NULL;
	i = 0;
	while (file[i] && file[i] != '\n') {
		str[i] = file[i];
		i++;
	}
	if (file[i] == '\n') {
		str[i] = file[i];
		i++;
	}
	str[i] = '\0';
	return str;
}

char*	ft_new_file(char* file) {
	int		i;
	int		j;
	char*	str;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i]) {
		free(file);
		return NULL;
	}
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(file) - i + 1))))
		return NULL;
	i++;
	j = 0;
	while (file[i])
		str[j++] = file[i++];
	str[j] = '\0';
	free(file);
	return str;
}

char*	ft_read(int fd, char* file) {
	char*	buffer;
	int		read_len;
	
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return NULL;
	read_len = 1;
	while (!ft_strchr(file, '\n') && read_len != 0) {
		if ((read_len = read(fd, buffer, BUFFER_SIZE)) == -1) {
			free(buffer);
			return NULL;
		}
		buffer[read_len] = '\0';
		file = ft_strjoin(file, buffer);
	}
	free(buffer);
	return (file);
}

char*	get_next_line(int fd) {
	char*			line;
	static char*	file = "";
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	file = ft_read(fd, file);
	if (!file)
		return NULL;
	line = ft_get_line(file);
	file = ft_new_file(file);
	return (line);
}

int	main(int ac, char **av) {
	int		fd;
	char*	line;
	
	if (ac != 2)
		return 0;
	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s", line);
	close(fd);
	return 0;
}
