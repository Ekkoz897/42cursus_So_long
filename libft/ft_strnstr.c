/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:43:13 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:51:32 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the first character of the word is found in the string, then check if the 
 * rest of the word is in the string.
 * 
 * @param str The string to be searched.
 * @param word the word to be found
 * @param n the number of characters to be searched
 * 
 * @return The address of the first character of the substring.
 */

char	*ft_strnstr(const char *str, const char *word, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (word[i] == '\0')
		return ((char *)str);
	while ((i < n) && (str[i]))
	{
		j = 0;
		while (str[i + j] == word[j] && ((i + j) < n))
		{
			if (word[j + 1] == '\0')
				return ((char *)&(str[i]));
			j++;
		}
		i++;
	}
	return (0);
}
