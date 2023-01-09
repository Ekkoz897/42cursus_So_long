/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/09 16:09:19 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_key *game)
{
	if (key == 65307)
	{
		destroy_wdw(key, game);
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

