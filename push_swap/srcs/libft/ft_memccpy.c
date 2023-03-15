/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:35:23 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/14 19:13:05 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dstt;
	unsigned char	*srcc;

	srcc = (unsigned char *)src;
	dstt = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dstt[i] = srcc[i];
		if (srcc[i] == (unsigned char)c)
			return (dstt + ++i);
		i++;
	}
	return (0);
}
