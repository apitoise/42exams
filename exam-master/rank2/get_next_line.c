/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrfalco <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:38:27 by herrfalco         #+#    #+#             */
/*   Updated: 2019/11/18 20:56:53 by herrfalco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFF	1

typedef struct		s_file
{
	int		fd;
	char	buf[BUFF + 1];
	int		i;
}					t_file;

void	init_file(t_file *f, int fd)
{
	int		i;

	f->fd = fd;
	f->i = BUFF;
	i = 0;
	while (i <= BUFF)
	{
		f->buf[i] = '\0';
		i++;
	}
}

int		cat_buf(char **line, t_file *f)
{
	int		a;
	int		b;
	char	*new;

	a = 0;
	while ((*line)[a])
		a++;
	b = 0;
	while (f->buf[f->i + b] && f->buf[f->i + b] != '\n')
		b++;
	if (!(new = malloc((a + b + 1) * sizeof(char))))
		return (-1);
	a = 0;
	while ((*line)[a])
	{
		new[a] = (*line)[a];
		a++;
	}
	b = 0;
	while (f->buf[f->i + b] && f->buf[f->i + b] != '\n')
	{
		new[a + b] = f->buf[f->i + b];
		b++;
	}
	new[a + b] = '\0';
	free(*line);
	*line = new;
	return (b);
}

int		get_next_line(int fd, char **line)
{
	static t_file	f = { -1, { 0 }, 0 };
	int				buf_s;
	int				cat_s;

	if (fd < 0 || !line || !(*line = malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	if (f.fd != fd)
		init_file(&f, fd);
	while (f.buf[f.i] != '\n')
	{
		if (!f.buf[f.i])
		{
			if ((buf_s = read(fd, f.buf, BUFF)) == -1)
			{
				free(*line);
				return (-1);
			}
			if (!buf_s)
			{
				f.fd = -1;
				return (0);
			}
			f.buf[buf_s] = '\0';
			f.i = 0;
		}
		if ((cat_s = cat_buf(line, &f)) == -1)
		{
			free(*line);
			return (-1);
		}
		f.i += cat_s;
	}
	f.i++;
	return (1);
}
