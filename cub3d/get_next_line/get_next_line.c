/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:08:24 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/14 16:33:30 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char **str, int n, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	*line = ft_substr(str[fd], 0, i);
	if (!str[fd][i])
	{
		temp = str[fd];
		str[fd] = NULL;
		free(temp);
		return (0);
	}
	else
	{
		temp = str[fd];
		str[fd] = ft_strdup((str[fd]) + i + 1);
		free(temp);
	}
	if (!str[fd] || !*line)
		return (-1);
	if (n || (n == 0 && str[fd] != NULL))
		return (1);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*str[4864];
	char			*temp;
	int				n;

	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0
		|| !(buf = malloc(BUFFER_SIZE + 1)) || read(fd, buf, 0) == -1
		|| (!str[fd] && !(str[fd] = ft_strdup(""))))
		return (-1);
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (!n)
			break ;
		temp = str[fd];
		buf[n] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
		if (!str[fd])
			return (-1);
		free(temp);
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
	}
	free(buf);
	return (get_line(str, n, line, fd));
}