/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:42:51 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:51:14 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Appends src to the end of dst. It will append 
 * at most dstsize - strlen(dst) - 1 characters. It will then NUL-terminate.
 * 
 * size - max dest size 
 */

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	j = 0;
	while (src[j] != '\0' && i < (size - 1))
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[j]));
}
