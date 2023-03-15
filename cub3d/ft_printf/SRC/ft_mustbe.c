/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mustbe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:55:17 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 16:06:23 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	must(int espace, int zeros, t_args *valofarg, t_print *val)
{
	char	*str;
	int		size;

	str = valofarg->string;
	size = ft_strlen(str);
	if (str == NULL)
	{
		str = "(null)";
		size = ft_strlen(str);
		if (espace < zeros)
			ft_addespace(espace - size, val->szero, val);
		ft_addespace(espace - zeros, val->szero, val);
		ft_print_string(zeros, str, val);
	}
	else if (str[0] == '\0')
		ft_addespace(espace, val->szero, val);
	else
	{
		if (size < zeros)
			zeros = size;
		ft_addespace(espace - zeros, val->szero, val);
		ft_print_string(zeros, str, val);
	}
}

void	moin(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		zeros;
	int		size;
	t_args	value;

	zeros = va_arg(arg, int);
	espace = ft_atoi(s);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	if (value.number < 0)
		return (ft_neg_number(value.number, espace, zeros, val));
	if (val->type == '%')
		return (ft_print_percent(s, espace, val));
	if (zeros == (zeros < 0))
		zeros = size;
	if (val->type == 's')
		return (ft_star_string(espace, zeros, value.string, val));
	if (zeros == size)
		ft_addespace((espace - zeros), val->szero, val);
	else
		ft_addespace((espace - zeros), ' ', val);
}
