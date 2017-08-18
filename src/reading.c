#include "../includes/filler.h"

void	ind_map_size(t_m *m, char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	m->size_y = atoi(split[1]);
	m->size_x = atoi(split[2]);
	m->map = (char**)malloc(sizeof(char*) * m->size_y + 1);
	m->i_map = (int**)malloc(sizeof(int*) * m->size_y);
	while (i < m->size_y)
	{
		m->map[i] = (char*)malloc(sizeof(char) * m->size_x + 1);
		if (!(m->i_map[i] = (int*)malloc(sizeof(int) * m->size_x)))
			printf("ALARM\n");
		i++;
	}
	m->map[i] = (char*)malloc(sizeof(char));
	m->map[i] = NULL;
	free(split[0]);
	free(split[1]);
	free(split[2]);
}

void	ind_piece_size(t_m *m, char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	m->p_size_y = atoi(split[1]);
	m->p_size_x = atoi(split[2]);
	m->piece = (char**)malloc(sizeof(char*) * m->p_size_y + 1);
	while (i < m->p_size_y)
	{
		m->piece[i] = (char*)malloc(sizeof(char) * m->p_size_x + 1);
		i++;
	}
	m->piece[i] = (char*)malloc(sizeof(char));
	m->piece[i] = NULL;
	free(split[0]);
	free(split[1]);
	free(split[2]);
}

void	fill_i_map(t_m *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < m->size_y)
	{
		if (m->map[y][x] == m->enmy)
			m->i_map[y][x] = 1;
		else
			m->i_map[y][x] = 0;
		x++;
		if (x == m->size_x + 1)
		{
			y++;
			x = 0;
		}
	}
	calc_cell(m);

//	for (int i = 0; i < m->size_y; i++) {
//		for (int j = 0; j < m->size_x; j++) {
//				ft_putnbr(m->i_map[i][j]);
//
//		}
//		printf("\n");
//	}
}

void	fill_map(t_m *m, char *line)
{
	int c;

	c = 0;
	get_next_line(FD, &line);
	fprintf(m->f, "%s\n", line);
	while (c < m->size_y)
	{
		get_next_line(FD, &line);
		fprintf(m->f, "%s\n", line);
		m->map[c] = ft_strdup(line + 4);
		c++;
	}
	fill_i_map(m);
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
	m->piece[c] = NULL;
	FILE *fn;
	fn = fopen("piece.txt", "w");
	c = 0;
	while (c < m->p_size_y)
	{

		fprintf(fn, "%s\n", m->piece[c]);
		c++;
	}
	fclose(fn);
}
