/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:47:19 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:47:24 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numberofdigits(unsigned int n)
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

char	*convertetohex(unsigned int dec, int j)
{
	int		i;
	char	*hex;
	char	c;

	c = 'a';
	if (j == 1)
		c = 'A';
	i = numberofdigits(dec);
	hex = malloc(sizeof(char) * (i + 1));
	hex[i] = '\0';
	while (i > 0)
	{
		hex[i - 1] = (dec % 16 < 10 ? dec % 16 + '0' : c + ((dec % 16) - 10));
		dec = dec / 16;
		i--;
	}
	return (hex);
}

void	affiche_x_sub(t_data s, char *st, int *cpt)
{
	if (s.prec == 1)
	{
		if (s.flag == 0)
			affiche3_x(s.min, s.max, st, cpt);
		else if (s.flag == -1)
		{
			if (s.min <= 0)
				affiche1_x(-s.min, s.max, st, cpt);
			else
			{
				if (s.max >= 0)
					return (affiche3_x(s.min, s.max, st, cpt));
				affiche3_x(s.min, s.min, st, cpt);
			}
		}
	}
	else if (s.flag == -1)
	{
		if (s.min > 0)
			return (affiche1_x(0, s.min, st, cpt));
		affiche1_x(-s.min, 1, st, cpt);
	}
	else
		affiche4_x(s.min, st, cpt);
}

void	affiche_x(va_list *p, t_data s, int j, int *cpt)
{
	int		i;
	char	*st;

	i = 0;
	st = NULL;
	if (s.min == -1)
		s.min = va_arg(*p, int);
	if (s.max == -1)
		s.max = va_arg(*p, int);
	if (j == 2)
		st = convertetohex(va_arg(*p, unsigned int), 0);
	else if (j == 3)
		st = convertetohex(va_arg(*p, unsigned int), 1);
	if (s.flag == 1)
	{
		if (s.prec == 1)
			affiche1_x(s.min, s.max, st, cpt);
		else
			affiche2_x(s.min, st, cpt);
	}
	else
		affiche_x_sub(s, st, cpt);
	free(st);
}
