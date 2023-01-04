/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:28:57 by apereira          #+#    #+#             */
/*   Updated: 2022/11/09 19:50:15 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It calls the function on the content of the linked list
 * 
 * @param lst The list to be deleted.
 * @param del pointer to a function
 */

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del == NULL)
		return ;
	if (lst != NULL)
		del(lst->content);
	free (lst);
}
