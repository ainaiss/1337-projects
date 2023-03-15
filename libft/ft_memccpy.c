/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:09:14 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/13 03:55:38 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t				i;
	unsigned const char *src;
	unsigned char		*dst;

	src = (unsigned const char *)str2;
	dst = (unsigned char *)str1;
	if (!str1 && !str2)
		return (0);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (dst[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
