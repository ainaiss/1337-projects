/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:36:48 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/02 14:36:48 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_namecheck(char *arg, char *ext)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if ((i > 4 && arg[i - 1] == ext[2] && arg[i - 2] == ext[1])
		&& (arg[i - 3] == ext[0] && arg[i - 4] == '.'))
		return (1);
	return (0);
}

int	ft_savecheck(char *arg, char *save)
{
	int	i;

	i = 0;
	while (arg[i] == save[i])
	{
		if (arg[i] == '\0' && save[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_put_error("The game is closed", mlx);
	if (key == 13)
		mlx->forward = 1;
	if (key == 1)
		mlx->backward = 1;
	if (key == 0)
		mlx->left = 1;
	if (key == 2)
		mlx->right = 1;
	if (key == 123)
		mlx->rotleft = 1;
	if (key == 124)
		mlx->rotright = 1;
	return (0);
}

int	key_released(int key, t_mlx *mlx)
{
	if (key == 13)
		mlx->forward = 0;
	if (key == 1)
		mlx->backward = 0;
	if (key == 0)
		mlx->left = 0;
	if (key == 2)
		mlx->right = 0;
	if (key == 123)
		mlx->rotleft = 0;
	if (key == 124)
		mlx->rotright = 0;
	return (0);
}

int	is_color(int c_code)
{
	if (c_code >= 0 && c_code <= 255)
		return (1);
	else
		return (0);
}
