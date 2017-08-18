#include "../includes/filler.h"
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
//				for (int i = 0; i < m->size_y; i++) {
//					for (int j = 0; j < m->size_x; j++) {
//						ft_putnbr(m->i_map[i][j]);
//
//					}
//					printf("\n");
//				}
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
