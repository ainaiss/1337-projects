/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:21:17 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/13 14:48:59 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_restoftex(int dir, t_mlx *mlx)
{
	if (dir == 4)
	{
		if (mlx->tex4_done)
			ft_put_error("EAST Texture set more than once\n", mlx);
		else
			mlx->tex4_done = 1;
	}
	else if (dir == 5)
	{
		if (mlx->spr_done)
			ft_put_error("SPRITE Texture set more than once\n", mlx);
		else
			mlx->spr_done = 1;
	}
}

void	ft_checkmap_end(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx->max_x)
	{
		y = 0;
		while (y < mlx->max_y)
		{
			if (mlx->worldmap[x][y] != '1'
					&& mlx->worldmap[x][y] != '7' && mlx->worldmap[x][y] != ' ')
				checkmap(mlx, x, y);
			y++;
		}
		x++;
	}
}
