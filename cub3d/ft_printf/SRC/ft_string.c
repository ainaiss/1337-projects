/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:07:51 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 13:22:07 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_print_string(int size, char *str, t_print *val)
{
	int		i;

	i = 0;
	if (size < 0)
		size = ft_strlen(str);
	if (str == NULL)
		str = "(null)";
	while (size > i && str[i] != '\0')
	{
		ft_putchar(str[i], val);
		i++;
	}
}

void	ft_star_string(int espace, int size, char *str, t_print *val)
{
	int		strlen;

	strlen = ft_strlen(str);
	if (size > strlen)
		size = strlen;
	ft_addespace((espace - size), val->szero, val);
	ft_print_string(size, str, val);
	if (espace < 0)
		ft_addespace(((-espace) - size), ' ', val);
}

void	ft_just_star(const char *s, va_list arg, t_print *val)
{
	int		espace;
	int		size;
	char	type;
	t_args	value;

	espace = va_arg(arg, int);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	type = ' ';
	if (*s == '0')
		type = '0';
	if (*s == '-')
		espace *= -1;
	if (val->type == 'p')
	{
		ft_addespace(espace - size - 2, type, val);
		ft_putstr("0x", val);
	}
	else
		ft_addespace(espace - size, type, val);
	ft_print_arg(&value, val);
	if (espace < 0)
		ft_addespace((-espace) - size, type, val);
}

void	ft_negative_number_rest(int size, int value, char type, t_print *val)
{
	unsigned int	number;

	number = value;
	if (value < 0)
		number = -value;
	if (type == '0' && size != 0)
		ft_putunsignednbr(number, val);
	else if (size != 0)
		ft_putnbr(value, val);
}
