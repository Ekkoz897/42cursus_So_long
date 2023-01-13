/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:27:35 by apereira          #+#    #+#             */
/*   Updated: 2023/01/13 13:49:58 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (c == '\0')
		return ((char *)str + ft_strlen2(str));
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (0);
		++str;
	}
	return ((char *)str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen2(s + start) <= len)
		len = ft_strlen2(s + start);
	sub = ft_calloc(len + 1, 1);
	if (!sub)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen2(s) && s[i] && len > 0)
	{
		sub[j++] = s[i++];
		len--;
	}
	sub[j] = '\0';
	return (sub);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	array = malloc(size * nmemb);
	if (!array)
		return (NULL);
	while (i < nmemb * size)
		array[i++] = '\0';
	return ((void *)array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s1 || !s2)
		return (0);
	p = malloc(ft_strlen2(s1) + ft_strlen2(s2) + 1);
	if (!p)
		return (0);
	while (*s1 != '\0')
		p[i++] = *s1++;
	while (*s2 != '\0')
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}
