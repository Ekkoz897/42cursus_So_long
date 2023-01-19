/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_lost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:57:01 by apereira          #+#    #+#             */
/*   Updated: 2023/01/19 16:10:50 by apereira         ###   ########.fr       */
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

void	display_loss(t_game *game)
{
	game->p++;
	free(game->mlx);
	game->mlx = mlx_init();
	game->wdw = mlx_new_window(game->mlx, 1000, 560, "Better luck next time !");
	if (!game->wdw)
	{
		free (game->mlx);
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.lost,
		0, 0);
	mlx_hook(game->wdw, 2, 1L << 0, keydown, game);
	mlx_hook(game->wdw, 17, 1L << 17, destroy_wdw, game);
	mlx_loop(game->mlx);
}
