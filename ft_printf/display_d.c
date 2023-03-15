/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:45:40 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:45:46 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affiche_d_sub(t_data s, char *st, int n, int *cpt)
{
	if (s.prec == 1)
	{
		if (s.flag == 0)
			return (affiche3_d(s.min, s.max, st, cpt));
		else if (s.flag == -1)
		{
			if (s.min <= 0)
				return (affiche1_d(-s.min, s.max, st, cpt));
			else
			{
				if (s.max >= 0)
					return (affiche3_d(s.min, s.max, st, cpt));
				return (affiche3_d(s.min, s.min - 1, st, cpt));
			}
		}
	}
	else if (s.flag == -1)
	{
		if (s.min > 0 && n >= 0)
			return (affiche1_d(0, s.min, st, cpt));
		else if (s.min > 0 && n < 0)
			return (affiche1_d(0, s.min - 1, st, cpt));
		return (affiche1_d(-s.min, 1, st, cpt));
	}
	return (affiche4_d(s.min, st, n, cpt));
}

void	affiche_d(va_list *p, t_data s, int *cpt)
{
	int		i;
	char	*st;
	int		n;

	i = 0;
	if (s.min == -1)
		s.min = va_arg(*p, int);
	if (s.max == -1)
		s.max = va_arg(*p, int);
	n = va_arg(*p, int);
	st = ft_itoa(n);
	if (s.flag == 1)
	{
		if (s.prec == 1)
			affiche1_d(s.min, s.max, st, cpt);
		else
			affiche2_d(s.min, st, cpt);
	}
	else
		affiche_d_sub(s, st, n, cpt);
	free(st);
}
