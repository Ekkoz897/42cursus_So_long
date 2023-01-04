/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:42:41 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:51:04 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns a pointer to the first occurrence c in str.
 */

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if ((char) c == '\0')
		return ((char *)str + (int)ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
