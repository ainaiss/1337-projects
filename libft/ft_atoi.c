/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 03:03:47 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/13 03:53:11 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	res;
	int	i;

	i = 0;
	neg = 1;
	res = 0;
	while (*str && (*str == '\n' || *str == '\v' || *str == '\r' ||
				*str == '\t' || *str == '\f' || *str == ' '))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(str[i]) && ft_isdigit(str[i + 1]))
	{
		res += str[i] - '0';
		res *= 10;
		i++;
	}
	if (ft_isdigit(str[i]))
	{
		res += str[i] - '0';
	}
	return (res * neg);
}
