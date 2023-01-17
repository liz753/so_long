/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:20:50 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/03 18:56:17 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The lstclear() function deletes and frees the given node and every 
successor of that node, using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL. */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;
	t_list	*tmp;

	t = *lst;
	while (t != NULL)
	{
		tmp = t->next;
		ft_lstdelone(t, del);
		t = tmp;
	}
	*lst = NULL;
}
