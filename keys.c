/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/12 20:31:42 by apereira         ###   ########.fr       */
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
	img_to_window(game);
	if (game->a == 1)
		game->pp_x--;
	if (game->w == 1)
		game->pp_y--;
	if (game->s == 1)
		game->pp_y++;
	if (game->d == 1)
		game->pp_x++;
	mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.p,
		game->pp_x, game->pp_y);
	return (0);
}
