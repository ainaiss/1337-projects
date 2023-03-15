/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:51:59 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:52:01 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affiche1_u(int min, int max, char *s, int *cpt)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (min < 0)
		min *= -1;
	if (max < 0)
		max = len;
	if (max != 0 || *s != '0')
	{
		while (max > len++ && (*cpt)++)
		{
			ft_putchar('0');
			i++;
		}
		while (*s && (*cpt)++)
		{
			ft_putchar(*(s++));
			i++;
		}
	}
	while (i++ < min && (*cpt)++)
		ft_putchar(' ');
}

void	affiche2_u(int min, char *s, int *cpt)
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
	while (i++ < min && (*cpt)++)
		ft_putchar(' ');
}

void	affiche3_u(int min, int max, char *s, int *cpt)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (min < 0 || (max == 0 && *s == '0'))
		return (affiche1_u(min, max, s, cpt));
	if (max < len)
		max = len;
	while (i < min - max && (*cpt)++)
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < max - len && (*cpt)++)
	{
		ft_putchar('0');
		i++;
	}
	while (*s && (*cpt)++)
	{
		ft_putchar(*(s));
		s++;
	}
}

void	affiche4_sub_u(int min, char *s, int len, int *cpt)
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

void	affiche4_u(int min, char *s, int *cpt)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (*s == '0' && min >= 0)
	{
		affiche4_sub_u(min, s, len, cpt);
		return ;
	}
	if (*s == '0' && min < 0)
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
	if (*s != '0' && min < 0)
		return (affiche1_u(min, 0, s, cpt));
	affiche3_u(min, 0, s, cpt);
}
