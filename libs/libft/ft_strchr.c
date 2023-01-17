/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:34 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/03 20:57:47 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strchr() function locates the first occurrence of c (converted to a
char) in the string pointed to by s. 
The terminating null character is considered to be part of the string; 
therefore if c is `\0', the functions locate the terminating `\0'. */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
