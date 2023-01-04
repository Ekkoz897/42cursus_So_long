/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:37:08 by apereira          #+#    #+#             */
/*   Updated: 2023/01/04 17:08:30 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(int fd, char **argv)
{
	char	*str;
	char	**map;
	int		i;
	int		height;

	height = 0;
	i = 0;
	while (get_next_line(fd))
	height++;
	close(fd);
	map = malloc(sizeof(char *) * height);
	fd = open(argv[1], O_RDONLY);
	while (height > 0)
	{
	str = get_next_line(fd);
	map[i] = str;
	i++;
	height--;
	}
	return (map);
}
