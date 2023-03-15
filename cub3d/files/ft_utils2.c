/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:42:07 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 11:35:52 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	fillit(char **lines, char **tmp)
{
	int	j;

	j = 0;
	if (tmp)
	{
		while (tmp[j])
		{
			lines[j] = tmp[j];
			j++;
		}
	}
	return (j);
}

char	**get_filelines(char **lines, char **tmp, int fd)
{
	char	*s;
	int		i;
	int		j;
	int		ret;

	ret = 1;
	i = 1;
	while (ret)
	{
		ret = get_next_line(fd, &s);
		tmp = lines;
		j = 0;
		lines = malloc((i + 1) * sizeof(char *));
		j = fillit(lines, tmp);
		free(tmp);
		lines[j++] = s;
		lines[j] = 0;
		i++;
	}
	printf("Done\n");
	return (lines);
}
