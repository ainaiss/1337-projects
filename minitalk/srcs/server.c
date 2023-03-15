/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:02:20 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/03 18:03:02 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	put_char(int new)
{
	static int				i = 0;
	static unsigned char	c = 0;

	c |= (new) << i++;
	if (i > 7)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR2)
		put_char(1);
	else if (sig == SIGUSR1)
		put_char(0);
}

void	get_pid(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR2)
		put_char(1);
	else if (sig == SIGUSR1)
		put_char(0);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	int					pid;
	struct sigaction	sigact;

	pid = getpid();
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(1, "\n", 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = get_pid;
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (42)
		pause();
	return (0);
}
