/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:02:30 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 14:10:41 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (ft_memcmp(dst, src, len) == 0)
		return (dst);
	else if (dst > src)
	{
		while (len--)
		{
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
