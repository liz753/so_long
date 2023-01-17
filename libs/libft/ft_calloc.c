/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:57:46 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/02 14:59:26 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The calloc() function contiguously allocates enough space for count
objects that are size bytes of memory each and returns a pointer to the
allocated memory. The allocated memory is filled with bytes of value zero.*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*memoire;

	memoire = (void *)malloc(count * size);
	if (memoire == NULL)
		return (NULL);
	ft_bzero(memoire, count * size);
	return (memoire);
}
