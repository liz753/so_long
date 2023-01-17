/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:22 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/03 21:19:33 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memmove() function copies len bytes from string src to string dst.
The two strings may overlap; the copy is always done in a non-destructive
manner. */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL || src == NULL)
		return (0);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}
