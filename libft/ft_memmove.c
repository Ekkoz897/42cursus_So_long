/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:42:39 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:50:45 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// a posicao do pointer e menor do que o outro, n e o tamanho do aray

#include "libft.h"

/**
 * It copies n bytes from src to dest. The memory areas may overlap. 
 * copying takes place as though the bytes in src are first copied into a 
 * temporary array  that does not overlap src or dest, and the bytes are 
 * then copied from the temporary array to dest.
 * 
 * n - number of bytes to be moved.
 * 
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destino;

	source = (unsigned char *)src;
	destino = (unsigned char *)dest;
	if (!destino && !source)
		return (0);
	if (source < destino)
	{
		i = n;
		while (i-- > 0)
			destino[i] = source[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			destino[i] = source[i];
			i++;
		}
	}
	return (dest);
}
