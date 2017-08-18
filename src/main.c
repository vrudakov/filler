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


void	piece_tofile(t_m *m)
{
	FILE*  fd;
	fd = fopen("curent.txt", "w");
	for (int i = 0; i < m->size_y; i++) {
		for (int j = 0; j < m->size_x; j++) {
			fprintf(fd, "%4d", m->i_map[i][j]);
		}
		fprintf(fd,"\n");
	}
	fclose(fd);
}

int 	calc_sum(t_m *m, int ix, int iy)
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
		sum += m->i_map[y + iy][x + ix];
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
		new = calc_sum(m, x, y);
//		printf("Summ---> %d\n", new);

		if (new <= m->sum && m->p == 1)
		{
			m->sum = new;
			m->pos.x = x;
			m->pos.y = y;
//			printf("\n");
//			printf("\n");
//			for (int i = 0; i < m->size_y; i++) {
//					for (int j = 0; j < m->size_x; j++) {
//						printf(" %3d ", m->i_map[i][j]);
//
//					}
//					printf("\n");
//				}

			FILE*  fd;
			fd = fopen("curent.txt", "a");
			fprintf(fd,"%d y - %d x - %d\n", new, y , x);
			fclose(fd);

		}

		if (new < m->sum && m->p == 2)
		{
			m->sum = new;
			m->pos.x = x;
			m->pos.y = y;

			FILE*  fd;
			fd = fopen("curent.txt", "a");
			fprintf(fd,"%d y - %d x - %d\n", new, y , x);
			fclose(fd);

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
//	piece_tofile(m);
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

	FILE*  fd;
	fd = fopen("curent.txt", "a");
	fprintf(fd,"best pos - x-%d y-%d \n", m->pos.y , m->pos.x);
	fclose(fd);

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
		m->sum = 1000000;
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
	to_file(&m, argv[1]);
	return(0);
}
//TODO  Найти свою букву
//TODO  Поставить фигуру чтоб 1 звездочка была на букве.