/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:54:02 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/16 13:15:57 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	open_image(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}

mlx_image_t	*ft_asset_to_image(mlx_t *mlx, char *img_path)
{
	xpm_t			*xpm;
	mlx_image_t		*img;
	mlx_texture_t	texture;

	if (open_image(img_path) == FALSE)
		ft_error_message(E_IMAGE, 1);
	xpm = mlx_load_xpm42(img_path);
	if (!xpm)
		ft_printf("\nxpm is null\n");
	texture = xpm->texture;
	img = mlx_texture_to_image(mlx, &texture);
	if (!img)
		ft_printf("\nimg is null\n");
	mlx_delete_xpm42(xpm);
	return (img);
}

void	ft_image_to_window(t_game *game, int x, int y)
{
	if (y != 0 || x != 0)
		mlx_image_to_window(game->mlx, game->assets.floor, x * 64, y * 64);
	if (game->map_2d[y][x] == '1')
		mlx_image_to_window(game->mlx, game->assets.bush, x * 64, y * 64);
	else if (game->map_2d[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->assets.tree, x * 64, y * 64);
	else if (game->map_2d[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->assets.squirrel, x * 64, y * 64);
	else if (game->map_2d[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->assets.acorn, x * 64 + 16,
			y * 64 + 16);
	if (y == 0 && x == 0)
		mlx_image_to_window(game->mlx, game->assets.floor, x * 64, y * 64);
}

void	ft_put_image_in_map(t_game *game)
{
	int			x;
	int			y;

	y = 0;
	if (game->state == STATE_NULL)
	{
		ft_clean_old_assets(game);
		game->old_assets = game->assets;
		ft_load_assets(game);
		while (y < game->rows)
		{
			x = 0;
			while (x < game->columns)
			{
				ft_image_to_window(game, x, y);
				x++;
			}
			y++;
		}
		if (game->exit == TRUE)
			ft_game_won(game);
	}
	return ;
}

void	ft_game_won(t_game *game)
{
	ft_clean_old_assets(game);
	game->old_assets = game->assets;
	ft_clean_old_assets(game);
	game->state = STATE_SUCCESS;
	ft_print_message(game);
	mlx_close_window(game->mlx);
}
