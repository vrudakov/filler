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
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
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

void	calc_cell(t_m *m)
{
	int x;
	int y;
	int i;

	i = 1;
	y = 1;
	while (1)
	{
		while (y < (m->size_y - 1))
		{
			x = 1;
			while (x < (m->size_x - 1))
			{
				if (m->i_map[y][x] == i)
				{
					reload(m, x, y);
				}
				x++;
			}
			y++;
		}
		i++;
		y = 1;
		if (find_zero(m))
			return ;
	}
}
