/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:51:25 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:51:28 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affiche1_p(int min, int max, char *s, int *cpt)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	min = (min < 0) ? -min : min;
	max = (max < 0) ? len : max;
	if (max != 0 || *s != '0')
	{
		while (max > len++ && (*cpt)++ && i++)
			ft_putchar('0');
		write(1, "0x", 2);
		(*cpt) += 2;
		i += 2;
		while (*s && (*cpt)++)
		{
			ft_putchar(*(s++));
			i++;
		}
	}
	while (i++ < min && (*cpt)++)
		ft_putchar(' ');
}

void	affiche2_p(int min, char *s, int *cpt)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (min < 0)
		min *= -1;
	write(1, "0x", 2);
	(*cpt) += 2;
	i += 2;
	while (*s && (*cpt)++)
	{
		ft_putchar(*(s++));
		i++;
	}
	while (i++ < min && (*cpt)++)
		ft_putchar(' ');
}

void	affiche3_p(int min, int max, char *s, int *cpt)
{
	int i;
	int len;

	i = 2;
	len = ft_strlen(s);
	if (min < 0 || (max == 0 && *s == '0'))
		return (affiche1_p(min, max, s, cpt));
	max = (max < len) ? len : max;
	while (i < min - max && (*cpt)++)
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	write(1, "0x", 2);
	(*cpt) += 2;
	while (i < max - len && (*cpt)++)
	{
		ft_putchar('0');
		i++;
	}
	while (*s && (*cpt)++)
		ft_putchar(*(s++));
}

void	affiche4sub_p(int min, char *s, int len, int *cpt)
{
	int i;

	i = 2;
	while (i < min - len && (*cpt)++)
	{
		ft_putchar(' ');
		i++;
	}
	write(1, "0x", 2);
	*cpt += 2;
	while (*s && (*cpt)++)
	{
		ft_putchar(*s);
		s++;
	}
}

void	affiche4_p(int min, char *s, int *cpt)
{
	int i;
	int len;

	i = 2;
	len = ft_strlen(s);
	if (*s == '0' && min >= 0)
		return (affiche4sub_p(min, s, len, cpt));
	if (*s == 0 && min < 0)
	{
		write(1, "0x", 2);
		*cpt += 2;
		while (*s && (*cpt)++)
		{
			ft_putchar(*(s++));
			i++;
		}
		while (i++ < -min && (*cpt)++)
			ft_putchar(' ');
		return ;
	}
	if (*s != 0 && min < 0)
		return (affiche1_p(min, 0, s, cpt));
	return (affiche3_p(min, 0, s, cpt));
}
