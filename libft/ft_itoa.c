/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:25:08 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/13 03:53:28 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len(int n)
{
	long int	a;
	int			i;

	i = 0;
	a = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n < 10)
		return (1 + i);
	while (a <= n)
	{
		a *= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		neg;
	int		res;
	int		len2;

	if (!(s = (char *)malloc(sizeof(char) * (len(n) + 1))))
		return (0);
	if ((neg = 1) && n == -2147483648)
		return (ft_strdup("-2147483648"));
	len2 = len(n);
	if (!(res = 0) && n < 0)
	{
		n *= -1;
		neg = -1;
		s[0] = '-';
	}
	s[len2] = '\0';
	while (len2--)
	{
		if (neg == -1 && len2 == 0)
			break ;
		s[len2] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
