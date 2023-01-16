/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/15 19:43:56 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keydown(int key, t_game *game)
{
	if (key == 'a')
		game->a = 1;
	else if (key == 'w')
		game->w = 1;
	else if (key == 's')
		game->s = 1;
	else if (key == 'd')
		game->d = 1;
	else if (key == 65307)
		destroy_wdw(game);
	return (0);
}

int	keyup(int key, t_game *game)
{
	if (key == 'a')
		game->a = 0;
	if (key == 'w')
		game->w = 0;
	if (key == 's')
		game->s = 0;
	if (key == 'd')
		game->d = 0;
	return (0);
}

#include <stdio.h>

int	p_move(t_game *game)
{
	printf("%i\n", game->matriz[(game->pp_x) / 64][(game->pp_y) / 64]);
	img_to_window(game);
	if (game->matriz[(game->pp_y + 1) / 64][(game->pp_x + 1) / 64] != '1' &&
		game->matriz[(game->pp_y + 39) / 64][(game->pp_x - 1) / 64] != '1')
		if (game->pp_x > 64)
			if (game->a == 1)
				game->pp_x--;
	if (game->matriz[game->pp_y / 64][(game->pp_x) / 64] != '1' &&
		game->matriz[game->pp_y / 64][(game->pp_x + 40) / 64] != '1')
		if (game->pp_y > 64)
			if (game->w == 1)
				game->pp_y--;
	if (game->matriz[(game->pp_y + 40) / 64][(game->pp_x) / 64] != '1' &&
		game->matriz[(game->pp_y + 40) / 64][(game->pp_x + 40) / 64] != '1')
		if (game->pp_y < (game->tall - 2) * 64)
			if (game->s == 1)
				game->pp_y++;
	if (game->matriz[(game->pp_y + 1) / 64][(game->pp_x + 41) / 64] != '1' &&
		game->matriz[(game->pp_y + 39) / 64][(game->pp_x + 41) / 64] != '1')
		if (game->pp_x < (game->large - 2) * 64)
			if (game->d == 1)
				game->pp_x++;
	mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.p,
		game->pp_x, game->pp_y);
	return (0);
}
