/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:37:08 by apereira          #+#    #+#             */
/*   Updated: 2023/01/05 15:38:55 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// passa o mapa para uma matris e conta as linhas (altura)
char	**map_cpy(int fd, char *argv, t_map	*map)
{
	char	*str;

	while (get_next_line(fd))
		map->large++;
	close(fd);
	map->matriz = malloc(sizeof(char *) * map->large);
	fd = open(argv, O_RDONLY);
	while (map->large > 0)
	{
		str = get_next_line(fd);
		map->matriz[map->tall] = str;
		map->tall++;
		map->large--;
	}
	map->large = ft_strlen(map->matriz[0]);
	return (wall_check(fd, map));
}

// verifica se as bordas do mapa estão ok
char	**wall_check(int fd, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map->matriz[0]) - 1;
	while (i <= j)
	{
		if (map->matriz[0][i] != '1' || map->matriz[map->tall - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map->matriz[i])
	{
		if ((ft_strlen(map->matriz[i]) - 1) != j)
			return (0);
		if (map->matriz[i][0] != '1' || map->matriz[i][j] != '1')
			return (0);
		i++;
	}
	if (check_CPE(map->matriz, map))
		return (map->matriz);
}

int	check_CPE(char **matriz, t_map *map)
{
	while (matriz[map->i])
	{
		map->j = 0;
		while(matriz[map->i][map->j])
		{
			if(matriz[map->i][map->j] == 'C')
				map->food++;
			else if(matriz[map->i][map->j] == 'P')
			{
				map->p++;
				map->player_x = map->i;
				map->player_y = map->j;
			}
			else if(matriz[map->i][map->j] == 'E')
				map->e++;
			else if(matriz[map->i][map->j] != '0' && matriz[map->i][map->large] != '\n' 
				&& matriz[map->i][map->j] != '1')
				return (0);
			map->j++;
		}
		map->i++;
	}
	if (!map->food || map->p != 1 || map->e != 1)
		return (0);
	return (1);
}
