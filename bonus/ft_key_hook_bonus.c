/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:58:45 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 10:58:45 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	keys_t	key;

	game = param;
	key = keydata.key;
	if (keydata.action == MLX_PRESS)
	{
		if (key == MLX_KEY_ESCAPE)
			ft_espace(game);
		if (game->exit == FALSE)
		{
			game->turn_west = (key == MLX_KEY_A || key == MLX_KEY_LEFT);
			game->turn_east = (key == MLX_KEY_D || key == MLX_KEY_RIGHT);
			if ((key == MLX_KEY_W || key == MLX_KEY_UP))
				ft_move_up(game);
			if ((key == MLX_KEY_S || key == MLX_KEY_DOWN))
				ft_move_down(game);
			if ((key == MLX_KEY_D || key == MLX_KEY_RIGHT))
				ft_move_right(game);
			if ((key == MLX_KEY_A || key == MLX_KEY_LEFT))
				ft_move_left(game);
		}
	}
}

void	ft_espace(t_game *game)
{
	mlx_close_window(game->mlx);
	game->state = STATE_CLOSING;
	ft_print_message(game);
}
