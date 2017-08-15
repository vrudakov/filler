/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:43:26 by vrudakov          #+#    #+#             */
/*   Updated: 2017/08/03 21:43:29 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/filler.h"
#include "../libft/libft.h"

// * - 42
// . - 46
// O - 79
// X - 88

int		try_incert(t_m *m, int x, int y)
{
	/*
	if ((m->map[y][x] != 'O' && m->p == 1) || (m->map[y][x] != 'X' && m->p == 2))
		return (0);
	if (m->pic->coords[0].x > x || m->pic->coords[0].y > y)
		return (0);
//	if ()
	 */
	int	xn;
	int	yn;
	int t;
    t_coord     c;

	yn = 0;
	t = 0;
	while (yn < m->p_size_y)
	{
		xn = 0;
		while (xn < m->p_size_x)
		{
			if (m->map[y + yn][x + xn] == m->enmy)
				return (0);
			if (m->map[y + yn][x + xn] == m->iam && m->piece[yn][xn] == '*')
                t++;
			if (t > 1)
				return (0);
			xn++;
		}
		yn++;
	}
	if (t == 1)
	{
		printf(">>>%d %d<<<", x ,y);
		return(1);
	}
	return (0);
}



void	ft_think(t_m *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < m->size_y - m->p_size_y)
	{
		if (try_incert(m, x, y))
			return ;
		x++;
		if (x == m->size_x - m->p_size_x)
		{
			y++;
			x = 0;
		}
	}
}

int		count_ast(t_m *m, int ind)
{
	int x;
	int y;
	int ast;

	ast = 0;
	x = 0;
	y = 0;
	while (y < m->p_size_y)
	{
		if (m->piece[y][x] == '*')
		{
			if (ind == 1)
			{
				m->pic->coords[ast].x = x;
				m->pic->coords[ast].y = y;
			}
			ast++;
		}
		x++;
		if (x == m->p_size_x + 1)
		{
			y++;
			x = 0;
		}
	}
	return (ast);
}

void	take_piece_info(t_m *m)
{
	m->pic = malloc(sizeof(t_piece));
	m->pic->ast = count_ast(m, 0);
	m->pic->coords = malloc(sizeof(t_coord) * m->pic->ast);
	count_ast(m, 1);

}

void ft_read(t_m *m, char *line)
{
	while (get_next_line(FD, &line) > 0)
	{
		if (m->map == NULL)
		{
			if (ft_strstr(line, "$$$"))
			{
				m->p = line[10] - 48;
				if (m->p == 2)
				{
					m->iam = 'X';
					m->enmy = 'O';
				}
			}
			if (ft_strstr(line, "Plat"))
				ind_map_size(m, line);
		}
		if (ft_strstr(line, "Plat"))
			fill_map(m, line);
		if (ft_strstr(line, "Pie"))
		{
			ind_piece_size(m, line);
			fill_piece(m, line);
		}
	}
}

void	to_file(t_m *m, char *str)
{
	char *line;
	int fd;

	fd = open("in.txt", O_RDONLY);

	line = "\0";

	m->f = fopen("file.txt", "w");

	while (get_next_line(FD, &line) > 0)
	{
		ft_read(m, line);
		take_piece_info(m);

		ft_think(m);

		fprintf(m->f, "%s\n", line);


//		write(1, "8 2\n", 4);
	}
	fclose(m->f);
}

int		main(int argc,char **argv)
{
	t_m  m;

	m.p = 0;
	m.map = NULL;
	m.iam = 'O';
	m.enmy = 'X';
	to_file(&m, argv[1]);
	return(0);
}
//TODO  Найти свою букву
//TODO  Поставить фигуру чтоб 1 звездочка была на букве.