/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:45:34 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/13 03:53:15 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *s;

	if (!(s = (unsigned char*)malloc(size * count)))
		return (NULL);
	ft_bzero(s, size * count);
	return ((void*)s);
}
