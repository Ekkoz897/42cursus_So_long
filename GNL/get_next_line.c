/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:41:39 by apereira          #+#    #+#             */
/*   Updated: 2023/01/05 15:07:00 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	if (!temp)
		temp = ft_calloc (1, 1);
	temp = read_into_temp(fd, temp);
	if (temp[0] == '\0')
	{
		free (temp);
		temp = NULL;
	}
	if (!temp)
		return (NULL);
	len = cpy_line_only(temp);
	line = ft_substr(temp, 0, len);
	temp = ft_cleartemp(temp, len - 1);
	return (line);
}

char	*ft_free(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	free(res);
	return (temp);
}

char	*read_into_temp(int fd, char *temp)
{
	int		read_ret;
	char	*buff;

	read_ret = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(temp, '\n') && read_ret != 0)
	{
		read_ret = (int)read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free (buff);
			free (temp);
			return (0);
		}
		buff[read_ret] = '\0';
		temp = ft_free(temp, buff);
	}
	free (buff);
	return (temp);
}

int	cpy_line_only(char *temp)
{
	size_t	len;

	if (!temp)
		return (0);
	len = 0;
	while (temp[len])
	{
		if (temp[len] == '\n')
		{
			len ++;
			break ;
		}
		len++;
	}
	return (len);
}

char	*ft_cleartemp(char *src, int len)
{
	char	*temp;
	int		i;

	i = 0;
	if (!src[len])
	{
		free(src);
		return (0);
	}
	temp = ft_calloc(ft_strlen2(src) - len + 1, sizeof(char));
	len++;
	while (src[len])
		temp[i++] = src[len++];
	free(src);
	return (temp);
}
