/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/19 18:31:10 by apereira         ###   ########.fr       */
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

int	p_move_ifs(t_game *game)
{
	int	i;
	int	j;

	i = game->pp_x;
	j = game->pp_y;
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
	if (i != game->pp_x || j != game->pp_y)
		return (1);
	return (0);
}

int	p_move(t_game *game)
{
	static int	count;
	char		*couunt;

	if (game->p == 1)
	{
		couunt = ft_itoa(count / 64);
		mlx_clear_window(game->mlx, game->wdw);
		img_to_window(game);
		if (player_anim(game) && p_move_ifs(game))
			count++;
		exit_check(game);
		enemy_check(game);
		mlx_string_put(game->mlx, game->wdw,
			(((game->large - 2) * 64) - 32),
			(game->tall * 64) - 26, 0x000000, "NUMBER OF MOVEMENTS : ");
		mlx_string_put(game->mlx, game->wdw,
			(((game->large - 2) * 64) + 100),
			(game->tall * 64) - 26, 0x000000, couunt);
		free(couunt);
	}
	else if (game->p == 2 && (game->p)++ && (game->p)++)
		display_victory(*game);
	else if (game->p == 3 && game->p++)
		display_loss(*game);
	return (0);
}
