/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 00:01:35 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/13 03:53:55 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *st;
	unsigned char *sr;

	st = (unsigned char *)s1;
	sr = (unsigned char *)s2;
	while (n--)
	{
		if (*st != *sr)
			return (*st - *sr);
		st++;
		sr++;
	}
	return (0);
}
