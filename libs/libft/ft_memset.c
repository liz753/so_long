/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:26 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/03 19:56:51 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memset() function writes len bytes of value c (converted to an
unsigned char) to the string b. */

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (b == NULL)
		return (0);
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}
