/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:57:11 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 14:59:02 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->columns)
		{
			if (game->map_2d[y][x] == 'P')
			{
				if (game->map_2d[y - 1][x] == '0' || game->map_2d[y
					- 1][x] == 'C' || game->map_2d[y - 1][x] == 'E')
				{
					if (ft_check_for_c_and_e(game, game->map_2d[y - 1][x]) == 1)
						return ;
					game->map_2d[y - 1][x] = 'P';
					game->map_2d[y][x] = '0';
					game->move_count++;
					ft_printf("Moves:%d\n", game->move_count);
					return ;
				}
			}
		}
	}
}

void	ft_move_down(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->columns)
		{
			if (game->map_2d[y][x] == 'P')
			{
				if (game->map_2d[y + 1][x] == '0' || game->map_2d[y
					+ 1][x] == 'C' || game->map_2d[y + 1][x] == 'E')
				{
					if (ft_check_for_c_and_e(game, game->map_2d[y + 1][x]) == 1)
						return ;
					game->map_2d[y + 1][x] = 'P';
					game->map_2d[y][x] = '0';
					game->move_count++;
					ft_printf("Moves:%d\n", game->move_count);
					return ;
				}
			}
		}
	}
}

void	ft_move_right(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->columns)
		{
			if (game->map_2d[y][x] == 'P')
			{
				if (game->map_2d[y][x + 1] == '0' || game->map_2d[y][x
					+ 1] == 'C' || game->map_2d[y][x + 1] == 'E')
				{
					if (ft_check_for_c_and_e(game, game->map_2d[y][x + 1]) == 1)
						return ;
					game->map_2d[y][x + 1] = 'P';
					game->map_2d[y][x] = '0';
					game->move_count++;
					ft_printf("Moves:%d\n", game->move_count);
					return ;
				}
			}
		}
	}
}

void	ft_move_left(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->columns)
		{
			if (game->map_2d[y][x] == 'P')
			{
				if (game->map_2d[y][x - 1] == '0' || game->map_2d[y][x
					- 1] == 'C' || game->map_2d[y][x - 1] == 'E')
				{
					if (ft_check_for_c_and_e(game, game->map_2d[y][x - 1]) == 1)
						return ;
					game->map_2d[y][x - 1] = 'P';
					game->map_2d[y][x] = '0';
					game->move_count++;
					ft_printf("Moves:%d\n", game->move_count);
					return ;
				}
			}
		}
	}
}

int	ft_check_for_c_and_e(t_game *game, char c)
{
	if (c == 'C')
	{
		game->c_count--;
		if (game->c_count == 0)
			ft_printf("Yeay! Let's go home and prepare dinner!\n");
	}
	else if (c == 'E' && game->c_count != 0)
	{
		ft_printf("Let's get all these nuts!\n");
		return (1);
	}
	else if (c == 'E' && game->c_count == 0)
	{
		game->exit = TRUE;
	}
	return (0);
}
