/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:52:45 by apereira          #+#    #+#             */
/*   Updated: 2023/01/15 18:07:54 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "GNL/get_next_line.h"
# include <fcntl.h>

typedef struct s_game
{
	struct s_img
	{
		void	*zero;
		void	*one;
		void	*c;
		void	*p;
		void	*e;
	}t_img;
	void	*wdw;
	void	*mlx;
	void	*img;
	char	**matriz;
	int		tall;
	int		large;
	int		food;
	int		p;
	int		e;
	int		pixel;
	int		pixelp;
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

int		game_start(t_game *game, char *file);
int		ft_strlen(const char *str);
int		key_press(t_game *game);
int		keydown(int key, t_game *game);
int		keyup(int key, t_game *game);
int		destroy_wdw(t_game *game);
void	vars_init(t_game	*game);
int		open_wdw(t_game *game);
char	**map_cpy(int fd, char *argv, t_game	*game);
int		wall_check(t_game *game);
int		check_cpe(char **matriz, t_game *game);
int		check_path(int i, int j, t_game *inf);
int		check_path_check(char **matriz, t_game *game);
void	imgs_init(t_game *game);
void	img_to_window(t_game *game);
void	ifs(t_game *game);
int		p_move(t_game *game);

#endif
