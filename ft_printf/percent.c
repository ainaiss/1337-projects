/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:53:45 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:53:47 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_perc(va_list *lst, t_data s, int *cpt)
{
	char ch;

	s.min = (s.min == -1) ? va_arg(*lst, int) : s.min;
	s.max = (s.max == -1) ? va_arg(*lst, int) : s.max;
	if (s.min <= 0 || s.flag == 1)
	{
		s.min = (s.min < 0) ? -s.min : s.min;
		ft_putchar('%');
		(*cpt)++;
		s.min--;
		while (s.min-- > 0 && (*cpt)++)
			ft_putchar(' ');
	}
	else
	{
		ch = '0';
		if (s.flag == 0)
			ch = ' ';
		s.min--;
		while (s.min-- > 0 && (*cpt)++)
			ft_putchar(ch);
		ft_putchar('%');
		(*cpt)++;
	}
}
