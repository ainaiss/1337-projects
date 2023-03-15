/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:34:47 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/14 19:13:16 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*srcc;
	char	*dstt;

	srcc = (char *)src;
	dstt = (char *)dst;
	if (dst == src)
		return (NULL);
	i = -1;
	if (src > dst)
	{
		while (len > ++i)
			dstt[i] = srcc[i];
	}
	else
	{
		while (len)
		{
			dstt[len - 1] = srcc[len - 1];
			len--;
		}
	}
	return (dst);
}
