/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/04 17:56:12 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_wdw(int key, t_key *game)
{
	if (key)
	{
		mlx_clear_window(game->mlx, game->wdw);
		mlx_destroy_window(game->mlx, game->wdw);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free (game);
		exit(0);
	}
	return (0);
}

int	key_press(int key, t_key *game)
{
	if (key == 65307)
	{
		destroy_wdw(key, game);
		free (game);
	}
	if (key == 'w')
		write(1, "w", 1);
	else if (key == 'a')
		write(1, "a", 1);
	else if (key == 's')
		write(1, "s", 1);
	else if (key == 'd' )
		write(1, "d", 1);
	return (0);
}

void	game_init(t_key	*game)
{
	game->mlx = 0;
	game->wdw = 0;
}

int	main(int argc, char **argv)
{
	t_key	*game;

	if (!(argc == 2))
		return (0);
	game = malloc(sizeof(t_key));
	game_init(game);
	game->mlx = mlx_init();
	if (!(game->mlx))
	{
		free (game);
		return (1);
	}
	game->wdw = mlx_new_window(game->mlx, 500, 600, "FML");
	if (!(game->wdw))
	{
		free(game->wdw);
		free (game);
		return (1);
	}
	mlx_hook(game->wdw, 2, 1L << 0, key_press, &game);
	mlx_hook(game->wdw, 17, 1L << 17, destroy_wdw, &game);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
