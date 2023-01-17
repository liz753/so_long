/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:15 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/03 21:13:52 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memcmp() function compares byte string s1 against byte string s2.
Both strings are assumed to be n bytes long. */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]) && (i < n
			- 1))
	{
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
