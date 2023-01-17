/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:59:00 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/02 17:21:59 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The substr() function allocates (with malloc(3)) and returns 
a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’. */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start > ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (len > ft_strlen(s))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}
