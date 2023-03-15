/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:46:37 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:46:40 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affiche_s(va_list *p, t_data s, int *cpt)
{
	int		i;
	char	*st;
	char	c;

	i = 0;
	if (s.min == -1)
		s.min = va_arg(*p, int);
	if (s.max == -1)
		s.max = va_arg(*p, int);
	st = va_arg(*p, char *);
	if (s.flag == 1)
	{
		if (s.prec == 1)
			affiche1_s(s.min, s.max, st, cpt);
		else
			affiche2_s(s.min, st, cpt);
	}
	else
	{
		c = (s.flag == -1 ? '0' : ' ');
		if (s.prec == 1)
			affiche3_s(s, st, cpt, c);
		else
			affiche4_s(s.min, st, cpt, c);
	}
}
