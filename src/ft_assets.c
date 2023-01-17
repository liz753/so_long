/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:53:59 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 15:28:49 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_assets(t_game *game)
{
	game->assets.bush = ft_asset_to_image(game->mlx, "./assets/bush.xpm42");
	game->assets.floor = ft_asset_to_image(game->mlx, "./assets/floor.xpm42");
	game->assets.squirrel = ft_asset_to_image(game->mlx,
			"./assets/sqrl_e.xpm42");
	game->assets.acorn = ft_asset_to_image(game->mlx, "./assets/acorn.xpm42");
	if (game->c_count == 0)
		game->assets.tree = ft_asset_to_image(game->mlx, "./assets/hole.xpm42");
	else
		game->assets.tree = ft_asset_to_image(game->mlx, "./assets/tree.xpm42");
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
}
