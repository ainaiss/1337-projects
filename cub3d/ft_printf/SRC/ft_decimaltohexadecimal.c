/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimaltohexadecimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:06:43 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 15:05:47 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	loopa(unsigned long dic, char type)
{
	int		i;
	int		rest;
	char	*hexadecimal;

	i = 0;
	hexadecimal = (char *)malloc(sizeof(char) * 17);
	while (dic != 0)
	{
		rest = (dic % 16);
		if (rest < 10)
			hexadecimal[i] = rest + 48;
		else if (type == 'X')
			hexadecimal[i] = rest + 55;
		else if (type == 'x' || type == 'p')
			hexadecimal[i] = rest + 87;
		dic = dic / 16;
		i++;
	}
}

char	*ft_decimaltohex(unsigned long dic, char type)
{
	char	*hexadecimal;
	int		i;

	i = 0;
	hexadecimal = (char *)malloc(sizeof(char) * 17);
	if (dic == 0)
		hexadecimal[i++] = '0';
	else
		loopa(dic, type);
	hexadecimal[i] = '\0';
	if (hexadecimal[8] == (type == 'X' || type == 'x'))
		hexadecimal[8] = '\0';
	ft_strrev(hexadecimal);
	return (hexadecimal);
}

char	*ft_pointer(void *p, t_print *val)
{
	unsigned long	hex;

	hex = (unsigned long)p;
	ft_putstr("0x", val);
	return (ft_decimaltohex(hex, 'p'));
}

void	ft_print_hex(const char *s, unsigned int dic, t_print *val)
{
	char	*ptr;

	ptr = (char *)s;
	if (val->type == 'x')
		ptr = ft_decimaltohex(dic, 'x');
	else if (val->type == 'X')
		ptr = ft_decimaltohex(dic, 'X');
	ft_putstr(ptr, val);
	free(ptr);
}
