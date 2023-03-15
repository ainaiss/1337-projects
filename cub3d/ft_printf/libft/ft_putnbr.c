/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:03:05 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/13 11:51:42 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long n, t_print *val)
{
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		ft_putchar('-', val);
		a = -n;
	}
	if (a > 9)
	{
		ft_putnbr((a / 10), val);
		ft_putchar((a % 10) + '0', val);
	}
	else
		ft_putchar(a + '0', val);
}
