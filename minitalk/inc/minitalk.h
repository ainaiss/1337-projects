/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:03:19 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/03 18:03:22 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

void		exit_error(char *msg);
void		ft_putstr_fd(char *msg, int fd);
int			ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif