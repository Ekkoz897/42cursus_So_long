/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/11 18:17:18 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_game *game)
{
	if (key == 65307)
	{
		destroy_wdw(key, game);
	}
	if (key == 'w')
		game->pp_y += 1;
	else if (key == 'a')
		game->pp_x -= 1;
	else if (key == 's')
		game->pp_y -= 1;
	else if (key == 'd' )
		game->pp_x += 1;
		img_to_window(game);
	return (1);
}
