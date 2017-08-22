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


int		try_incert(t_m *m, int x, int y)
{
	int	xn;
	int	yn;
	int t;
	int new;
	yn = 0;
	t = 0;
	while (yn < m->p_size_y)
	{
		xn = 0;
		while (xn < m->p_size_x)
		{
			if (m->map[y + yn][x + xn] == m->enmy && m->piece[yn][xn] != '.')
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
		new = calc_sum(m, x, y);
		if (new < m->sum)
		{
			m->sum = new;
			m->pos.x = x;
			m->pos.y = y;
		}
	}
	return (0);
}

int	ft_think(t_m *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= m->size_y - m->p_size_y)
	{
		try_incert(m, x, y);
		x++;
		if (x == m->size_x - m->p_size_x + 1)
		{
			y++;
			x = 0;
		}
	}
	if (m->sum == 1000000)
		return (1);
	ft_putnbr(m->pos.y);
	write(1, " ", 1);
	ft_putnbr(m->pos.x);
	write(1, "\n", 1);
	m->pos.y = 0;
	m->pos.x = 0;
	return (0);
}

void	read_map(t_m *m, char *line)
{
	if (m->map == NULL)
	{
		if (ft_strstr(line, "$$$"))
		{
			m->p = line[10] - 48;
			if (m->p == 2)
			{
				m->iam ='X';
				m->enmy = 'O';
			}
			get_next_line(FD, &line);
		}
		if (ft_strstr(line, "Plat"))
			ind_map_size(m, line);
	}
	if (ft_strstr(line, "Plat"))
	{
		fill_map(m, line);
		get_next_line(FD, &line);
	}
	if (ft_strstr(line, "Pie"))
	{
		ind_piece_size(m, line);
		fill_piece(m, line);
	}
}

void	to_file(t_m *m)
{
	char *line;

	line = "\0";

	while (get_next_line(FD, &line) > 0)
	{
		m->sum = 1000000;
		read_map(m, line);
		take_piece_info(m);

		if (ft_think(m))
			write(1, "0 0\n", 4);
	}
}

int		main(int argc,char **argv)
{
	t_m  m;

	m.p = 0;
	m.map = NULL;
	m.iam = 'O';
	m.enmy = 'X';
	to_file(&m);
	return(0);
}
