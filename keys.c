/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/12 15:44:38 by apereira         ###   ########.fr       */
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
		destroy_wdw(key, game);
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
	if (game->a == 1)
		game->pp_x--;
	if (game->w == 1)
		game->pp_y--;
	if (game->s == 1)
		game->pp_y++;
	if (game->d == 1)
		game->pp_x++;
	imgs_init(game);
	game->i = 0;
	img_to_window(game);
	game->img = game->t_img.zero;
	mlx_put_image_to_window(game->mlx, game->wdw, game->img,
		game->pp_x, game->pp_y);
	free(game->img);
	return (0);
}
