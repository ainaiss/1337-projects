/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:01:29 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 16:10:26 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	itoa_check(int n, char **str, int *i)
{
	if (n <= 0)
	{
		*i = 1;
		if (n == 0)
			*str[0] = '0';
		else
			*str[0] = '-';
		n = -n;
	}
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	int				int_size;

	i = 0;
	int_size = ft_intsize(n);
	str = (char *)malloc(sizeof(char) * int_size + 1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n <= 0)
		int_size += 1;
	if (!((char *)malloc(sizeof(char) * int_size + 1)))
		return (NULL);
	itoa_check(n, &str, &i);
	str[int_size] = '\0';
	while (i <= --int_size)
	{
		str[int_size] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
