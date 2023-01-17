/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_2Dmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:53:55 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 16:19:06 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_strings(char **map_2d)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map_2d[i] != 0)
	{
		count++;
		i++;
	}
	return (count);
}

void	ft_validate_2dmap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->rows = ft_count_strings(game->map_2d);
	game->columns = ft_strlen(game->map_2d[0]);
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (x == 0 && game->map_2d[y][x] != '1')
				ft_error_message(E_WALLS, 1);
			if (y == 0 && game->map_2d[y][x] != '1')
				ft_error_message(E_WALLS, 1);
			if (x == game->columns - 1 && game->map_2d[y][x] != '1')
				ft_error_message(E_WALLS, 1);
			if (y == game->rows - 1 && game->map_2d[y][x] != '1')
				ft_error_message(E_WALLS, 1);
			x++;
		}
		y++;
	}
}
