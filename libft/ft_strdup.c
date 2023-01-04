/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:42:44 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:51:06 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It copies the string s into a new string g using malloc.
 */

char	*ft_strdup(const char *s)
{
	char	*g;
	int		i;

	i = 0;
	g = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!g)
		return (NULL);
	while (s[i])
	{
		g[i] = s[i];
		i++;
	}
	g[i] = '\0';
	return (g);
}
