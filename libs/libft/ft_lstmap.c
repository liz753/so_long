/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:21:26 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/03 22:49:14 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The lstmap() function iterates the list ’lst’ and applies the function ’f’ 
on the content of each node. Creates a new list resulting of the successive 
applications of the function ’f’. 
The ’del’ function is used to delete the content of a node if needed.
- For each node at a time in the lst-List it applies function f to the 
content, creates a new node with this content and add this new node to 
the new list new_lst. */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_lst;
	void	*content;

	new_lst = NULL;
	while (lst != NULL)
	{
		content = (f(lst->content));
		tmp = ft_lstnew(content);
		if (tmp == NULL)
		{
			ft_lstclear(&new_lst, del);
			free(content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}
