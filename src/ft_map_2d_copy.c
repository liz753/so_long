/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2D_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:56:57 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 14:59:26 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_2dmap_copy(t_game *game)
{
	char	**map_2d_copy;
	int		i;

	i = 0;
	map_2d_copy = ft_calloc(sizeof(char *), (game->rows));
	if (!map_2d_copy)
		return (NULL);
	while (i < game->rows)
	{
		map_2d_copy[i] = ft_strdup(game->map_2d[i]);
		i++;
	}
	return (map_2d_copy);
}

void	ft_free_map_2d(char **map_2d)
{
	int	i;

	i = 0;
	if (map_2d == NULL)
		return ;
	while (map_2d[i])
	{
		free(map_2d[i]);
		i++;
	}
	free(map_2d);
	map_2d = NULL;
}
