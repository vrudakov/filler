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

void    find_letter(t_m *m)
{
	t_coord	c;
	c.x = 0;
	c.y = 0;
	if (m->p == 1)
	{
		while (m->map[c.y][c.x] != 'O')
		{
			c.x++;
			if (c.x == m->size_x)
				c.y += 1;
		}
	}
}

void	ft_think(t_m *m)
{
	find_letter(m);
}

void ft_read(t_m *m, char *line)
{
	if (m->map == NULL)
	{
		if (ft_strstr(line, "$$$")) {
			m->p = line[10] - 48;
		}
		if (ft_strstr(line, "Plat")) {
			ind_map_size(m, line);
		}
	}
	if (ft_strstr(line, "Plat")) {
		fill_map(m, line);
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
		ft_read(m, line);
		ft_think(m);

		fprintf(m->f, "%s\n", line);


		write(1, "8 2\n", 4);
	}
	fclose(m->f);
}

int		main(int argc,char **argv)
{
	t_m  m;

	m.p = 0;
	m.map = NULL;

	to_file(&m, argv[1]);
	return(0);
}
//TODO  Найти свою букву
//TODO  Поставить фигуру чтоб 1 звездочка была на букве.