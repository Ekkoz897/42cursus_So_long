/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:45:23 by apereira          #+#    #+#             */
/*   Updated: 2023/01/18 10:29:44 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	food_collector(t_game *game)
{
	if (game->matriz[game->pp_y / 64][(game->pp_x + 19) / 64] == 'c')
	{
		game->matriz[game->pp_y / 64][(game->pp_x + 19) / 64] = 'C';
		game->food--;
	}
	if (game->matriz[(game->pp_y + 19) / 64][(game->pp_x + 39) / 64] == 'c')
	{
		game->matriz[(game->pp_y + 19) / 64][(game->pp_x + 39) / 64] = 'C';
		game->food--;
	}
	if (game->matriz[(game->pp_y + 39) / 64][(game->pp_x + 19) / 64] == 'c')
	{
		game->matriz[(game->pp_y + 39) / 64][(game->pp_x + 19) / 64] = 'C';
		game->food--;
	}
	if (game->matriz[(game->pp_y + 19) / 64][game->pp_x / 64] == 'c')
	{
		game->matriz[(game->pp_y + 19) / 64][game->pp_x / 64] = 'C';
		game->food--;
	}
	if (game->food == 0)
		game->matriz[game->end_y][game->end_x] = 'E';
}

void	player_anim(t_game *game)
{
	void	*img;

	img = game->t_img.pr;
	if (game->w == 1)
		img = game->t_img.pu;
	if (game->a == 1)
		img = game->t_img.pl;
	if (game->d == 1)
		img = game->t_img.pr;
	if (game->s == 1)
		img = game->t_img.pr;
	mlx_put_image_to_window(game->mlx, game->wdw, img,
		game->pp_x, game->pp_y);
}
