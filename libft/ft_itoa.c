/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:46:26 by apereira          #+#    #+#             */
/*   Updated: 2022/11/14 15:02:34 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It converts an integer to a string.
 * 
 * @param n the number to be converted
 * 
 * @return A pointer to a string.
 */

int	ft_digits(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	n = -n;
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		digits = ft_digits(n) + 1;
	else
		digits = ft_digits(n);
	array = malloc(digits + 1);
	if (!array)
		return (NULL);
	if (n < 0)
		array[0] = '-';
	if (n < 0)
		n = -n;
	if (n == 0)
		array[0] = '0';
	array[digits] = '\0';
	while (n != 0 && digits >= 0)
	{
		array[digits-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (array);
}
