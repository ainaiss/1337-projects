/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:18:16 by fel-boua          #+#    #+#             */
/*   Updated: 2019/11/05 13:21:42 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cw(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	cc(const char *s, char c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	if (!s || !(str = (char **)malloc(sizeof(char *) * (cw(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < cw(s, c))
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (cc(s + k, c) + 1))))
			return (NULL);
		j = 0;
		while (s[k] == c && s[k])
			k++;
		while (s[k] != c && s[k])
			str[i][j++] = s[k++];
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}
