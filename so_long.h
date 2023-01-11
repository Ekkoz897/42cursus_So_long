/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:52:45 by apereira          #+#    #+#             */
/*   Updated: 2023/01/11 18:18:26 by apereira         ###   ########.fr       */
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
	char	**matriz;
	void	*img;
	int		pixel;
	int		pp_x;
	int		pp_y;
	int		i;
	int		j;
}t_game;

typedef struct s_map
{
	int		i;
	int		j;
	int		p;
	int		e;

	int		tall;
	int		large;
	int		food;
	int		p_x;
	int		p_y;
}t_map;

int		ft_strlen(const char *str);
int		key_press(int key, t_game *game);
int		destroy_wdw(int key, t_game *game);
void	vars_init(t_game	*game, t_map *map_size);
int		open_wdw(t_game *game, t_map *map);
char	**map_cpy(int fd, char *argv, t_game	*game, t_map *map);
char	**wall_check(t_game *game, t_map *map);
int		check_cpe(char **matriz, t_map *map);
void	img_to_window(t_game *game, t_map *map);

#endif
