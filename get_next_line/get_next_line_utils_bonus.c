/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:56:38 by fel-boua          #+#    #+#             */
/*   Updated: 2020/01/01 20:43:53 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	if (c == '\0')
		return ((char*)str);
	return (0);
}

char		*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*s;

	len = ft_strlen(s1);
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(s = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s[j++] = s2[i++];
	}
	s[j] = '\0';
	return (s);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || !(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
