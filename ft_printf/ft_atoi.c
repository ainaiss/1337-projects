/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:47:38 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:47:44 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char *str)
{
	int			a;
	long int	result;
	long int	prev;

	a = 1;
	result = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			a = -1;
	while (*str && *str >= '0' && *str <= '9')
	{
		prev = result;
		result = result * 10 + a * (*str - '0');
		if (a == 1 && prev > result)
			return (-1);
		else if (a == -1 && prev < result)
			return (0);
		str++;
	}
	return (result);
}
