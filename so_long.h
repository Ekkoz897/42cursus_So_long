/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:52:45 by apereira          #+#    #+#             */
/*   Updated: 2023/01/05 15:36:55 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "GNL/get_next_line.h"
# include <fcntl.h>

# define WIDTH 600
# define HEIGHT 250

typedef struct s_key
{
	void	*wdw;
	void	*mlx;
}t_key;

typedef struct s_map
{
	int	i;
	int	j;
	int	p;
	int	e;

	int		tall;
	int		large;
	int		food;
	char	**matriz;
	int		player_x;
	int		player_y;
}t_map;

int		key_press(int key, t_key *game);
int		destroy_wdw(int key, t_key *game);
void	vars_init(t_key	*game, t_map *map_size);
int		open_wdw(t_key *game);
size_t	ft_strlen(const char *str);
char	**map_cpy(int fd, char *argv, t_map	*map_size);
char	**wall_check(int fd, t_map *map_size);
int		check_CPE(char **matriz, t_map *map);

#endif
