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
	t_map	*map;
	int		fd;

	if (!(argc == 2))
		return (0);
	game = malloc(sizeof(t_key));
	if (!game)
		return (0);
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	fd = open(argv[1], O_RDONLY);
	vars_init(game, map);
	open_wdw(game);
	mlx_hook(game->wdw, 2, 1L << 0, key_press, &game);
	mlx_hook(game->wdw, 17, 1L << 17, destroy_wdw, &game);
	map->matriz = map_cpy(fd, argv[1], map);
	if (!map->matriz)
		return (0);
	mlx_loop(game->mlx);
	destroy_wdw(fd, game);
	return (0);
}
