#include "includes/filler.h"

int		count_ast(t_m *m, int ind)
{
	int x;
	int y;
	int ast;

	ast = 0;
	x = 0;
	y = 0;
	while (y < m->p_size_y)
	{
		if (m->piece[y][x] == '*')
		{
			if (ind == 1)
			{
				m->pic->coords[ast].x = x;
				m->pic->coords[ast].y = y;
			}
			ast++;
		}
		x++;
		if (x == m->p_size_x + 1)
		{
			y++;
			x = 0;
		}
	}
	return (ast);
}

void	take_piece_info(t_m *m)
{
	m->pic = malloc(sizeof(t_piece));
	m->pic->ast = count_ast(m, 0);
	m->pic->coords = malloc(sizeof(t_coord) * m->pic->ast);
	count_ast(m, 1);

}
