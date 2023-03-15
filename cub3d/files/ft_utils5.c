/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:22:22 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/16 14:03:42 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_writeinfile(t_mlx *mlx, int fd, int pad)
{
	int	i;
	int	abrv;

	i = -1;
	while (++i < mlx->shot->height)
	{
		abrv = i * mlx->shot->width * 3;
		write(fd, mlx->shot->buf + abrv, mlx->shot->width * 3);
		write(fd, mlx->shot->bmppad, pad);
	}
}

void	ft_screno(t_mlx *mlx)
{
	int	fd;
	int	pad;

	pad = (4 - (mlx->shot->width * 3) % 4) % 4;
	fd = open("save.bmp", O_WRONLY | O_CREAT, 0666);
	mlx->shot->bmpfileheader = (unsigned char *)malloc(14);
	mlx->shot->bmpinfoheader = (unsigned char *)malloc(40);
	mlx->shot->bmppad = (unsigned char *)malloc(3);
	ft_memset(mlx->shot->bmppad, 0, 3);
	mlx->shot->filesize = 54 + mlx->shot->width * mlx->shot->height * 3;
	mlx->shot->bmpfileheader = bmp_header(mlx->shot->filesize);
	mlx->shot->bmpinfoheader = bmp_info(mlx);
	ft_fill_image(mlx, mlx->shot->buf);
	write(fd, mlx->shot->bmpfileheader, 14);
	write(fd, mlx->shot->bmpinfoheader, 40);
	ft_writeinfile(mlx, fd, pad);
	close(fd);
	free(mlx->shot->buf);
}
