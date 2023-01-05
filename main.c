/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/05 15:52:55 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_key	*game;
	int		fd;
	t_map	*map_size;
	char	**map;

	if (!(argc == 2))
		return (0);
	game = malloc(sizeof(t_key));
	if (!game)
		return (0);
	map_size = malloc(sizeof(t_map));
	if (!map_size)
		return (0);
	fd = open(argv[1], O_RDONLY);
	vars_init(game, map_size);
	open_wdw(game);
	write(1, "\nisok\n", 6);
	mlx_hook(game->wdw, 2, 1L << 0, key_press, &game);
	mlx_hook(game->wdw, 17, 1L << 17, destroy_wdw, &game);
	map = map_cpy(fd, argv[1], map_size);
	wall_check(map, map_size);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
