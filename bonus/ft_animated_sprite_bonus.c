/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animated_sprite_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:58:39 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 15:31:43 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animated_sprite(t_game *game)
{
	int		speed;

	speed = 50;
	game->pigeon = game->loop % speed;
	if (game->collected_c >= 3 || game->c_count <= 3)
	{
		if (game->pigeon < speed / 2 && game->pi_left == TRUE)
			game->assets.pigeon = ft_asset_to_image(game->mlx,
					"./assets/pigeon_w.xpm42");
		else if (game->pigeon >= speed / 2 && game->pi_left == TRUE)
			game->assets.pigeon = ft_asset_to_image(game->mlx,
					"./assets/pi_w2.xpm42");
		else if (game->pigeon < speed / 2 && game->pi_right == TRUE)
			game->assets.pigeon = ft_asset_to_image(game->mlx,
					"./assets/pi_e.xpm42");
		else if (game->pigeon >= speed / 2 && game->pi_right == TRUE)
			game->assets.pigeon = ft_asset_to_image(game->mlx,
					"./assets/pi_e2.xpm42");
	}
}

void	ft_enemy_moves(t_game *game)
{
	int		speed;
	int		x;
	int		y;

	y = -1;
	speed = 80;
	game->pigeon = game->loop % speed;
	if (game->pigeon == speed - 1)
	{
		while (++y < game->rows)
		{
			x = -1;
			while (++x < game->columns)
			{
				if (game->map_2d[y][x] == 'X')
				{
					while (ft_move_if_poss(game, x, y) == FALSE)
					{
					}
					return ;
				}
			}
		}
	}
}

bool	ft_move_if_poss(t_game *game, int x, int y)
{
	int		rand_x;
	int		rand_y;

	rand_x = (rand() % 3) - 1;
	rand_y = (rand() % 3) - 1;
	game->pi_right = rand_x > 0;
	game->pi_left = rand_x < 0;
	if (ft_strchr("0P", game->map_2d[y + rand_y][x + rand_x]))
	{
		if (game->map_2d[y + rand_y][x + rand_x] == 'P')
			game->gameover = TRUE;
		game->map_2d[y + rand_y][x + rand_x] = 'X';
		game->map_2d[y][x] = '0';
		return (TRUE);
	}
	return (FALSE);
}
