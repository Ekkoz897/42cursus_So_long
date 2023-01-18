/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/17 21:34:48 by apereira         ###   ########.fr       */
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

int	p_move(t_game *game)
{
	if (game->p == 1)
	{
		img_to_window(game);
		if (game->matriz[game->pp_y / 64][(game->pp_x - 1) / 64] != '1' &&
			game->matriz[(game->pp_y + 39) / 64][(game->pp_x - 1) / 64] != '1')
			if (game->a == 1)
				game->pp_x--;
		if (game->matriz[(game->pp_y - 1) / 64][game->pp_x / 64] != '1' &&
			game->matriz[(game->pp_y - 1) / 64][(game->pp_x + 39) / 64] != '1')
			if (game->w == 1)
				game->pp_y--;
		if (game->matriz[(game->pp_y + 40) / 64][(game->pp_x) / 64] != '1' &&
			game->matriz[(game->pp_y + 40) / 64][(game->pp_x + 39) / 64] != '1')
			if (game->s == 1)
				game->pp_y++;
		if (game->matriz[game->pp_y / 64][(game->pp_x + 40) / 64] != '1' &&
			game->matriz[(game->pp_y + 39) / 64][(game->pp_x + 40) / 64] != '1')
			if (game->d == 1)
				game->pp_x++;
		player_anim(game);
		exit_check(game);
	}
	else if (game->p == 2)
		close_first_window(game);
	return (0);
}

int	keydown_end(int key, t_game *game)
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
		end_game(game);
	return (0);
}
