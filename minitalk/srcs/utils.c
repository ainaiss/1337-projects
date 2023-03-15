/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:02:38 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/03 18:02:57 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	exit_error(char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_putstr_fd(char *msg, int fd)
{
	int	i;

	i = 0;
	while (msg[i])
		write(fd, &msg[i++], 1);
}

int	ft_atoi(const char *str)
{
	int		res;
	int		neg;
	int		i;

	res = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	c;

	i = n;
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
	if (i >= 10)
	{
		ft_putnbr_fd((i / 10), fd);
		c = (i % 10 + '0');
		write(1, &c, 1);
	}
	else
	{
		c = (i + '0');
		write(1, &c, 1);
	}
}
