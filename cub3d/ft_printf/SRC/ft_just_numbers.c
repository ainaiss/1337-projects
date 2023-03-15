/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:59 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 15:52:25 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	plus1(va_list arg, char *s, t_print *val)
{
	int		zeros;
	int		espace;
	t_args	value;
	int		skip;

	espace = ft_atoi(s);
	value = ft_arg(arg, val);
	skip = ft_skip_number(s);
	zeros = ft_atoi(s + skip + 1);
	if (value.number < 0 && val->type != 'u')
		return (ft_double_number_neg(espace, zeros, &value, val));
	if (val->type == '%')
		return (ft_print_percent(s, espace, val));
	else if (value.number == 0 && zeros == 0)
	{
		if (espace < 0)
			espace *= -1;
		else
			espace *= 1;
		return (ft_addespace(espace, ' ', val));
	}
	else if (val->type == 's')
		return (ft_double_number_s(espace, zeros, &value, val));
}

void	ft_double_numbers(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		zeros;
	int		skip;
	t_args	value;

	espace = ft_atoi(s);
	skip = ft_skip_number(s);
	zeros = ft_atoi(s + skip + 1);
	value = ft_arg(arg, val);
	plus1(arg, s, val);
	skip = ft_value_len(&value, val);
	if (skip > zeros)
		zeros = skip;
	ft_addespace(espace - zeros, ' ', val);
	ft_double_numbers_rest((zeros - skip), &value, val);
	ft_check_espace(espace, zeros, val);
}

void	ft_double_numbers_rest(int zeros, t_args *value, t_print *val)
{
	if (val->type == '%')
		ft_addespace(zeros, ' ', val);
	else
		ft_addespace(zeros, '0', val);
	if (zeros == 0 && value->string[0] == '0' && value->string[1] == '\0')
		ft_putchar(' ', val);
	else
		ft_print_arg(value, val);
}

void	ft_double_number_neg(int espace, int zeros, t_args *value, t_print *val)
{
	int		size;

	size = ft_value_len(value, val);
	if (val->type == 'd' || val->type == 'i')
	{
		zeros++;
		if (zeros < size)
			zeros = size;
		ft_addespace(espace - zeros, ' ', val);
		ft_putchar('-', val);
		ft_addespace(zeros - size, '0', val);
		ft_putnbr(-value->number, val);
	}
	if (espace < 0)
		ft_addespace((-espace) - zeros, ' ', val);
}

void	ft_double_number_s(int espace, int zeros,
			t_args *valofarg, t_print *val)
{
	int		size;
	char	*str;

	str = valofarg->string;
	size = ft_strlen(str);
	must(espace, zeros, valofarg, val);
	if (zeros > size)
		zeros = size;
	if (espace < 0)
		ft_addespace((-espace) - zeros, val->szero, val);
}
