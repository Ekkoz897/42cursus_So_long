/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:37:08 by apereira          #+#    #+#             */
/*   Updated: 2023/01/11 18:12:38 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// passa o mapa para uma matris e conta as linhas (altura)
char	**map_cpy(int fd, char *argv, t_game	*game, t_map *map)
{
	char	*str;

	while (get_next_line(fd))
		map->large++;
	close(fd);
	game->matriz = malloc(sizeof(char *) * map->large);
	fd = open(argv, O_RDONLY);
	while (map->large > 0)
	{
		str = get_next_line(fd);
		game->matriz[map->tall] = str;
		map->tall++;
		map->large--;
	}
	map->large = ft_strlen(game->matriz[0]);
	return (wall_check(game, map));
}

// verifica se as bordas do mapa estão ok
char	**wall_check(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(game->matriz[0]) - 1;
	while (i <= j)
	{
		if (game->matriz[0][i] != '1' || game->matriz[map->tall - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->tall)
	{
		if ((ft_strlen(game->matriz[i]) - 1) != j)
			return (0);
		if (game->matriz[i][0] != '1' || game->matriz[i][j] != '1')
			return (0);
		i++;
	}
	if (check_cpe(game->matriz, map))
		return (game->matriz);
	return (0);
}

int	check_cpe(char **matriz, t_map *map)
{
	map->i = -1;
	while (++map->i < map->tall)
	{
		map->j = -1;
		while (matriz[map->i][++map->j])
		{
			if (matriz[map->i][map->j] == 'C')
				map->food++;
			else if (matriz[map->i][map->j] == 'P')
			{
				map->p++;
				map->p_x = map->i;
				map->p_y = map->j;
			}
			else if (matriz[map->i][map->j] == 'E')
				map->e++;
			else if (matriz[map->i][map->j] != '0' &&
				matriz[map->i][map->large] != '\n' &&
				matriz[map->i][map->j] != '1')
				return (0);
		}
	}
	if (!map->food || map->p != 1 || map->e != 1)
		return (0);
	return (1);
}
