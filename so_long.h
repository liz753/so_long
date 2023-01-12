/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:54:37 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 14:53:22 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define E_MALLOC "Error with malloc"
# define E_ARG "Please give me one map, Mam!\n"
# define E_FILE "I cannot open the file, sorry!\n"
# define E_CHARACTER "The map contains at least one invalid character, Mam!\n"
# define E_CHARS "The map does not contain the required characters. Meh!!\n"
# define E_INVALIDMAP "Give me a valid map, Mam! I wanna rectangles!\n"
# define E_WALLS "This map is not surrounded by walls! Gimme a fortress!\n"
# define E_PATH "Hey,that path is not valid !I cannot jump walls.\n "
# define E_FORMAT "Format not allowed"
# define E_EMPTYFILE "Yo! Nothing to read here."
# define E_IMAGE "There is something wrong with the image you want to put."

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map_2d;
	int				rows;
	int				columns;
	mlx_image_t		**assets;
	mlx_image_t		**old_assets;
	mlx_t			*window;
	int				move_count;
	int				m_flag;
	int				c_flag;
	int				c_count;
	int				state;
	bool			exit;
	int				screen_x;
	int				screen_y;
}					t_game;

typedef enum e_id
{
	ID_FLOOR = 0,
	ID_P_E = 1,
	ID_ACORN = 2,
	ID_BUSH = 3,
	ID_TREE = 4,
}					t_id;

typedef enum e_state
{
	STATE_NULL = 0,
	STATE_SUCCESS = 1,
	STATE_CLOSING = 2,
	STATE_GAMEOVER = 3,
}					t_state;

char				*ft_read_map(char *map);
void				ft_error_message(char *str, int error);
void				ft_validate_map(char *str_map, t_game *game);
void				ft_validate_characters(char *str_map);
void				ft_amount_of_characters(char *str_map, t_game *game);
void				ft_validate_line_length(char *str_map);
char				**ft_string_to_2d(char *str_map);
int					ft_count_strings(char **s);
void				ft_validate_2dmap(t_game *game);
void				ft_validate_path(t_game *game);
void				ft_floodfill(char **map_2d, int x, int y, int *count_c);
void				ft_restore(char **map_2d);
void				ft_validate_file(char *map_path);
bool				open_image(char *str);
int					ft_put_image_in_map(t_game *game);
mlx_image_t			*ft_asset_to_image(mlx_t *mlx, char *img_path);
void				ft_key_hook(mlx_key_data_t keydata, void *param);
void				ft_move_up(t_game *game);
void				ft_move_down(t_game *game);
void				ft_move_right(t_game *game);
void				ft_move_left(t_game *game);
void				ft_load_assets(t_game *game);
char				**ft_2dmap_copy(t_game *game);
void				ft_free_map_2d(char **map_2d);
void				ft_clean_old_assets(t_game *game);
int					ft_check_for_c_and_e(t_game *game, char c);
void				ft_print_message(t_game *game);
void				ft_initialize_variables(t_game *game);
void				ft_game_won(t_game *game);

#endif