/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/09 18:34:49 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char **argv)
{
	t_game	game;
	t_map	*map;
	int		fd;

	if (!(argc == 2))
		return (0);
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	fd = open(argv[1], O_RDONLY);
	vars_init(&game, map);
	map->matriz = map_cpy(fd, argv[1], map);
	if (!map->matriz)
		return (0);
	map->large = ft_strlen(map->matriz[0]);
	open_wdw(&game, map);
	img_to_window(&game, map);
	mlx_hook(game.wdw, 2, 1L << 0, key_press, &game);
	mlx_hook(game.wdw, 17, 1L << 17, destroy_wdw, &game);
	mlx_loop(game.mlx);
	destroy_wdw(fd, &game);
	return (0);
}
