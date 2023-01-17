/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:52 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/03 21:11:46 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strnstr() function locates the first occurrence of the null-terminated 
string needle in the string haystack, where not more than len characters 
are searched.  
If needle is an empty string, haystack is returned; if needle occurs
nowhere in haystack, NULL is returned; otherwise a pointer to the first
character of the first occurrence of needle is returned. */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (haystack == NULL || needle == NULL)
		return (NULL);
	if (needle[j] == '\0' || needle == NULL)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] != '\0' && i < len)
	{
		while (needle[j] == haystack[i + j] && ((i + j) < len))
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
