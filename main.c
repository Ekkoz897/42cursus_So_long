/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/17 13:51:13 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	vars_init(&game);
	game.matriz = map_cpy(fd, argv[1], &game);
	if (!game.matriz)
	{
		write(1, "\nError\nThe provided map is invalid.\n\n", 38);
		return (0);
	}
	game_start(&game);
	return (0);
}

int	game_start(t_game *game)
{
	check_path(game->p_y, game->p_x, game);
	if (wall_check(game))
	{
		write(1, "\nThe map is valid, launching game...\n\n", 38);
		write(1, "------------------\n\n", 20);
	}
	else
	{
		write(1, "\nError\nThe player can't access all the collectibles.\n\n", 55);
		return (0);
	}
	open_wdw(game);
	imgs_init(game);
	mlx_hook(game->wdw, 2, 1L << 0, keydown, game);
	mlx_hook(game->wdw, 3, 1L << 1, keyup, game);
	mlx_hook(game->wdw, 17, 1L << 17, destroy_wdw, game);
	mlx_loop_hook(game->mlx, p_move, game);
	mlx_loop(game->mlx);
	return (0);
}

// verifica se o p tem um caminho de 0's ate todos os C e o E
int	check_path(int x, int y, t_game *game)
{
	if (game->matriz[x][y] == '0' || game->matriz[x][y] == 'P' ||
		game->matriz[x][y] == 'C' || game->matriz[x][y] == 'E')
	{
		if (game->matriz[x][y] == '0')
			game->matriz[x][y] = '-';
		if (game->matriz[x][y] == 'C')
			game->matriz[x][y] = 'c';
		if (game->matriz[x][y] == 'P')
			game->matriz[x][y] = 'p';
		if (game->matriz[x][y] == 'E')
			game->matriz[x][y] = 'e';
		if (check_path(x, y - 1, game))
			return (1);
		if (check_path(x + 1, y, game))
			return (1);
		if (check_path(x, y + 1, game))
			return (1);
		if (check_path(x - 1, y, game))
			return (1);
	}
	return (0);
}
