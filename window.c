/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/05 15:43:50 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_wdw(t_key *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
	{
		free (game);
		return (0);
	}
	game->wdw = mlx_new_window(game->mlx, WIDTH, HEIGHT, "So_Long");
	if (!(game->wdw))
	{
		free(game->wdw);
		free (game);
		return (0);
	}
	return (1);
}

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
