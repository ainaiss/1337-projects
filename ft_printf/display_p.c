/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:46:06 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:46:22 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numberofdigits_p(unsigned long n)
{
	int i;

	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}

char	*convertetohex_p(unsigned long dec)
{
	int		i;
	char	*hex;

	i = numberofdigits_p(dec);
	hex = malloc(sizeof(char) * (i + 1));
	hex[i] = '\0';
	while (i > 0)
	{
		hex[i - 1] = (dec % 16 < 10 ? dec % 16 + '0' : 'a' + ((dec % 16) - 10));
		dec = dec / 16;
		i--;
	}
	return (hex);
}

void	affiche_p_sub(t_data s, char *st, int *cpt)
{
	if (s.prec == 1)
	{
		if (s.flag == -1)
		{
			if (s.min <= 0)
				return (affiche1_p(-s.min, s.max, st, cpt));
			else
			{
				if (s.max >= 0)
					return (affiche3_p(s.min, s.max, st, cpt));
				return (affiche3_p(s.min, s.min, st, cpt));
			}
		}
		return (affiche3_p(s.min, s.max, st, cpt));
	}
	else if (s.flag == -1)
	{
		if (s.min > 0)
			return (affiche1_p(0, s.min, st, cpt));
		return (affiche1_p(-s.min, 1, st, cpt));
	}
	else
		return (affiche4_p(s.min, st, cpt));
}

void	affiche_p(va_list *p, t_data s, int *cpt)
{
	int		i;
	char	*st;

	i = 0;
	if (s.min == -1)
		s.min = va_arg(*p, int);
	if (s.max == -1)
		s.max = va_arg(*p, int);
	st = convertetohex_p(va_arg(*p, unsigned long));
	if (s.flag == 1)
	{
		if (s.prec == 1)
			affiche1_p(s.min, s.max, st, cpt);
		else
			affiche2_p(s.min, st, cpt);
	}
	else
		affiche_p_sub(s, st, cpt);
	free(st);
}
