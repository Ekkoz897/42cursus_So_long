/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_won.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:20:03 by apereira          #+#    #+#             */
/*   Updated: 2023/01/18 11:22:30 by apereira         ###   ########.fr       */
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

void	close_first_window(t_game *game, int flag)
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
	if (flag == 1)
		display_victory(*game);
	else if (flag == 2)
		display_loss(*game);
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
	mlx_put_image_to_window(game.mlx, game.wdw, game.t_img.won,
		0, 0);
	mlx_hook(game.wdw, 2, 1L << 0, keydown_end, &game);
	mlx_hook(game.wdw, 17, 1L << 17, end_game, &game);
	mlx_loop(game.mlx);
}

int	end_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->t_img.won);
	mlx_destroy_image(game->mlx, game->t_img.lost);
	mlx_clear_window(game->mlx, game->wdw);
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	write(1, "GAME OVER\n\n", 12);
	free(game->mlx);
	exit (0);
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
