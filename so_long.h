/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:52:45 by apereira          #+#    #+#             */
/*   Updated: 2023/01/11 19:39:22 by apereira         ###   ########.fr       */
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
	int		tall;
	int		large;
	int		food;
	int		p;
	int		e;
	void	*img;
	int		pixel;
	int		p_x;
	int		p_y;
	int		pp_x;
	int		pp_y;

	int		i;
	int		j;
	int		w;
	int		a;
	int		s;
	int		d;
}t_game;

int		ft_strlen(const char *str);
int 	key_press(t_game *game);
int 	keydown(int key, t_game *game);
int 	keyup(int key, t_game *game);
int		destroy_wdw(int key, t_game *game);
void	vars_init(t_game	*game);
int		open_wdw(t_game *game);
char	**map_cpy(int fd, char *argv, t_game	*game);
char	**wall_check(t_game *game);
int		check_cpe(char **matriz, t_game *game);
void	img_to_window(t_game *game);
void	ifs(t_game *game);
int 	p_move(t_game *game);

#endif
