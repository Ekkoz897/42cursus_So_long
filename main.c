/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/11 18:16:53 by apereira         ###   ########.fr       */
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
	map = malloc(sizeof(t_game));
	if (!map)
		return (0);
	fd = open(argv[1], O_RDONLY);
	vars_init(&game, map);
	game.matriz = map_cpy(fd, argv[1], &game, map);
	if (!game.matriz)
		return (0);
	map->large = ft_strlen(game.matriz[0]);
	open_wdw(&game, map);
	img_to_window(&game, map);
	mlx_hook(game.wdw, 17, 1L << 17, destroy_wdw, &game);
	mlx_hook(inf.ptr.win_ptr, 2, 1L << 0, keydown, &inf);
	mlx_hook(inf.ptr.win_ptr, 3, 1L << 1, keyup, &inf);
	mlx_loop_hook(inf.ptr.mlx_ptr, key_press, &game);
	mlx_loop(game.mlx);
	destroy_wdw(fd, &game);
	return (0);
}
