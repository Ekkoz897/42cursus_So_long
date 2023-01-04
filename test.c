/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/02 17:05:54 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_linux/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*ptr_window;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	ptr_window = mlx_new_window(mlx_ptr, 500, 600, "FML");
	if (!ptr_window)
	{
		free(ptr_window);
		return (1);
	}
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, ptr_window);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
