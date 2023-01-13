/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:20:33 by apereira          #+#    #+#             */
/*   Updated: 2023/01/13 18:56:08 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_init(t_game	*game)
{
	game->wdw = 0;
	game->mlx = 0;
	game->matriz = 0;
	game->tall = 0;
	game->large = 0;
	game->food = 0;
	game->p = 0;
	game->e = 0;
	game->pixel = 64;
	game->p_x = 0;
	game->p_y = 0;
	game->pp_x = 0;
	game->pp_y = 0;
	game->i = 0;
	game->j = 0;
	game->w = 0;
	game->a = 0;
	game->s = 0;
	game->d = 0;
}

void	imgs_init(t_game *game)
{
	game->img = 0;
	game->t_img.zero = mlx_xpm_file_to_image(game->mlx, "images/0.xpm",
			&game->pixel, &game->pixel);
	game->t_img.one = mlx_xpm_file_to_image(game->mlx, "images/1.xpm",
			&game->pixel, &game->pixel);
	game->t_img.p = mlx_xpm_file_to_image(game->mlx, "images/right.xpm",
			&game->pixel, &game->pixel);
	game->t_img.c = mlx_xpm_file_to_image(game->mlx, "images/c.xpm",
			&game->pixel, &game->pixel);
	game->t_img.e = mlx_xpm_file_to_image(game->mlx, "images/e.xpm",
			&game->pixel, &game->pixel);
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
