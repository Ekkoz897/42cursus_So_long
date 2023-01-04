/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:42:10 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:49:28 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It allocates memory for an array of nmemb elements 
 * of size bytes each, and returns a pointer to the
 * allocated memory. The memory is set to zero.
 * 
 *  nmemb - number of elements
 *  size  -  size of the memory block, in bytes.
 *  array - A pointer to the allocated memory.
 */

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*array;

	array = malloc(size * nmemb);
	if (!array)
		return (NULL);
	ft_bzero(array, (size * nmemb));
	return (array);
}
