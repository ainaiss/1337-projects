/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 03:04:53 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/13 03:54:55 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char*)s1);
	if (!s1 && len == 0)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		j = 1;
		if (s1[i] == s2[0])
		{
			while (s2[j] && (i + j) < len)
			{
				if (s1[i + j] != s2[j])
					break ;
				j++;
			}
			if (s2[j] == '\0')
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
