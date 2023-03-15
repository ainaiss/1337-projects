/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:34:32 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/02 14:34:32 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_sprite	*ft_get_sprite(t_mlx *mlx)
{
	t_sprite	*sprites;
	int			i;
	int			x;
	int			y;

	mlx->sprite_num = ft_count_sprotes(mlx);
	sprites = malloc(mlx->sprite_num * sizeof(t_sprite));
	mlx->sprite_order = malloc(mlx->sprite_num * sizeof(int));
	i = 0;
	x = 0;
	while (x < mlx->max_x)
	{
		y = 0;
		while (y < mlx->max_y)
		{
			if (mlx->worldmap[x][y] == '2')
			{
				sprites[i].x = x;
				sprites[i++].y = y;
			}
			y++;
		}
		x++;
	}
	return (sprites);
}

void	ft_lablablab(t_mlx *mlx, double *distance)
{
	int	i;
	int	tmp;
	int	disttmp;

	i = -1;
	while (++i < mlx->sprite_num - 1)
	{
		if (distance[i] < distance[i + 1])
		{
			disttmp = distance[i];
			distance[i] = distance[i + 1];
			distance[i + 1] = disttmp;
			tmp = mlx->sprite_order[i];
			mlx->sprite_order[i] = mlx->sprite_order[i + 1];
			mlx->sprite_order[i + 1] = tmp;
			i = -1;
		}
	}
}

void	ft_sort_sprites(t_mlx *mlx)
{
	double	*distance;
	int		i;

	i = -1;
	distance = (double *)malloc(sizeof(double) * mlx->sprite_num);
	while (++i < mlx->sprite_num)
	{
		distance[i] = ((mlx->posx - mlx->sp[i].x) * (mlx->posx
					- mlx->sp[i].x) + (mlx->posy - mlx->sp[i].y) * (mlx->posy
					- mlx->sp[i].y));
		mlx->sprite_order[i] = i;
	}
	ft_lablablab(mlx, distance);
}

void	ft_drawsprites(t_mlx *mlx)
{
	int			i;
	t_sprite	sprite_ptr;
	t_sprtools	sprite;

	ft_sort_sprites(mlx);
	i = 0;
	while (i < mlx->sprite_num)
	{
		sprite_ptr = mlx->sp[mlx->sprite_order[i++]];
		sprite.spritex = (sprite_ptr.x + 0.5) - mlx->posx;
		sprite.spritey = (sprite_ptr.y + 0.5) - mlx->posy;
		sprite.invdet = 1.0 / (mlx->planex
				* mlx->diry - mlx->dirx * mlx->planey);
		sprite.transformx = sprite.invdet * (mlx->diry
				* sprite.spritex - mlx->dirx * sprite.spritey);
		sprite.transformy = sprite.invdet
			* (-mlx->planey * sprite.spritex + mlx->planex * sprite.spritey);
		sprite.spritescreenx = (int)((mlx->win.width / 2)
				* (1 + sprite.transformx / sprite.transformy));
		ft_sprite_height(&sprite, mlx);
		ft_sprite_width(&sprite, mlx);
		ft_drawspritelines(&sprite, mlx);
	}
}
