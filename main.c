/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/13 18:23:28 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_start(t_game *game, char *map)
{
	int	fd;

	vars_init(game);
	fd = open(map, O_RDONLY);
	game->matriz = map_cpy(fd, map, game);
	if (!game->matriz)
		return (0);
	check_path(game->p_y, game->p_x, game);
	if (wall_check(game))
	{
		write(1, "The map is valid, launching game...\n\n", 38);
		write(1, "------------------\n\n", 20);
	}
	else
		return (0);
	open_wdw(game);
	imgs_init(game);
	mlx_hook(game->wdw, 2, 1L << 0, keydown, game);
	mlx_hook(game->wdw, 3, 1L << 1, keyup, game);
	mlx_hook(game->wdw, 17, 1L << 17, destroy_wdw, game);
	mlx_loop_hook(game->mlx, p_move, game);
	mlx_loop(game->mlx);
	destroy_wdw(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	game_start(&game, argv[1]);
	return (0);
}
