/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:43:36 by vrudakov          #+#    #+#             */
/*   Updated: 2017/08/03 21:43:38 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_FDF_H
# define FDF_FDF_H

# include <stdio.h>
#include "../libft/libft.h"

typedef struct  s_m
{
    int     p;
    int     size_x;
    int     size_y;
	char    **map;
	int     p_size_x;
	int     p_size_y;
	char    **piece;
}               t_m;

void  test(void);
int		get_next_line(const int fd, char **line);

#endif