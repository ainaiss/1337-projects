/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:03:30 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 13:34:48 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int			count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	*word_len(char const *str, char c)
{
	char		*word;
	int			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = (char)str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	freeall(int i, char **arr)
{
	int			j;

	j = -1;
	while (j++ <= i)
		free(arr[j]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			len_w;
	char		**arr;

	if (!s)
		return (NULL);
	len_w = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (len_w + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len_w)
	{
		while (*s && *s == c)
			s++;
		arr[i] = word_len(s, c);
		if (!arr[i])
			freeall(i, arr);
		while (*s && *s != c)
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
