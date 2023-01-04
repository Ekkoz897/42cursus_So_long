/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:52:45 by apereira          #+#    #+#             */
/*   Updated: 2023/01/04 17:27:12 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include "GNL/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIDTH 500
# define HEIGHT 600

typedef struct s_key
{
	void	*wdw;
	void	*mlx;
}t_key;

typedef struct s_map
{
	int	tall;
	int	large;
}t_map;

int		key_press(int key, t_key *game);
int		destroy_wdw(int key, t_key *game);
void	game_init(t_key	*game);
int		open_wdw(t_key *game);

#endif
