/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:43:15 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:51:37 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * It takes a string and a set of characters, 
 * and returns a copy of the string with the characters in
 * the set removed from the beginning and end of the string
 * 
 * @param s1 The string to be trimmed.
 * @param set the characters to be trimmed
 * 
 * @return A pointer to the trimmed string.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		len;
	char		*trimmed;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen((char *)s1 + i);
	if (len)
		while (ft_strchr(set, s1[len + i - 1]))
			len--;
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + i, len + 1);
	trimmed[len] = '\0';
	return (trimmed);
}
