/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:49:37 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/13 14:49:42 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sprite_width(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->spritewidth = abs((int)(mlx->win.heigth / (sprite->transformy)));
	sprite->drawstartx = -sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= mlx->win.width)
		sprite->drawendx = mlx->win.width;
}

void	ft_sprite_height(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->spriteheight = abs((int)(mlx->win.heigth / (sprite->transformy)));
	sprite->drawstarty = -sprite->spriteheight / 2 + mlx->win.heigth / 2;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = sprite->spriteheight / 2 + mlx->win.heigth / 2;
	if (sprite->drawendy >= mlx->win.heigth)
		sprite->drawendy = mlx->win.heigth;
}
