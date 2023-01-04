/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:14:07 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:50:19 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterate through a linked list and apply a function to each element
 * 
 * @param lst a pointer to the first element of a linked list
 * @param f a function that takes a void pointer and returns nothing
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!f || !lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		f(lst->content);
		lst = tmp;
	}
}
