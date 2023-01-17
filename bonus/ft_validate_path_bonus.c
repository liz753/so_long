/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:59:50 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/11 16:46:47 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_count_c(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->c_count = 0;
	game->rows = ft_count_strings(game->map_2d);
	game->columns = ft_strlen(game->map_2d[0]);
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map_2d[y][x] == 'C')
			{
				game->c_count++;
			}
			x++;
		}
		y++;
	}
	return (game->c_count);
}

void	ft_floodfill(t_game *game, int x, int y)
{
	game->rows = ft_count_strings(game->map_2d);
	game->columns = ft_strlen(game->map_2d[0]);
	if (x <= 0 || x >= game->columns || y <= 0 || y >= game->rows
		|| game->map_2d[y][x] == '1' || game->map_2d[y][x] == 'c'
		|| game->map_2d[y][x] == 'o' || game->map_2d[y][x] == 'e'
		|| game->map_2d[y][x] == 'E')
	{
		if (game->map_2d[y][x] == 'E')
			game->exit_flag = TRUE;
		return ;
	}
	if (game->map_2d[y][x] == 'C')
	{
		game->c_count--;
		game->map_2d[y][x] = 'c';
	}
	else if (game->map_2d[y][x] == '0')
		game->map_2d[y][x] = 'o';
	ft_floodfill(game, x, (y + 1));
	ft_floodfill(game, x, (y - 1));
	ft_floodfill(game, (x + 1), y);
	ft_floodfill(game, (x - 1), y);
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

	y = 0;
	game->c_count = ft_count_c(game);
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map_2d[y][x] == 'P')
			{
				ft_floodfill(game, x, y);
				if (game->c_count != 0)
					ft_error_message(E_PATH, 1);
				ft_restore(game->map_2d);
				if (game->exit_flag == FALSE)
					ft_error_message(E_PATH, 1);
				return ;
			}
			x++;
		}
		y++;
	}
}
