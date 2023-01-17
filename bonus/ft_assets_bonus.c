/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:34:29 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/10 21:18:35 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_assets(t_game *game)
{
	game->assets.bush = ft_asset_to_image(game->mlx, "./assets/bush.xpm42");
	game->assets.floor = ft_asset_to_image(game->mlx, "./assets/floor.xpm42");
	if (game->turn_east == TRUE)
		game->assets.squirrel = ft_asset_to_image(game->mlx,
				"./assets/sqrl_e.xpm42");
	else if (game->turn_west == TRUE)
		game->assets.squirrel = ft_asset_to_image(game->mlx,
				"./assets/sqrl_w.xpm42");
	else
		game->assets.squirrel = ft_asset_to_image(game->mlx,
				"./assets/squirrel_front.xpm42");
	game->assets.acorn = ft_asset_to_image(game->mlx, "./assets/acorn.xpm42");
	if (game->c_count == 0)
		game->assets.tree = ft_asset_to_image(game->mlx, "./assets/hole.xpm42");
	else
		game->assets.tree = ft_asset_to_image(game->mlx, "./assets/tree.xpm42");
	game->assets.pigeon = ft_asset_to_image(game->mlx, "./assets/pi_e.xpm42");
	ft_animated_sprite(game);
}

/* frees the memory allocated to previously used assets */
void	ft_clean_old_assets(t_game *game)
{
	int	i;

	i = 0;
	mlx_delete_image(game->mlx, game->old_assets.bush);
	mlx_delete_image(game->mlx, game->old_assets.floor);
	mlx_delete_image(game->mlx, game->old_assets.squirrel);
	mlx_delete_image(game->mlx, game->old_assets.acorn);
	mlx_delete_image(game->mlx, game->old_assets.tree);
	mlx_delete_image(game->mlx, game->old_assets.pigeon);
}
