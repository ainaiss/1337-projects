/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:33:54 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/13 00:56:50 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_hand]);
	ft_print_message(FORK, philo);
	pthread_mutex_lock(&philo->data->forks[philo->right_hand]);
	ft_print_message(FORK, philo);
}

static void	msleep(size_t n)
{
	size_t	wakeuptime;

	wakeuptime = (ft_get_time() + n);
	while (wakeuptime > ft_get_time())
		usleep(100);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->eat);
	ft_print_message(EATING, philo);
	if (philo->data->eat_counter != -1)
		philo->data->current_eat++;
	philo->eating_time = ft_get_time();
	philo->next_meal = philo->eating_time
		+ (unsigned int)philo->data->time_to_die;
	msleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->left_hand]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_hand]);
	pthread_mutex_unlock(philo->eat);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_message(SLEEPING, philo);
	msleep(philo->data->time_to_sleep);
}
