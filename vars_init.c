/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:20:33 by apereira          #+#    #+#             */
/*   Updated: 2023/01/11 18:18:50 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_init(t_game	*game, t_map *map)
{
	game->i = 0;
	game->j = 0;
	map->i = 0;
	map->j = 0;
	map->p = 0;
	map->e = 0;
	map->tall = 0;
	map->large = 0;
	map->food = 0;
	game->matriz = 0;
	map->p_x = 0;
	game->pp_x = 0;
	map->p_y = 0;
	game->pp_y = 0;
	game->mlx = 0;
	game->wdw = 0;
	game->pixel = 64;
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
