/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:34:20 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/02 14:34:20 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_readmap(char *fname, t_mlx *mlx)
{
	int		fd;
	char	**tmp;
	char	**firstmap;

	fd = open(fname, O_RDONLY);
	tmp = NULL;
	if (fd < 0)
		ft_put_error("map file not found\n", mlx);
	mlx->lines = 0;
	mlx->lines = get_filelines(mlx->lines, tmp, fd);
	close(fd);
	init_params(mlx);
	firstmap = parse_parameters(mlx, mlx->lines);
	verify_params(mlx);
	mlx->max_x = countx(firstmap, mlx);
	mlx->max_y = county(firstmap);
	init_map(mlx);
	make_map(firstmap, mlx);
	check_player(mlx);
	ft_checkmap_end(mlx);
	mlx->sp = ft_get_sprite(mlx);
	mlx->win.win_ptr = mlx_new_window(mlx->win.mlx_ptr,
			mlx->win.width, mlx->win.heigth, "fel-boua Cub3D");
}
