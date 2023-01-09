/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:20:33 by apereira          #+#    #+#             */
/*   Updated: 2023/01/09 16:18:19 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_init(t_key	*game, t_map *map)
{
	map->i = 0;
	map->j = 0;
	map->p = 0;
	map->e = 0;
	map->tall = 0;
	map->large = 0;
	map->food = 0;
	map->matriz = 0;
	map->player_x = 0;
	map->player_y = 0;
	game->mlx = 0;
	game->wdw = 0;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
