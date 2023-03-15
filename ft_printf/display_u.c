/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:47:00 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:47:03 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affiche_u_sub(t_data s, char *st, int *cpt)
{
	if (s.prec == 1)
	{
		if (s.flag == 0)
			return (affiche3_u(s.min, s.max, st, cpt));
		else if (s.flag == -1)
		{
			if (s.min <= 0)
				return (affiche1_u(-s.min, s.max, st, cpt));
			else
			{
				if (s.max >= 0)
					return (affiche3_u(s.min, s.max, st, cpt));
				else
					return (affiche3_u(s.min, s.min, st, cpt));
			}
		}
	}
	else if (s.flag == -1)
	{
		if (s.min > 0)
			return (affiche1_u(0, s.min, st, cpt));
		if (s.min <= 0)
			return (affiche1_u(-s.min, 1, st, cpt));
	}
	return (affiche4_u(s.min, st, cpt));
}

void	affiche_u(va_list *p, t_data s, int *cpt)
{
	int		i;
	char	*st;

	i = 0;
	if (s.min == -1)
		s.min = va_arg(*p, int);
	if (s.max == -1)
		s.max = va_arg(*p, int);
	st = ft_itoa_u(va_arg(*p, unsigned int));
	if (s.flag == 1)
	{
		if (s.prec == 1)
			affiche1_u(s.min, s.max, st, cpt);
		else
			affiche2_u(s.min, st, cpt);
	}
	else
		affiche_u_sub(s, st, cpt);
	free(st);
}
