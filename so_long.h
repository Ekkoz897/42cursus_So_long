/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:52:45 by apereira          #+#    #+#             */
/*   Updated: 2023/01/09 17:40:04 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "GNL/get_next_line.h"
# include <fcntl.h>

typedef struct s_key
{
	void	*wdw;
	void	*mlx;
	void	*img;
	int		pixel;
}t_game;

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

size_t	ft_strlen(const char *str);
int		key_press(int key, t_game *game);
int		destroy_wdw(int key, t_game *game);
void	vars_init(t_game	*game, t_map *map_size);
int		open_wdw(t_game *game, t_map *map);
size_t	ft_strlen(const char *str);
char	**map_cpy(int fd, char *argv, t_map	*map_size);
char	**wall_check(int fd, t_map *map_size);
int		check_CPE(char **matriz, t_map *map);
int	img_to_window(t_game *game, t_map *map);

#endif
