/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:45:09 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:50:09 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterate through the list, deleting each node's content 
 * and freeing the node itself
 * 
 * @param lst a pointer to the first element of a linked list
 * @param del a pointer to a function that takes a single 
 * void pointer argument and returns nothing.
 * 
 * @return A pointer to the first element of the list.
 */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (del == NULL)
		return ;
	while (lst && *lst)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
