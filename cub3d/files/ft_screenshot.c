/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:34:24 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/02 14:34:24 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_screenshot	*ft_init_shot(t_mlx *mlx)
{
	t_screenshot	*takeshot;

	takeshot = malloc(1 * sizeof(t_screenshot));
	takeshot->width = mlx->win.width;
	takeshot->height = mlx->win.heigth;
	takeshot->bitcount = 24;
	takeshot->blue = 255;
	takeshot->green = 0;
	takeshot->red = 0;
	takeshot->width_in_bytes = ((takeshot->width
				* takeshot->bitcount + 31) / 32) * 4;
	takeshot->imagesize = takeshot->width_in_bytes * takeshot->height;
	takeshot->buf = malloc(takeshot->imagesize);
	return (takeshot);
}

void	ft_screen_shot(t_mlx *mlx)
{
	ft_update(mlx, YES);
	mlx->shot = ft_init_shot(mlx);
	ft_printf("[Taking ScreenShoot....]\n");
	ft_screno(mlx);
	ft_printf("ScreenShot Has been saved under The name 'screenshot.bmp'.\n");
	close_game(mlx);
}

void	ft_fill_image(t_mlx *mlx, unsigned char *buf)
{
	int	col;
	int	row;

	col = 0;
	while (col < mlx->shot->width)
	{
		row = 0;
		while (row < mlx->shot->height)
		{
			mlx->shot->red = (mlx->tex.img_data[(mlx->shot->height - row)
					*mlx->win.width + col] >> 16);
			mlx->shot->green = (mlx->tex.img_data[(mlx->shot->height - row)
					*mlx->win.width + col] >> 8);
			mlx->shot->blue = mlx->tex.img_data[(mlx->shot->height - row)
				*mlx->win.width + col];
			buf[(row * mlx->win.width + col)*3 + 0] = mlx->shot->blue;
			buf[(row * mlx->win.width + col)*3 + 1] = mlx->shot->green;
			buf[(row * mlx->win.width + col)*3 + 2] = mlx->shot->red;
			row++;
		}
		col++;
	}
}

unsigned char	*bmp_header(int filesize)
{
	unsigned char	*bmpfileheader;

	bmpfileheader = (unsigned char *)malloc(14);
	ft_memset(bmpfileheader, 0, 14);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[10] = (unsigned char)(54);
	return (bmpfileheader);
}

unsigned char	*bmp_info(t_mlx *mlx)
{
	unsigned char	*bmpinfoheader;

	bmpinfoheader = (unsigned char *)malloc(40);
	ft_memset(bmpinfoheader, 0, 40);
	bmpinfoheader[0] = (unsigned char)(40);
	bmpinfoheader[4] = (unsigned char)(mlx->shot->width);
	bmpinfoheader[5] = (unsigned char)(mlx->shot->width >> 8);
	bmpinfoheader[6] = (unsigned char)(mlx->shot->width >> 16);
	bmpinfoheader[7] = (unsigned char)(mlx->shot->width >> 24);
	bmpinfoheader[8] = (unsigned char)(mlx->shot->height);
	bmpinfoheader[9] = (unsigned char)(mlx->shot->height >> 8);
	bmpinfoheader[10] = (unsigned char)(mlx->shot->height >> 16);
	bmpinfoheader[11] = (unsigned char)(mlx->shot->height >> 24);
	bmpinfoheader[12] = (unsigned char)(1);
	bmpinfoheader[14] = (unsigned char)(24);
	return (bmpinfoheader);
}
