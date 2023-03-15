/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:18:54 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/15 16:20:58 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			l;

	str = (unsigned char*)s;
	l = 0;
	while (l < n)
	{
		if (str[l] == (unsigned char)c)
			return ((void*)&str[l]);
		l++;
	}
	return (0);
}
