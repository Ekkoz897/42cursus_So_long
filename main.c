/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/12 20:31:21 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (!(argc == 2))
		return (0);
	vars_init(&game);
	fd = open(argv[1], O_RDONLY);
	game.matriz = map_cpy(fd, argv[1], &game);
	if (!game.matriz)
		return (0);
	if (wall_check(&game))
		write(1, "The map is valid, launching game...", 36);
	game.large = ft_strlen(game.matriz[0]);
	open_wdw(&game);
	imgs_init(&game);
	mlx_hook(game.wdw, 2, 1L << 0, keydown, &game);
	mlx_hook(game.wdw, 3, 1L << 1, keyup, &game);
	mlx_hook(game.wdw, 17, 1L << 17, destroy_wdw, &game);
	mlx_loop_hook(game.mlx, p_move, &game);
	mlx_loop(game.mlx);
	destroy_wdw(&game);
	return (0);
}
