/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:43:36 by vrudakov          #+#    #+#             */
/*   Updated: 2017/08/23 21:29:19 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define FD 0

# include "../libft/includes/libft.h"

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_piece
{
	t_coord	*coords;
	int		ast;
}				t_piece;

typedef struct	s_m
{
	int		p;
	int		size_x;
	int		size_y;
	char	**map;
	int		p_size_x;
	int		p_size_y;
	char	**piece;
	char	iam;
	char	enmy;
	int		**i_map;
	t_piece	*pic;
	int		sum;
	t_coord	pos;

}				t_m;

int				get_next_line(const int fd, char **line);

void			ind_map_size(t_m *m, char *line);
void			ind_piece_size(t_m *m, char *line);
void			fill_map(t_m *m, char *line);
void			fill_piece(t_m *m, char *line);
void			to_file(t_m *m);
int				count_ast(t_m *m, int ind);
void			take_piece_info(t_m *m);
void			renew(t_m *m, int x, int y);
int				calc_sum(t_m *m, int ix, int iy);
void			calc_cell(t_m *m);
#endif
