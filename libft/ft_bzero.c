/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:28:08 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/13 03:53:13 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	if (n == 0)
		return ;
	ptr = (unsigned char*)s;
	while (n--)
	{
		*ptr = '\0';
		if (n)
			ptr++;
	}
}
