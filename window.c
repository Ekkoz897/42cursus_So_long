/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/12 20:30:19 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_wdw(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (0);
	game->wdw = mlx_new_window(game->mlx,
			game->large * 64, game->tall * 64, "So_Long");
	if (!(game->wdw))
	{
		free (game->mlx);
		return (0);
	}
	game->img = mlx_new_image(game->mlx, game->large * 64, game->tall * 64);
	game->pp_x = game->p_x * 64;
	game->pp_y = game->p_y * 64;
	return (1);
}

int	destroy_wdw(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->matriz);
	exit(0);
}

void	ifs(t_game *game)
{
	if (game->matriz[game->i][game->j] == '1')
		mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.one,
			game->j * 64, game->i * 64);
	else if (game->matriz[game->i][game->j] == 'c')
		mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.c,
			game->j * 64, game->i * 64);
	else if (game->matriz[game->i][game->j] == 'e')
		mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.e,
			game->j * 64, game->i * 64);
	else
		mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.zero,
			game->pp_x, game->pp_y);
}

void	img_to_window(t_game *game)
{
	game->i = 0;
	while (game->i < game->tall)
	{
		game->j = 0;
		while (game->j < game->large)
		{
			mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.zero,
				game->j * 64, game->i * 64);
			ifs(game);
			game->j++;
		}
		game->i++;
	}
}
