/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:04:11 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/02 17:04:14 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	unsigned char	*join;

	if (s1 != NULL && s2 != NULL)
	{
		join = (unsigned char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!join)
			return (NULL);
		i = -1;
		j = 0;
		while (s1[++i] != '\0')
			join[i] = s1[i];
		while (s2[j] != '\0')
			join[i++] = s2[j++];
		join[i] = '\0';
		return ((char *)join);
	}
	return (NULL);
}
