/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:07:30 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/13 12:43:23 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

int	ft_skip(char *s)
{
	int		i;

	i = 0;
	while (s[i] != 'c' && s[i] != 's' && s[i] != 'p'
		&& s[i] != 'd' && s[i] != 'i' && s[i] != 'u'
		&& s[i] != 'x' && s[i] != 'X' && s[i] != '%')
		i++;
	return (i);
}

int	ft_skip_number(char *s)
{
	int		skip;

	skip = ft_strlen(ft_itoa(ft_atoi(s)));
	if (*s == '0')
		skip++;
	return (skip);
}

void	ft_set_val(t_print *val)
{
	val->star = 0;
	val->point = 0;
	val->whith = 0;
	val->left = 0;
	val->zeros = 0;
	val->szero = ' ';
}

void	ft_flags(va_list arg, const char *s, t_print *val)
{
	ft_flags_count(s, val);
	ft_select_flag(arg, s, val);
}

void	ft_initialized(t_args *arg)
{
	arg->number = 0;
	arg->string = NULL;
	arg->int_str = 0;
}
