/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:57:44 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/03 20:00:03 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The bzero() function copies n bytes (b), 
each with a value of zero, into string s */

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (n > 0)
	{
		((char *)s)[i] = 0;
		i++;
		n--;
	}
}
