/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status_in_window_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:58:29 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/16 12:19:16 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_moves_and_acorns(t_game *game)
{
	char	*total_count;

	game->texts.mo = mlx_put_string(game->mlx, "Moves:", 3,
			game->rows * 64 + 10);
	game->texts.ac = mlx_put_string(game->mlx, "Acorns:   /", 3,
			game->rows * 64 + 40);
	total_count = ft_itoa(ft_count_c(game));
	game->texts.acorn_nbr = mlx_put_string(game->mlx,
			total_count, 125, game->rows * 64 + 40);
	free(total_count);
}

void	ft_print_moves(t_game *game)
{
	char	*move_count;

	move_count = ft_itoa(game->move_count);
	mlx_delete_image(game->mlx, game->texts.move_nbr);
	game->texts.move_nbr = mlx_put_string(game->mlx,
			move_count, 70, game->rows * 64 + 10);
	free(move_count);
}

void	ft_print_collected_c(t_game *game)
{
	char	*collected_c;

	collected_c = ft_itoa(game->collected_c);
	mlx_delete_image(game->mlx, game->texts.collected_nbr);
	game->texts.collected_nbr = mlx_put_string(game->mlx,
			collected_c, 80, game->rows * 64 + 40);
	free(collected_c);
}

void	ft_game_over(t_game *game)
{
	mlx_image_t	*g_img;

	mlx_delete_image(game->mlx, game->texts.m1);
	mlx_delete_image(game->mlx, game->texts.m2);
	mlx_delete_image(game->mlx, game->texts.move_nbr);
	mlx_delete_image(game->mlx, game->texts.acorn_nbr);
	mlx_delete_image(game->mlx, game->texts.collected_nbr);
	mlx_delete_image(game->mlx, game->texts.ac);
	mlx_delete_image(game->mlx, game->texts.mo);
	ft_clean_old_assets(game);
	game->old_assets = game->assets;
	ft_clean_old_assets(game);
	game->state = STATE_GAMEOVER;
	ft_print_message(game);
	g_img = mlx_new_image(game->mlx, game->screen_x, game->screen_y);
	mlx_image_to_window(game->mlx,
		ft_asset_to_image(game->mlx, "./assets/gameover.xpm42"),
		game->screen_x / 2 - 272, game->screen_y / 2 - 160);
}
