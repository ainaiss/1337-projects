/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:19 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 14:53:39 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_addespace(int size, char c, t_print *val)
{
	if (size > 0)
	{
		while (size)
		{
			ft_putchar(c, val);
			size--;
		}
	}
}

void	ft_rest(int espace, char type, int value, t_print *val)
{
	int			size;

	size = ft_strlen(ft_itoa(value));
	if (val->type == 'u')
	{
		if (value < 0)
			size = 10;
		ft_addespace(espace - size, type, val);
		if (value == 0 && val->point == 6)
			ft_putchar(' ', val);
		else
			ft_putunsignednbr(value, val);
	}
	if (espace < 0)
		ft_addespace((-espace) - size, ' ', val);
}

int	ft_getflag(int i, const char *s)
{
	if (*(s + i) == 'c' || *(s + i) == 's' || *(s + i) == 'd'
		|| *(s + i) == 'i' || *(s + i) == 'u' || *(s + i) == 'x'
		|| *(s + i) == 'X' || *(s + i) == 'p')
		return (1);
	return (0);
}

void	check_1(t_print *val, t_args ret, va_list arg)
{
	if (val->type == 'c')
		ret.number = va_arg(arg, int);
	else if (val->type == 's')
		ret.string = va_arg(arg, char *);
	else if (val->type == 'd' || val->type == 'i' || val->type == 'u')
		ret.number = va_arg(arg, int);
	else if (val->type == 'x' || val->type == 'X')
		ret.string = ft_decimaltohex(va_arg(arg, int), val->type);
	else if (val->type == 'p')
		ret.string = ft_decimaltohex((unsigned long)va_arg(arg, void *),
				val->type);
	else if (val->type == '%')
		ret.number = '%';
}

t_args	ft_arg(va_list arg, t_print *val)
{
	t_args	ret;

	ft_initialized(&ret);
	ret.int_str = CHAR;
	check_1(val, ret, arg);
	if (val->type == 's' || val->type == 'x'
		|| val->type == 'X' || val->type == 'p')
		ret.int_str = STRING;
	else if (val->type == 'd' || val->type == 'i' || val->type == 'u')
		ret.int_str = NUMBER;
	if (ret.int_str == STRING)
		ret.number = 1;
	if (ret.int_str == NUMBER)
		ret.string = "NO";
	return (ret);
}
