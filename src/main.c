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
#include <sys/socket.h>

// * - 42
// . - 46
// O - 79
// X - 88

void 	reload(t_m *m, int x, int y)
{
	if (m->i_map[y - 1][x - 1] == 0)
		m->i_map[y - 1][x - 1] = m->i_map[y][x] + 1;
	if (m->i_map[y][x - 1] == 0)
		m->i_map[y][x - 1] = m->i_map[y][x] + 1;
	if (m->i_map[y + 1][x - 1] == 0)
		m->i_map[y + 1][x - 1] = m->i_map[y][x] + 1;
	if (m->i_map[y - 1][x] == 0)
		m->i_map[y - 1][x] = m->i_map[y][x] + 1;
	if (m->i_map[y + 1][x] == 0)
		m->i_map[y + 1][x] = m->i_map[y][x] + 1;
	if (m->i_map[y][x + 1] == 0)
		m->i_map[y][x + 1] = m->i_map[y][x] + 1;
	if (m->i_map[y + 1][x + 1] == 0)
		m->i_map[y + 1][x + 1] = m->i_map[y][x] + 1;
	if (m->i_map[y - 1][x + 1] == 0)
		m->i_map[y - 1][x + 1] = m->i_map[y][x] + 1;
}
int		find_zero(t_m *m)
{
	int x;
	int y;

	y = 0;
	while (y < m->size_y)
	{
		x = 0;
		while (x < m->size_x)
		{
			if (m->i_map[y][x] == 0)
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	calc_cell(t_m *m)
{
	int x;
	int y;

	y = 1;
	while (1)
	{
		while (y < (m->size_y - 1))
		{
			x = 1;
			while (x < (m->size_x - 1))
			{
				if (m->i_map[y][x] != 0)
					reload(m, x, y);
				x++;
			}
			y++;
		}
		y = 1;
		if (find_zero(m))
			return ;
	}
}

void	piece_tofile(char **p,int size)
{
	int yn;

	yn = 0;
	FILE*  fd;
	fd = fopen("curent.txt", "w");
	while (yn < size)
	{
		fprintf(fd, "%s\n", p[yn]);
		yn++;
	}
	fclose(fd);
}
int 	calc_sum(t_m *m)
{
	int	sum;
	int	i;
	int x;
	int y;

	i = 0;
	sum = 0;
	while (i < m->pic->ast)
	{
		x = m->pic->coords[i].x;
		y = m->pic->coords[i].y;
		sum += m->i_map[y][x];
		i++;
	}
	return (sum);
}

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
		new = calc_sum(m);
		if (new <= m->sum)
		{
			m->sum = new;
			m->pos.x = x;
			m->pos.y = y;
		}
	}
	/*
	if (t == 1)
	{
		ft_putnbr(y);
		write(1, " ", 1);
		ft_putnbr(x);
		write(1, "\n", 1);
		piece_tofile(m->piece, m->p_size_y);
		return(1);
	}
	 */
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
		/*if (*/try_incert(m, x, y);/*)
			return (0);*/
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
			fprintf(m->f, "%s\n", line);
		}
		if (ft_strstr(line, "Plat"))
			ind_map_size(m, line);
	}
	if (ft_strstr(line, "Plat"))
	{
		fill_map(m, line);
		get_next_line(FD, &line);
		fprintf(m->f, "%s\n", line);
	}
	if (ft_strstr(line, "Pie"))
	{
		ind_piece_size(m, line);
		fill_piece(m, line);
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
		fprintf(m->f, "%s\n", line);
		read_map(m, line);
		take_piece_info(m);

		if (ft_think(m))
			write(1, "0 0\n", 4);
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
	m.sum = 1000000;
	to_file(&m, argv[1]);
	return(0);
}
//TODO  Найти свою букву
//TODO  Поставить фигуру чтоб 1 звездочка была на букве.