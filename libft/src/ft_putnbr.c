/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 20:18:37 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/21 20:18:39 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(int n)
{
	long tmp;
	long num;

	tmp = n;
	if (n < 0)
	{
		tmp = -tmp;
		write(1, "-", 1);
	}
	if (tmp >= 10)
		ft_putnbr(tmp / 10);
	num = tmp % 10 + 48;
	write(1, &num, 1);
}
