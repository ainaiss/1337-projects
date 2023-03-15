/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:30:37 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/02 14:30:37 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_draw(t_mlx *mlx, int x)
{
	long int	color;

	color = RGB_RED;
	mlx->wall.lineheight = (int)(mlx->win.heigth / mlx->ray.perpwalldist);
	mlx->wall.drawstart = -mlx->wall.lineheight / 2 + mlx->win.heigth / 2;
	if (mlx->wall.drawstart < 0)
		mlx->wall.drawstart = 0;
	mlx->wall.drawend = mlx->wall.lineheight / 2 + mlx->win.heigth / 2;
	if (mlx->wall.drawend >= mlx->win.heigth)
		mlx->wall.drawend = mlx->win.heigth - 1;
	ft_texture(mlx, x);
	return (0);
}

void	make_map(char **lines, t_mlx *mlx)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		last_y;

	x = 0;
	i = -1;
	last_y = 0;
	while (lines[++i])
	{
		y = 0;
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j])
				mlx->worldmap[x][y++] = lines[i][j++];
		}
		if (last_y < y)
			last_y = y;
		x++;
	}
	mlx->max_y = last_y;
}
