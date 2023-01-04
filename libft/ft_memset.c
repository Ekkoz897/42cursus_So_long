/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:42:40 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:50:48 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It sets the first n bytes of str to the specified value c.
 * 
 * @param n the number of bytes to be set to the value c
 * 
 */

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;

	str1 = (unsigned char *)str;
	i = 0;
	while (i < n)
		str1[i++] = c;
	return (str);
}
