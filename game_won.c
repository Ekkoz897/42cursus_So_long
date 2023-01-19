/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_won.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:20:03 by apereira          #+#    #+#             */
/*   Updated: 2023/01/19 15:21:50 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_check(t_game *game)
{
	if (game->matriz[game->pp_y / 64][(game->pp_x + 19) / 64] == 'E')
		game->p++;
	if (game->matriz[(game->pp_y + 19) / 64][(game->pp_x + 39) / 64] == 'E')
		game->p++;
	if (game->matriz[(game->pp_y + 39) / 64][(game->pp_x + 19) / 64] == 'E')
		game->p++;
	if (game->matriz[(game->pp_y + 19) / 64][game->pp_x / 64] == 'E')
		game->p++;
}

void	display_victory(t_game *game)
{
	game->p++;
	mlx_destroy_image(game->mlx, game->t_img.c);
	mlx_destroy_image(game->mlx, game->t_img.open);
	mlx_destroy_image(game->mlx, game->t_img.closed);
	mlx_destroy_image(game->mlx, game->t_img.one);
	mlx_destroy_image(game->mlx, game->t_img.pr);
	mlx_destroy_image(game->mlx, game->t_img.pu);
	mlx_destroy_image(game->mlx, game->t_img.pl);
	mlx_destroy_image(game->mlx, game->t_img.zero);
	mlx_destroy_image(game->mlx, game->t_img.ded);
	mlx_destroy_image(game->mlx, game->t_img.won);
	mlx_destroy_image(game->mlx, game->t_img.lost);
	mlx_destroy_image(game->mlx, game->t_img.water);
	mlx_clear_window(game->mlx, game->wdw);
	mlx_destroy_window(game->mlx, game->wdw);
	// free(game->mlx);
	// game->mlx = mlx_init();
	game->wdw = mlx_new_window(game->mlx, 1000, 560, "Congratulations !");
	if (!game->wdw)
	{
		free (game->mlx);
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.won,
		0, 0);
	mlx_hook(game->wdw, 2, 1L << 0, keydown, game);
	mlx_hook(game->wdw, 17, 1L << 17, destroy_wdw, game);
	mlx_loop(game->mlx);
}
