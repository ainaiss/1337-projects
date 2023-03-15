/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:29:48 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/13 15:14:59 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
void	ft_lablab(t_sprtools *sprite, t_mlx *mlx)
{
	while (sprite->y < sprite->drawendy)
	{
		sprite->d = (sprite->y) * 256 - mlx->win.heigth * 128
			+ sprite->spriteheight * 128;
		sprite->tex_y = ((sprite->d * mlx->tex.sp_h)
				/ sprite->spriteheight) / 256;
		if (*(mlx->tex.sp_data + sprite->tex_x + sprite->tex_y
				* mlx->tex.sp_sl / 4))
			*(mlx->tex.img_data + sprite->x + sprite->y
					*mlx->tex.size_line / 4) = *(mlx->tex.sp_data
					+ sprite->tex_x + sprite->tex_y
					* mlx->tex.sp_sl / 4);
		sprite->y++;
	}
}

void	ft_drawspritelines(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->x = sprite->drawstartx;
	while (sprite->x < sprite->drawendx)
	{
		sprite->tex_x = (int)((sprite->x - (-sprite->spritewidth / 2
						+ sprite->spritescreenx))
				* mlx->tex.sp_w / sprite->spritewidth);
		sprite->y = sprite->drawstarty;
		if (sprite->transformy > 0 && sprite->x >= 0
			&& sprite->x < mlx->win.width && sprite->transformy
			< (float)mlx->zbuffer[sprite->x])
			ft_lablab(sprite, mlx);
		sprite->x++;
	}
}
