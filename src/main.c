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

int		main(int argc,char **argv)
{
	t_m  m;

	m.p = 0;
	m.map = NULL;

	to_file(&m, argv[1]);
	return(0);
}