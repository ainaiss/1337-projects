/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:59:40 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/13 03:54:41 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t slen;
	size_t dlen;
	size_t i;
	size_t j;

	slen = ft_strlen(src);
	if (!dst && size == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (size + slen);
	else
	{
		i = dlen;
		j = 0;
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (slen + dlen);
	}
}
