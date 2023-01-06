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
	return (map->matriz);
}

int	check_CPE(char **matriz, t_map *map)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (matriz[i])
	{
		j = 0;
		while(matriz[i][j])
		{
			if(matriz[i][j] == 'C')
				map->food++;
			if(matriz[i][j] == 'P')
				p++;
			if(matriz[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (!map->food || !p || !e)
		return (0);
	else
		return (1);
}
