/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:02:09 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/02 17:02:11 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*ssrc;

	dest = (char *)dst;
	ssrc = (char *)src;
	if (src == dst)
		return (dst);
	if (!dest && !ssrc)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = ssrc[i];
		i++;
	}
	return (dst);
}