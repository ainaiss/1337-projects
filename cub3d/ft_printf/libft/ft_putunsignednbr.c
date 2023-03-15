/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:03:23 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/13 17:22:57 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsignednbr(unsigned int n, t_print *val)
{
	unsigned int	size;
	unsigned int	temp;
	unsigned int	j;

	size = 1;
	temp = n;
	j = (temp /= 10);
	while (j > 0)
		size *= 10;
	temp = n;
	while (size)
	{
		ft_putchar((temp / size) + '0', val);
		temp %= size;
		size /= 10;
	}
}
