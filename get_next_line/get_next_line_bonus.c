/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:54:55 by fel-boua          #+#    #+#             */
/*   Updated: 2020/01/02 16:20:06 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*get_line(char *buff, char **line)
{
	char	*rest;
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	*line = ft_substr(buff, 0, i);
	if (buff[i] == '\n')
		rest = ft_strdup(buff + i + 1);
	if (buff[i] == '\0')
		rest = ft_strdup("");
	return (rest);
}

static int		last_line(char **buff, char **line)
{
	*line = *buff;
	*buff = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buff[FD_MAX];
	char			*rest;
	char			*tmp;
	int				len;

	if (fd < 0 || !line || fd > FD_MAX || !(tmp = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!buff[fd])
		buff[fd] = ft_strdup("");
	while (!ft_strchr(buff[fd], '\n') && (len = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[len] = '\0';
		rest = ft_strjoin(buff[fd], tmp);
		free(buff[fd]);
		buff[fd] = rest;
	}
	free(tmp);
	if (len < 0)
		return (-1);
	if (!len && !ft_strchr(buff[fd], '\n'))
		return (last_line(&buff[fd], line));
	rest = get_line(buff[fd], line);
	free(buff[fd]);
	buff[fd] = rest;
	return (1);
}
