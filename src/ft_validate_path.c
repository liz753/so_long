/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:53:06 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 12:57:13 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_c(char **map_2d)
{
	int	x;
	int	y;
	int	rows;
	int	columns;
	int	count_c;

	y = 0;
	count_c = 0;
	rows = ft_count_strings(map_2d);
	columns = ft_strlen(map_2d[0]);
	while (y < rows)
	{
		x = 0;
		while (x < columns)
		{
			if (map_2d[y][x] == 'C')
			{
				count_c++;
			}
			x++;
		}
		y++;
	}
	return (count_c);
}

void	ft_floodfill(char **map_2d, int x, int y, int *count_c)
{
	int	rows;
	int	columns;

	rows = ft_count_strings(map_2d);
	columns = ft_strlen(map_2d[0]);
	if (x <= 0 || x >= columns || y <= 0 || y >= rows || map_2d[y][x] == '1'
		|| *count_c == 0 || map_2d[y][x] == 'c' || map_2d[y][x] == 'o'
		|| map_2d[y][x] == 'e' || map_2d[y][x] == 'E')
		return ;
	if (map_2d[y][x] == 'C')
	{
		(*count_c)--;
		map_2d[y][x] = 'c';
	}
	else if (map_2d[y][x] == '0')
		map_2d[y][x] = 'o';
	ft_floodfill(map_2d, x, (y + 1), count_c);
	ft_floodfill(map_2d, x, (y - 1), count_c);
	ft_floodfill(map_2d, (x + 1), y, count_c);
	ft_floodfill(map_2d, (x - 1), y, count_c);
}

void	ft_restore(char **map_2d)
{
	int	x;
	int	y;
	int	rows;
	int	columns;

	y = 0;
	rows = ft_count_strings(map_2d);
	columns = ft_strlen(map_2d[0]);
	while (y < rows)
	{
		x = 0;
		while (x < columns)
		{
			if (map_2d[y][x] == 'c')
				map_2d[y][x] = 'C';
			else if (map_2d[y][x] == 'e')
				map_2d[y][x] = 'E';
			else if (map_2d[y][x] == 'o')
				map_2d[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	ft_validate_path(t_game *game)
{
	int	x;
	int	y;
	int	count_c;

	y = 0;
	game->rows = ft_count_strings(game->map_2d);
	game->columns = ft_strlen(game->map_2d[0]);
	count_c = ft_count_c(game->map_2d);
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map_2d[y][x] == 'P')
			{
				ft_floodfill(game->map_2d, x, y, &count_c);
				if (count_c != 0)
					ft_error_message(E_PATH, 1);
				ft_restore(game->map_2d);
				return ;
			}
			x++;
		}
		y++;
	}
}
