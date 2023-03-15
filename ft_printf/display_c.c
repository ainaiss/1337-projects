/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:49:47 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:49:49 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affichec(int min, char c, int flag, int *cpt)
{
	char ch;

	if (min <= 0 || flag == 1)
	{
		min = (min < 0) ? -min : min;
		ft_putchar(c);
		(*cpt)++;
		min--;
		while (min-- > 0 && (*cpt)++)
			ft_putchar(' ');
	}
	else
	{
		ch = '0';
		if (flag == 0)
			ch = ' ';
		min--;
		while (min-- && (*cpt)++)
			ft_putchar(ch);
		ft_putchar(c);
		(*cpt)++;
	}
}

void	affiche_c(va_list *p, t_data s, int *cpt)
{
	int		i;
	char	ch;

	i = 0;
	if (s.min == -1)
		s.min = va_arg(*p, int);
	if (s.max == -1)
		s.max = va_arg(*p, int);
	ch = va_arg(*p, int);
	affichec(s.min, ch, s.flag, cpt);
}
