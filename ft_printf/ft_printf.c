/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:13 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 11:06:46 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*copy;

	if ((copy = malloc(sizeof(char) * (ft_strlen(s) + 1))) == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		ft_printf(const char *str, ...)
{
	va_list	lst;
	t_data	s;
	int		cpt;

	va_start(lst, str);
	cpt = 1;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			s = check_form(&str);
			ft_printf_sub(s, &lst, &cpt);
		}
		else
		{
			ft_putchar(*str);
			cpt++;
		}
		str++;
	}
	va_end(lst);
	return (--cpt);
}
