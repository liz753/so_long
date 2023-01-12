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
	mlx_image_t	**assets;

	assets = ft_calloc(5, sizeof(mlx_image_t *));
	assets[ID_FLOOR] = ft_asset_to_image(game->mlx, "./assets/floor.xpm42");
	assets[ID_BUSH] = ft_asset_to_image(game->mlx, "./assets/bush.xpm42");
	assets[ID_P_E] = ft_asset_to_image(game->mlx, "./assets/sqrl_e.xpm42");
	assets[ID_ACORN] = ft_asset_to_image(game->mlx, "./assets/acorn.xpm42");
	if (game->c_count == 0)
		assets[ID_TREE] = ft_asset_to_image(game->mlx, "./assets/hole.xpm42");
	else
		assets[ID_TREE] = ft_asset_to_image(game->mlx, "./assets/tree.xpm42");
	game->assets = assets;
}

/* frees the memory allocated to previously used assets */
void	ft_clean_old_assets(t_game *game)
{
	int	i;

	i = 0;
	if (game->old_assets == NULL)
		return ;
	while (i < 5)
	{
		mlx_delete_image(game->mlx, game->old_assets[i]);
		i++;
	}
	free(game->old_assets);
	game->old_assets = NULL;
}
