/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:44:56 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/13 14:47:09 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**parse_parameters(t_mlx *mlx, char **lines)
{
	int	i;
	int	j;
	int	map;

	i = 0;
	map = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		if (!choose_param(lines[i][j], lines[i], mlx))
		{
			return (&lines[i]);
		}
		i++;
	}
	ft_put_error("NO MAP FOUND\n", mlx);
	return (lines);
}

int	ft_count_sprotes(t_mlx *mlx)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < mlx->max_x)
	{
		j = 0;
		while (j < mlx->max_y)
		{
			if (mlx->worldmap[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
