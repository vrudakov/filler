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
# define FD 3

void	ind_size(t_m *m, char *line)
{
	char	**split;
	int		x;

	x = 0;
	split = ft_strsplit(line, ' ');
	m->size_y = atoi(split[1]);
	m->size_x = atoi(split[2]);
	m->map = (char**)malloc(sizeof(char**) * m->size_y);
	while (x < m->size_x)
	{
		m->map[x] = (char*)malloc(sizeof(char*) * m->size_x);
		x++;
	}
	m->map[x] = NULL;
	free(split[0]);
	free(split[1]);
	free(split[2]);
}

void	fill_map(t_m *m, char *line)
{
	int c;

	c = 0;
	get_next_line(FD, &line);
	while (c < m->size_y)
	{
		get_next_line(FD, &line);
		m->map[c] = ft_strdup(line + 4);
		c++;
	}
}

void	to_file(t_m *m, char *str)
{
	char *line;
	int fd;

	fd = open("in.txt", O_RDONLY);

	line = "\0";
	while (get_next_line(FD, &line) > 0)
	{
		if (m->map == NULL)
		{
			if (ft_strstr(line, "$$$"))
				m->p = line[10] - 48;
			if (ft_strstr(line, "Plat"))
				ind_size(m, line);
		}
		if (ft_strstr(line, "Plat"))
			fill_map(m, line);
	}
}

int		main(int argc,char **argv)
{
	t_m  m;

	m.p = 0;
	m.map = NULL;

	to_file(&m, argv[1]);
	return(0);
}