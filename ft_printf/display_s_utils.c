/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:51:45 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:51:47 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affiche1_s(int min, int max, char *s, int *cpt)
{
	int i;
	int len;

	if (!s)
		s = "(null)";
	i = 0;
	len = ft_strlen(s);
	min = (min < 0) ? -min : min;
	max = (max > len) ? len : max;
	max = (max < 0) ? len : max;
	if (min == 0)
		while (i < max && (*cpt)++)
		{
			ft_putchar(*(s++));
			i++;
			if (i == max)
				return ;
		}
	if (max != 0)
		while (i < max && (*cpt)++ && i++ >= 0)
			ft_putchar(*(s++));
	while (i++ < min && (*cpt)++)
		ft_putchar(' ');
}

void	affiche2_s(int min, char *s, int *cpt)
{
	int len;
	int i;

	if (!s)
		s = "(null)";
	i = 0;
	len = ft_strlen(s);
	min = (min < 0) ? -min : min;
	if (min > len)
	{
		while (*s && (*cpt)++)
		{
			ft_putchar(*s);
			s++;
			i++;
		}
		while (i++ < min && (*cpt)++)
			ft_putchar(' ');
	}
	else
		while (*s && (*cpt)++)
		{
			ft_putchar(*s);
			s++;
		}
}

void	affiche3_s(t_data t, char *s, int *cpt, char c)
{
	int i;
	int len;

	if (!s)
		s = "(null)";
	i = 0;
	len = ft_strlen(s);
	if (t.min < 0 || t.min == 0)
		return (affiche1_s(t.min, t.max, s, cpt));
	t.max = (t.max < 0) ? len : t.max;
	t.max = (t.max > len) ? len : t.max;
	if (t.max != 0)
	{
		while (i++ < t.min - t.max && (*cpt)++)
			ft_putchar(c);
		i = 0;
		while (i++ < t.max && (*cpt)++)
		{
			ft_putchar(*s);
			s++;
		}
	}
	else
		while (i++ < t.min && (*cpt)++)
			ft_putchar(' ');
}

void	affiche4_s(int min, char *s, int *cpt, char c)
{
	int i;
	int len;

	if (!s)
		s = "(null)";
	i = 0;
	len = ft_strlen(s);
	if (min < 0)
	{
		affiche2_s(min, s, cpt);
		return ;
	}
	if (min > len)
	{
		while (i++ < min - len && (*cpt)++)
			ft_putchar(c);
		while (*s && (*cpt)++)
			ft_putchar(*(s++));
	}
	else
		while (*s && (*cpt)++)
			ft_putchar(*(s++));
}
