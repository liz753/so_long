/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:54:27 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/16 13:09:28 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(void *param)
{
	t_game	*game;

	game = param;
	ft_put_image_in_map(game);
}

void	ft_initialize_variables(t_game *game)
{
	game->move_count = 0;
	game->state = STATE_NULL;
	game->exit_flag = FALSE;
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*str_map;

	if (argc != 2)
		ft_error_message(E_ARG, 1);
	str_map = ft_read_map(argv[1]);
	ft_initialize_variables(&game);
	ft_validate_map(str_map, &game);
	game.map_2d = ft_string_to_2d(str_map);
	free(str_map);
	ft_validate_2dmap(&game);
	ft_validate_path(&game);
	game.screen_x = game.columns * 64;
	game.screen_y = game.rows * 64;
	game.mlx = mlx_init(game.screen_x, game.screen_y, "MLX42", FALSE);
	if (!game.mlx)
		exit(EXIT_FAILURE);
	ft_load_assets(&game);
	mlx_loop_hook(game.mlx, &hook, &game);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	mlx_loop(game.mlx);
	ft_free_map_2d(game.map_2d);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
