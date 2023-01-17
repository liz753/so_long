/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:58 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/02 17:17:33 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strtrim() function allocates (with malloc(3)) and returns a copy
of ’s1’ with the characters specified in ’set’ removed from the 
beginning and the end of the string. */

char	*ft_strtrim(char const *s1, char const *set)
{
	int	set_size;
	int	i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	set_size = ft_strlen(&s1[i]);
	if (set_size != 0)
		while (s1[i + set_size - 1] && ft_strchr(set, s1[i + set_size - 1]))
			set_size--;
	return (ft_substr(s1, i, set_size));
}
