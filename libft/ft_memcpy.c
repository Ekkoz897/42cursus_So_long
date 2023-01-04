/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:42:38 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:50:41 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It copies n bytes from src to dest.
 * 
 * dest - This is the destination array where the 
 * content is to be copied, type-casted to a
 * pointer.
 * src - pointer to the source.
 * n - number of bytes to copy
 * 
 * @return a pointer to the destination.
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destino;

	i = 0;
	source = (unsigned char *)src;
	destino = (unsigned char *)dest;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		destino[i] = source[i];
		i++;
	}
	return (dest);
}
