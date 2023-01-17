/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:31 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/16 12:05:58 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The split() function allocates (with malloc(3)) and returns an array of 
strings obtained by splitting ’s’ using the character ’c’ as a delimiter. 
The array must end with a NULL pointer. */

static void	ft_free_all(char **str_tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(str_tab[i]);
		i--;
	}
	free(str_tab);
}

static int	ft_count_strings(char const *s, char c)
{
	int	count;
	int	seen_c;
	int	i;

	count = 0;
	seen_c = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && seen_c == 1)
		{
			count++;
			seen_c = 0;
		}
		else if (s[i] == c)
			seen_c = 1;
		i++;
	}
	return (count);
}

static char	*ft_set_one_substring(int *start, char const *s, char c)
{
	char	*substr;
	int		end;
	int		j;

	j = 0;
	end = *start;
	while (s[end] != c && s[end] != '\0')
		end++;
	substr = (char *)malloc(sizeof(char) * (end - *start + 1));
	if (substr == NULL)
		return (NULL);
	while (*start < end)
	{
		substr[j] = s[*start];
		j++;
		(*start)++;
	}
	substr[j] = '\0';
	return (substr);
}

static char	**ft_set_substrings(char const *s, char c, char **str_tab)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (s[start] != '\0')
	{
		if (s[start] != c)
		{
			str_tab[i] = ft_set_one_substring(&start, s, c);
			if (str_tab[i] == NULL)
			{
				ft_free_all(str_tab, i);
				return (NULL);
			}
			i++;
		}
		else
			start++;
	}
	str_tab[i] = 0;
	return (str_tab);
}

char	**ft_split(char const *s, char c)
{
	char	**str_tab;

	str_tab = malloc(sizeof(char *) * (ft_count_strings(s, c) + 1));
	if (str_tab == NULL)
		return (NULL);
	return (ft_set_substrings(s, c, str_tab));
}
