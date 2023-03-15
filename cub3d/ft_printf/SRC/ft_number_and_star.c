/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_and_star.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:07:15 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 15:57:54 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_number_star(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		zeros;
	int		size;
	t_args	value;

	zeros = va_arg(arg, int);
	espace = ft_atoi(s);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	moin(arg, s, val);
	if (value.number == 0 && zeros == 0)
		return ;
	ft_addespace((zeros - size), '0', val);
	ft_print_arg(&value, val);
	ft_check_espace(espace, zeros, val);
}

void	ft_check_espace(int espace, int zeros, t_print *val)
{
	if (espace < 0)
		ft_addespace(((-espace) - zeros), ' ', val);
}

void	ft_print_percent(char *s, int espace, t_print *val)
{
	if (*s == '-' && espace > 0)
		espace *= -1;
	if (espace > 0 && *s == '0')
		ft_addespace(espace - 1, '0', val);
	else if (espace < 0)
	{
		ft_putchar('%', val);
		ft_addespace((-espace) - 1, ' ', val);
		return ;
	}
	else
		ft_addespace(espace - 1, ' ', val);
	ft_putchar('%', val);
	if (espace < 0)
		ft_addespace((-espace) - 1, ' ', val);
}

void	ft_print_spercent(int espace, t_print *val)
{
	if (val->left == 2 && espace > 0)
		espace *= -1;
	if (espace > 0 && val->szero == '0')
		ft_addespace(espace - 1, '0', val);
	else if (espace < 0)
	{
		ft_putchar('%', val);
		ft_addespace((-espace) - 1, ' ', val);
		return ;
	}
	else
		ft_addespace(espace - 1, ' ', val);
	ft_putchar('%', val);
	if (espace < 0)
		ft_addespace((-espace) - 1, ' ', val);
}
