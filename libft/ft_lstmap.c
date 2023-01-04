/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:21:31 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:50:28 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a list, applies a function to each element of the list, 
 * and returns a new list with the
 * results of the function
 * 
 * @param lst The list to iterate over.
 * @param f a function that takes a void pointer and returns a void pointer
 * @param del a function that frees the memory of the content of a link.
 * 
 * @return A pointer to the new list.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*first;

	first = NULL;
	while (lst)
	{
		newlst = ft_lstnew(f(lst->content));
		if (!newlst)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, newlst);
		lst = lst->next;
	}
	return (first);
}
