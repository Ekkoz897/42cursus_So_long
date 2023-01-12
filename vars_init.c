/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:20:33 by apereira          #+#    #+#             */
/*   Updated: 2023/01/11 19:40:39 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_init(t_game	*game)
{
	game->i = 0;
	game->j = 0;
	game->i = 0;
	game->j = 0;
	game->p = 0;
	game->e = 0;
	game->tall = 0;
	game->large = 0;
	game->food = 0;
	game->matriz = 0;
	game->p_x = 0;
	game->pp_x = 0;
	game->p_y = 0;
	game->pp_y = 0;
	game->mlx = 0;
	game->wdw = 0;
	game->pixel = 64;
	game->w = 0;
	game->a = 0;
	game->s = 0;
	game->d = 0;
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
