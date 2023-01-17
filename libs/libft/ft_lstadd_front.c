/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:14:08 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/02 18:20:02 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The lstadd_front() function adds the node (element) ’new’ 
at the beginning of the list. */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL | new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
