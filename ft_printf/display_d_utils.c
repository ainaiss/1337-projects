/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:50:17 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:50:20 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affiche1_d(int min, int max, char *s, int *cpt)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (ft_atoi(s) < 0 && (*cpt)++ && len--)
	{
		ft_putchar(*(s++));
		i++;
	}
	min = (min < 0) ? -min : min;
	max = (max < 0) ? len : max;
	if (max != 0 || ft_atoi(s) != 0)
	{
		while (max > len++ && (*cpt)++)
		{
			ft_putchar('0');
			i++;
		}
		while (*s && (*cpt)++ && i++ >= 0)
			ft_putchar(*(s++));
	}
	while (i++ < min && (*cpt)++)
		ft_putchar(' ');
}

void	affiche2_d(int min, char *s, int *cpt)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (min < 0)
		min *= -1;
	while (*s && (*cpt)++)
	{
		ft_putchar(*(s++));
		i++;
	}
	while (i < min && (*cpt)++)
	{
		ft_putchar(' ');
		i++;
	}
}

void	affiche3_d(int min, int max, char *s, int *cpt)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (min < 0 || (max == 0 && ft_atoi(s) == 0))
		return (affiche1_d(min, max, s, cpt));
	max = (max >= len && ft_atoi(s) < 0) ? max + 1 : max;
	max = (max < len) ? len : max;
	while (i < min - max && (*cpt)++)
	{
		ft_putchar(' ');
		i++;
	}
	if (ft_atoi(s) < 0 && (*cpt)++)
		ft_putchar(*(s++));
	i = 0;
	while (i++ < max - len && (*cpt)++)
		ft_putchar('0');
	while (*s && (*cpt)++)
		ft_putchar(*(s++));
}

void	affiche4sub_d(int min, char *s, int len, int *cpt)
{
	int i;

	i = 0;
	while (i < min - len && (*cpt)++)
	{
		ft_putchar(' ');
		i++;
	}
	while (*s && (*cpt)++)
	{
		ft_putchar(*s);
		s++;
	}
}

void	affiche4_d(int min, char *s, int n, int *cpt)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (n == 0 && min >= 0)
		return (affiche4sub_d(min, s, len, cpt));
	if (n == 0 && min < 0)
	{
		while (*s && (*cpt)++)
		{
			ft_putchar(*(s++));
			i++;
		}
		while (i++ < -min && (*cpt)++)
			ft_putchar(' ');
		return ;
	}
	if (n != 0 && min < 0)
		return (affiche1_d(min, 0, s, cpt));
	affiche3_d(min, 0, s, cpt);
}
