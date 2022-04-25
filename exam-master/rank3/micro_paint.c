/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrfalco <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:37:38 by herrfalco         #+#    #+#             */
/*   Updated: 2019/12/09 15:41:09 by herrfalco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_can
{
	int		w;
	int		h;
	char	bg;
	char	**array;
}				t_can;

typedef struct	s_rec
{
	char	op;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
}				t_rec;

int		can_ok(t_can *can)
{
	if (can->w < 1 || can->w > 300)	
		return (0);
	if (can->h < 1 || can->h > 300)	
		return (0);
	return (1);
}

int		rec_ok(t_rec *rec)
{
	if (rec->op != 'r' && rec->op != 'R')
		return (0);
	if (rec->w <= 0)	
		return (0);
	if (rec->h <= 0)	
		return (0);
	return (1);
}

void	new_can(t_can *can)
{
	int		y = -1;
	int		x;

	can->array = malloc(can->h * sizeof(char *));
	while (++y < can->h)
	{
		can->array[y] = malloc(can->w * sizeof(char));
		x = -1;
		while (++x < can->w)
			can->array[y][x] = can->bg;
	}
}

void	del_can(t_can *can)
{
	int		y = -1;

	while (++y < can->h)
		free(can->array[y]);
	free(can->array);
}

void	print_can(t_can *can)
{
	int		y = -1;
	int		x;

	while (++y < can->h)
	{
		x = -1;
		while (++x < can->w)
			write(1, &can->array[y][x], 1);
		write(1, "\n", 1);
	}
}

void	mod_rec(t_rec *rec)
{
	float	bx = (int)(rec->x + rec->w);
	float	by = (int)(rec->y + rec->h);

	rec->x = rec->x - (int)rec->x ? (int)rec->x + 1 : rec->x;
	rec->y = rec->y - (int)rec->y ? (int)rec->y + 1 : rec->y;
	rec->w = bx - rec->x;
	rec->h = by - rec->y;
}

void	put_rec(t_can *can, t_rec *rec)
{
	int		y = -1;
	int		x;

	while (++y < can->h)
	{
		x = -1;
		while (++x < can->w)
		{
			if (y >= rec->y && y <= rec->y + rec->h)
			{
				if (x == rec->x || x == rec->x + rec->w)
					can->array[y][x] = rec->c;
				else if (x > rec->x && x < rec->x + rec->w)
					if ((y == rec->y || y == rec->y + rec->h) || rec->op == 'R')
						can->array[y][x] = rec->c;
			} 
		}
	}
}

int		error(char *err, t_can *can)
{
	while (*err)
		write(1, err++, 1);
	if (can)
		del_can(can);
	return (1);
}

int		paint(FILE *fd)
{
	t_can	can;
	t_rec	rec;
	int		ret;

	if (fscanf(fd, "%d %d %c\n", &can.w, &can.h, &can.bg) != 3 || !can_ok(&can))
		return (error("Error: Operation file corrupted\n", NULL));
	new_can(&can);
	while ((ret = fscanf(fd, "%c %f %f %f %f %c\n",
		&rec.op, &rec.x, &rec.y, &rec.w, &rec.h, &rec.c)) == 6)
	{
		if (!rec_ok(&rec))	
			return (error("Error: Operation file corrupted\n", &can));
		mod_rec(&rec);
		put_rec(&can, &rec);
	}
	if (ret > -1 && ret < 6)
		return (error("Error: Operation file corrupted\n", &can));
	print_can(&can);
	del_can(&can);
	return (0);
}

int		main(int ac, char **av)
{
	FILE	*fd;
	int		ret;

	if (ac != 2)
		return (error("Error: argument", NULL));
	if (!(fd = fopen(av[1], "r")))
		return (error("Error: Operation file corrupted\n", NULL));
	ret = paint(fd);
	fclose(fd);
	return (ret);
}
