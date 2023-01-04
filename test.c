/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/04 13:41:29 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <unistd.h>

int	key_press(int key, t_key *wdw_mlx)
{
	if (key == 27)
	{
		mlx_destroy_display(wdw_mlx->mlx_ptr);
		mlx_destroy_image(wdw_mlx->mlx_ptr, wdw_mlx->wdw_ptr);
		free(wdw_mlx->mlx_ptr);
	}
	if (key == 'w')
		write(1, "w", 1);
	else if (key == 'a')
		write(1, "a", 1);
	else if (key == 's')
		write(1, "s", 1);
	else if (key == 'd' )
		write(1, "d", 1);
	return (0);
}

int	key_npress(int key, t_key *wdw_mlx)
{
	if (key)
		wdw_mlx->key_down = 0;
	return (0);
}

int	main(void)
{
	t_key	*wdw_mlx;

	wdw_mlx = malloc(sizeof(t_key));
	wdw_mlx->mlx_ptr = mlx_init();
	if (!(wdw_mlx->mlx_ptr))
		return (1);
	wdw_mlx->wdw_ptr = mlx_new_window(wdw_mlx->mlx_ptr, 500, 600, "FML");
	if (!(wdw_mlx->wdw_ptr))
	{
		free(wdw_mlx->wdw_ptr);
		return (1);
	}
	mlx_hook(wdw_mlx->wdw_ptr, 2, 1L << 0, key_press, &wdw_mlx);
	mlx_hook(wdw_mlx->wdw_ptr, 3, 1L << 1, key_npress, &wdw_mlx);
	mlx_loop(wdw_mlx->mlx_ptr);
	mlx_destroy_window(wdw_mlx->mlx_ptr, wdw_mlx->wdw_ptr);
	mlx_destroy_display(wdw_mlx->mlx_ptr);
	free(wdw_mlx->mlx_ptr);
}
