/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:02:11 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/03 18:02:53 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <stdio.h>

static int	g_pause = 0;

void	loop_sender(char *msg, int pid)
{
	int		j;
	int		i;

	i = -1;
	while (msg[++i])
	{
		j = 0;
		while (j < 8)
		{
			usleep(50);
			g_pause = 0;
			if ((msg[i] >> j) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit_error("Server not found.\n");
			}
			else
				if (kill(pid, SIGUSR1) == -1)
					exit_error("Server not found.\n");
			while (!g_pause)
				;
			j++;
		}
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR2)
		g_pause = 1;
	return ;
}

int	main(int ac, char **av)
{
	int			pid;
	int			j;

	if (ac != 3)
		exit_error("Wrong number of arguments.\n");
	pid = ft_atoi(av[1]);
	signal(SIGUSR2, handler);
	loop_sender(av[2], pid);
	j = 0;
	while (j < 8)
	{
		g_pause = 0;
		usleep(50);
		kill(pid, SIGUSR1);
		while (!g_pause)
			;
		j++;
	}
	return (0);
}
