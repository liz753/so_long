/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:11 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/03 20:59:01 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memchr() function locates the first occurrence of c (converted to an
unsigned char) in string s. */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == (unsigned char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
