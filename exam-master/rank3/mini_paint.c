/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrfalco <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:51:23 by herrfalco         #+#    #+#             */
/*   Updated: 2019/12/09 18:04:20 by herrfalco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_can
{
	int		w;
	int		h;
	char	bg;
	char	**arr;
}				t_can;

typedef struct	s_cir
{
	char	op;
	float	x;
	float	y;
	float	r;
	char	c;
}				t_cir;

int		can_ok(t_can *can)
{
	if (can->w < 1 || can->w > 300)
		return (0);
	else if (can->h < 1 || can->h > 300)
		return (0);
	return (1);
}

int		cir_ok(t_cir *cir)
{
	if (cir->op != 'c' && cir->op != 'C')
		return (0);
	if (cir->r <= 0)
		return (0);
	return (1);
}

void	new_can(t_can *can)
{
	int		y = -1;
	int		x;

	can->arr = malloc(can->h * sizeof(char *));
	while (++y < can->h)
	{
		can->arr[y] = malloc(can->w * sizeof(char));
		x = -1;
		while (++x < can->w)
			can->arr[y][x] = can->bg;
	}
}

void	del_can(t_can *can)
{
	int		y = -1;

	while (++y < can->h)
		free(can->arr[y]);
	free(can->arr);
}

void	print_can(t_can *can)
{
	int		y = -1;
	int		x;

	while (++y < can->h)
	{
		x = -1;
		while (++x < can->w)
			write(1, &can->arr[y][x], 1);
		write(1, "\n", 1);
	}
}

void	put_cir(t_can *can, t_cir *cir)
{
	int		y = -1;
	int		x;
	float	dist;

	while (++y < can->h)
	{
		x = -1;
		while (++x < can->w)
		{
			dist = sqrtf(powf(cir->x - x, 2) + powf(cir->y - y, 2));
			if (dist <= cir->r && (cir->r - dist < 1 || cir->op == 'C'))
				can->arr[y][x] = cir->c;
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
	t_cir	cir;
	int		ret;

	if (fscanf(fd, "%d %d %c\n", &can.w, &can.h, &can.bg) != 3 || !can_ok(&can))
		return (error("Error: Operation file corrupted\n", NULL));
	new_can(&can);
	while ((ret = fscanf(fd, "%c %f %f %f %c\n", &cir.op, &cir.x, &cir.y, &cir.r, &cir.c)) == 5)
	{
		if (!cir_ok(&cir))
			return (error("Error: Operation file corrupted\n", &can));
		put_cir(&can, &cir);
	}
	if (ret > -1 && ret < 5)
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
		return (error("Error: argument\n", NULL));
	if (!(fd = fopen(av[1], "r")))
		return (error("Error: Operation file corrupted\n", NULL));
	ret = paint(fd);
	fclose(fd);
	return (ret);
}
