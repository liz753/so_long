/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:08 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/02 18:45:37 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The itoa() function allocates (with malloc(3)) and returns a string 
representing the integer received as an argument. 
It returns the string representing the integer.*/

static int	intlen(int nb)
{
	int	size;

	size = 1;
	if (nb == INT_MIN)
	{
		nb = INT_MAX;
		size++;
	}
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static char	*ft_strrev(char *str, int startpos)
{
	int		i;
	int		len;
	char	tmp;

	i = startpos;
	len = ft_strlen(str) - 1;
	while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

static void	ft_getdigits(int nb, int i, char *str, int int_min_edge)
{
	if (nb < 0)
	{
		if (nb == INT_MIN)
		{
			nb = INT_MAX;
			int_min_edge = 1;
		}
		else
			nb = -nb;
		str[i] = '-';
		i++;
	}
	while (nb > 9)
	{
		if (int_min_edge == 1 && i == 1)
			str[i] = (nb % 10) + 48 + int_min_edge;
		else
			str[i] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	str[i] = nb + 48;
	str[i + 1] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	len = intlen(n);
	str = (char *)malloc(len + 1);
	neg = 0;
	if (n < 0)
		neg = 1;
	if (str == NULL)
		return (NULL);
	ft_getdigits(n, 0, str, 0);
	ft_strrev(str, neg);
	return (str);
}
