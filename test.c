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
	ptr_window = mlx_new_window(mlx_ptr, 500, 600, "FML");
	mlx_loop(mlx_ptr);
}
