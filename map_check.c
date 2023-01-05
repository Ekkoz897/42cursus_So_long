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
char	**map_cpy(int fd, char *argv, t_map	*map_size)
{
	char	*str;
	char	**map;

	write(1, "\nmapcpy\n", 8);
	while (get_next_line(fd))
		map_size->large++;
	write(1, "\nmapcpy\n", 8);
	close(fd);
	map = malloc(sizeof(char *) * map_size->large);
	fd = open(argv, O_RDONLY);
	while (map_size->large > 0)
	{
	str = get_next_line(fd);
	map[map_size->tall] = str;
	map_size->tall++;
	map_size->large--;
	}
	return (map);
}

// verifica se as bordas do mapa estão ok
int	wall_check(char **map, t_map *map_size)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[0]) - 1;
	while (i <= j)
	{
		if (map[0][i] != '1' || map[map_size->tall - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map[i])
	{
		if ((ft_strlen(map[i]) - 1) != j)
			return (0);
		if (map[i][0] != '1' || map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}
