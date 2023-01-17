/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:58:51 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/16 12:08:15 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
				if (ft_strchr("0CEX", game->map_2d[y - 1][x]))
				{
					if (ft_check_for_cex(game, game->map_2d[y - 1][x]) == 1)
						return ;
					game->map_2d[y - 1][x] = 'P';
					game->map_2d[y][x] = '0';
					game->move_count++;
					ft_print_moves(game);
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
				if (ft_strchr("0CEX", game->map_2d[y + 1][x]))
				{
					if (ft_check_for_cex(game, game->map_2d[y + 1][x]) == 1)
						return ;
					game->map_2d[y + 1][x] = 'P';
					game->map_2d[y][x] = '0';
					game->move_count++;
					ft_print_moves(game);
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
				if (ft_strchr("0CEX", game->map_2d[y][x + 1]))
				{
					if (ft_check_for_cex(game, game->map_2d[y][x + 1]) == 1)
						return ;
					game->map_2d[y][x + 1] = 'P';
					game->map_2d[y][x] = '0';
					game->move_count++;
					ft_print_moves(game);
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
				if (ft_strchr("0CEX", game->map_2d[y][x - 1]))
				{
					if (ft_check_for_cex(game, game->map_2d[y][x - 1]) == 1)
						return ;
					game->map_2d[y][x - 1] = 'P';
					game->map_2d[y][x] = '0';
					game->move_count++;
					ft_print_moves(game);
					return ;
				}
			}
		}
	}
}

int	ft_check_for_cex(t_game *game, char c)
{
	if (c == 'C')
	{
		game->c_count--;
		game->collected_c++;
		ft_print_collected_c(game);
		if (game->c_count == 0)
		{
			mlx_delete_image(game->mlx, game->texts.m1);
			game->texts.m2 = mlx_put_string(game->mlx,
					"Yeay! Let's go home and prepare dinner!",
					game->columns + 64 + 110, game->rows * 64 + 20);
		}
	}
	else if (c == 'E' && game->c_count != 0)
	{
		game->texts.m1 = mlx_put_string(game->mlx,
				"Let's get all these nuts!", game->columns + 64 + 240,
				game->rows * 64 + 20);
		return (1);
	}
	else if (c == 'E' && game->c_count == 0)
		game->exit = TRUE;
	else if (c == 'X')
		game->gameover = TRUE;
	return (0);
}
