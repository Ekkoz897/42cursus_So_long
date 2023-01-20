/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/20 02:24:36 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_wdw(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (0);
	game->wdw = mlx_new_window(game->mlx,
			game->large * 64, game->tall * 64, "so_long");
	if (!(game->wdw))
	{
		free (game->mlx);
		return (0);
	}
	game->pp_x = (game->p_x * 64) + 12;
	game->pp_y = (game->p_y * 64) + 12;
	return (1);
}

int	destroy_wdw(t_game *game)
{
	int	i;

	destroy_images(game);
	if (game->wdw2)
	{
		mlx_clear_window(game->mlx, game->wdw2);
		mlx_destroy_window(game->mlx, game->wdw2);
	}
	if (game->wdw)
	{	
		mlx_clear_window(game->mlx, game->wdw);
		mlx_destroy_window(game->mlx, game->wdw);
	}
	mlx_destroy_display(game->mlx);
	i = 0;
	while (i < game->tall)
		free(game->matriz[i++]);
	free (game->matriz);
	free(game->mlx);
	get_next_line(-1);
	write(1, "GAME OVER\n\n", 12);
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
	else if (game->matriz[game->i][game->j] == 'C')
		mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.ded,
			game->j * 64, game->i * 64);
	else if (game->matriz[game->i][game->j] == 'e')
		mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.closed,
			game->j * 64, game->i * 64);
	else if (game->matriz[game->i][game->j] == 'E')
		mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.open,
			game->j * 64, game->i * 64);
	else if (game->matriz[game->i][game->j] == 'G')
		mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.water,
			game->j * 64, game->i * 64);
	else
		mlx_put_image_to_window(game->mlx, game->wdw, game->t_img.zero,
			game->j * 64, game->i * 64);
}

void	img_to_window(t_game *game)
{
	unsigned long long	i;

	i = 0;
	if ((game->tall < 21 && game->large < 35)
		|| (game->tall < 10 && game->large < 40))
		while (i < 1050000)
			i++;
	food_collector(game);
	game->i = 0;
	while (game->i < game->tall)
	{
		game->j = 0;
		while (game->j < game->large)
		{
			ifs(game);
			game->j++;
		}
		game->i++;
	}
}
