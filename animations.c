/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:45:23 by apereira          #+#    #+#             */
/*   Updated: 2023/01/17 21:34:56 by apereira         ###   ########.fr       */
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

void	display_victory(t_game game)
{
	game.p++;
	game.mlx = mlx_init();
	mlx_clear_window(game.mlx, game.wdw);
	mlx_destroy_window(game.mlx, game.wdw);
	game.wdw = mlx_new_window(game.mlx, 1000, 560, "Congratulations !");
	if (!game.wdw)
	{
		free (game.mlx);
		return ;
	}
	mlx_put_image_to_window(game.mlx, game.wdw, game.t_img.end,
		0, 0);
	mlx_hook(game.wdw, 2, 1L << 0, keydown_end, &game);
	mlx_hook(game.wdw, 17, 1L << 17, end_game, &game);
	mlx_loop(game.mlx);
}

void	close_first_window(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->t_img.c);
	mlx_destroy_image(game->mlx, game->t_img.open);
	mlx_destroy_image(game->mlx, game->t_img.closed);
	mlx_destroy_image(game->mlx, game->t_img.one);
	mlx_destroy_image(game->mlx, game->t_img.pr);
	mlx_destroy_image(game->mlx, game->t_img.pu);
	mlx_destroy_image(game->mlx, game->t_img.pl);
	mlx_destroy_image(game->mlx, game->t_img.zero);
	mlx_destroy_image(game->mlx, game->t_img.ded);
	free(game->mlx);
	i = 0;
	while (game->matriz[i])
	{
		free(game->matriz[i]);
		i++;
	}
	get_next_line(-1);
	free (game->matriz[i]);
	free (game->matriz);
	display_victory(*game);
}

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
