/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:34:15 by fel-boua          #+#    #+#             */
/*   Updated: 2021/04/02 14:34:15 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	countx(char **lines, t_mlx *mlx)
{
	int	i;
	int	j;
	int	emptyline;

	i = 0;
	emptyline = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		if (!lines[i][j])
			emptyline = 1;
		if (lines[i][j] && emptyline)
			ft_put_error("Additional Input after map\n", mlx);
		i++;
	}
	return (i);
}

int	county(char **map)
{
	int	i;
	int	j;
	int	max_y;

	i = 0;
	j = 0;
	max_y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (max_y < j)
			max_y = j;
		i++;
	}
	return (max_y);
}

void	checkmap(t_mlx *mlx, int x, int y)
{
	char	**map;

	mlx->player_pos = 0;
	map = mlx->worldmap;
	if (x == 0 || y == 0 || x == mlx->max_x)
		ft_put_error("MAP NOT CLOSED AROUND1\n", mlx);
	if (map[x][y] == '7')
		ft_put_error("MAP NOT CLOSED AROUND2\n", mlx);
	if (map[x][y - 1] == '7' || map[x][y - 1] == ' ')
		ft_put_error("MAP NOT CLOSED AROUND3\n", mlx);
	if (map[x][y + 1] == '7' || map[x][y + 1] == ' ')
		ft_put_error("MAP NOT CLOSED AROUND4\n", mlx);
	if (map[x + 1][y] == '7' || map[x + 1][y] == ' ')
		ft_put_error("MAP NOT CLOSED AROUND5\n", mlx);
	if (map[x - 1][y] == '7' || map[x - 1][y] == ' ')
		ft_put_error("MAP NOT CLOSED AROUND6\n", mlx);
}

int	close_game(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->lines)
	{
		while (mlx->lines[i])
		{
			free(mlx->lines[i]);
			i++;
		}
		free(mlx->lines);
	}
	exit(EXIT_SUCCESS);
}

void	ft_put_error(char *error, t_mlx *mlx)
{
	ft_printf("Error:\n\t%s\n", error);
	close_game(mlx);
}
