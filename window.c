/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/09 17:52:39 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_wdw(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (0);
	// game->wdw = mlx_new_window(game->mlx, map->large * 64, map->tall * 64, "So_Long");
	game->wdw = mlx_new_window(game->mlx, 1300, 1000, "So_Long");
	if (!(game->wdw))
		return (0);
	// game->img = mlx_new_image(game->mlx, map->large * 64, map->tall * 64);
	game->img = mlx_new_image(game->mlx, 1300, 1000);
	return (1);
}

int	destroy_wdw(int key, t_game *game)
{
	if (key)
	{
		mlx_clear_window(game->mlx, game->wdw);
		mlx_destroy_window(game->mlx, game->wdw);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	return (0);
}

int	img_to_window(t_game *game, t_map *map)
{
	map->j = 0;
	while (map->matriz[map->j])
	{
		map->i = 0;
		while (map->matriz[map->j][map->i])
		{
			if (map->matriz[map->i][map->j] == '1')
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "images/1.xpm", &game->pixel, &game->pixel);
				mlx_put_image_to_window(game->mlx, game->wdw, game->img, map->i * 64, map->j * 64);
			}
			if (map->matriz[map->i][map->j] == '0')
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "images/0.xpm", &game->pixel, &game->pixel);
				mlx_put_image_to_window(game->mlx, game->wdw, game->img, map->i * 64, map->j * 64);
			}
			if (map->matriz[map->i][map->j] == 'P')
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "grass.xpm", &game->pixel, &game->pixel);
				mlx_put_image_to_window(game->mlx, game->wdw, game->img, map->i * 64, map->j * 64);
			}
			if (map->matriz[map->i][map->j] == 'C')
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "Cimages/c.xpm", &game->pixel, &game->pixel);
				mlx_put_image_to_window(game->mlx, game->wdw, game->img, map->i * 64, map->j * 64);
			}
			if (map->matriz[map->i][map->j] == 'E')
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "grass.xpm", &game->pixel, &game->pixel);
				mlx_put_image_to_window(game->mlx, game->wdw, game->img, map->i * 64, map->j * 64);
			}
			map->i++;
		}
		map->j++;
	}
	return (1);
}