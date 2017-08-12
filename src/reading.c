#include "../includes/filler.h"

void	ind_map_size(t_m *m, char *line)
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

void	ind_piece_size(t_m *m, char *line)
{
	char	**split;
	int		x;

	x = 0;
	split = ft_strsplit(line, ' ');
	m->p_size_x = atoi(split[1]);
	m->p_size_y = atoi(split[2]);
	m->piece = (char**)malloc(sizeof(char**) * m->p_size_y);
	while (x < m->p_size_x)
	{
		m->piece[x] = (char*)malloc(sizeof(char*) * m->p_size_x);
		x++;
	}
	m->piece[x] = NULL;
	free(split[0]);
	free(split[1]);
	free(split[2]);
}

void	fill_map(t_m *m, char *line)
{
	int c;

	c = 0;
	get_next_line(FD, &line);

//
			fprintf(m->f, "%s\n", line);
//
	while (c < m->size_y)
	{
		get_next_line(FD, &line);
		fprintf(m->f, "%s\n", line);

		m->map[c] = ft_strdup(line + 4);
		c++;
	}
}

void	fill_piece(t_m *m, char *line)
{
	int c;

	c = 0;
//	get_next_line(FD, &line);
	fprintf(m->f, "%s\n", line);

	while (c < m->p_size_y)
	{
		get_next_line(FD, &line);
		fprintf(m->f, "%s\n", line);

		m->piece[c] = ft_strdup(line);
		c++;
	}
}
