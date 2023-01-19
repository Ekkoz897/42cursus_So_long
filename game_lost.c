/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_lost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:57:01 by apereira          #+#    #+#             */
/*   Updated: 2023/01/19 17:21:10 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_check(t_game *game)
{
	if (game->matriz[game->pp_y / 64][(game->pp_x + 19) / 64] == 'G')
		game->p += 2;
	if (game->matriz[(game->pp_y + 19) / 64][(game->pp_x + 39) / 64] == 'G')
		game->p += 2;
	if (game->matriz[(game->pp_y + 39) / 64][(game->pp_x + 19) / 64] == 'G')
		game->p += 2;
	if (game->matriz[(game->pp_y + 19) / 64][game->pp_x / 64] == 'G')
		game->p += 2;
}

void	display_loss(t_game game)
{
	mlx_clear_window(game.mlx, game.wdw);
	mlx_destroy_window(game.mlx, game.wdw);
	game.wdw = NULL;
	game.wdw2 = mlx_new_window(game.mlx, 1000, 560,
			"Better luck next time !");
	mlx_put_image_to_window(game.mlx, game.wdw2, game.t_img.lost,
		0, 0);
	mlx_hook(game.wdw2, 2, 1L << 0, keydown, &game);
	mlx_hook(game.wdw2, 17, 1L << 17, destroy_wdw, &game);
	mlx_loop(game.mlx);
}
