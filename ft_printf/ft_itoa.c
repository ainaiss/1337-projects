/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:52:45 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:52:48 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_fill_pos(char *str, int size, long long int nb)
{
	int i;

	i = size - 2;
	str[size - 1] = '\0';
	while (i >= 0)
	{
		str[i] = nb % 10 + '0';
		i--;
		nb = nb / 10;
	}
}

void				ft_fill_neg(char *str, int size, long long int nb)
{
	int i;

	i = size - 2;
	str[size - 1] = '\0';
	while (i > 0)
	{
		str[i] = nb % 10 + '0';
		i--;
		nb = nb / 10;
	}
	str[0] = '-';
}

long long int		ft_abs(long long int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

char				*ft_itoa(int n)
{
	int				range;
	long long int	nb;
	int				c;
	char			*str;

	range = 1;
	c = 0;
	nb = n;
	nb = ft_abs(nb);
	while ((nb / range) >= 10)
	{
		range = range * 10;
		c++;
	}
	if (n >= 0)
		if ((str = malloc(sizeof(char) * (c + 2))) == 0)
			return (0);
		else
			ft_fill_pos(str, c + 2, nb);
	else if ((str = malloc(sizeof(char) * (c + 3))) == 0)
		return (0);
	else
		ft_fill_neg(str, c + 3, nb);
	return (str);
}

char				*ft_itoa_u(unsigned int n)
{
	int					range;
	unsigned long int	nb;
	int					c;
	char				*str;

	range = 1;
	c = 0;
	nb = n;
	while ((nb / range) >= 10)
	{
		range = range * 10;
		c++;
	}
	if ((str = malloc(sizeof(char) * (c + 2))) == 0)
		return (0);
	else
		ft_fill_pos(str, c + 2, nb);
	return (str);
}
