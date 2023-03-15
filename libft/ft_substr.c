/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:47:44 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/13 03:55:05 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t n)
{
	char	*dst;
	size_t	i;
	size_t	len;

	i = 0;
	if (!src)
		return (NULL);
	if (start > ft_strlen(src))
		return (ft_strdup(""));
	len = ft_strlen(src + start);
	if (n > len)
		n = len;
	if ((dst = (char *)malloc(sizeof(char) * n + 1)) == NULL)
		return (NULL);
	ft_memcpy(dst, src + start, n);
	dst[n] = '\0';
	return (dst);
}
