/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:00:44 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/17 12:15:19 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define E_MALLOC "Error with malloc.\n"
# define E_ARG "Please give me one map, Mam!\n"
# define E_FILE "I cannot open the file, sorry!\n"
# define E_CHARACTER "The map contains at least one invalid character, Mam!\n"
# define E_CHARS "The map does not contain the required characters. Meh!!\n"
# define E_INVALIDMAP "Give me a valid map, Mam! I wanna rectangles!\n"
# define E_WALLS "This map is not surrounded by walls! Gimme a fortress!\n"
# define E_PATH "Hey,that path is not valid !I cannot jump walls.\n"
# define E_FORMAT "Format not allowed.\n"
# define E_EMPTYFILE "Yo! Nothing to read here.\n"
# define E_IMAGE "There is something wrong with the image you want to put.\n"
# define E_MAX "You're kind of exagerating here.\n"

typedef struct s_assets
{
	mlx_image_t		*bush;
	mlx_image_t		*squirrel;
	mlx_image_t		*acorn;
	mlx_image_t		*tree;
	mlx_image_t		*floor;
	mlx_image_t		*pigeon;
}					t_assets;

typedef struct s_texts
{
	mlx_image_t		*acorn_nbr;
	mlx_image_t		*move_nbr;
	mlx_image_t		*collected_nbr;
	mlx_image_t		*m1;
	mlx_image_t		*m2;
	mlx_image_t		*ac;
	mlx_image_t		*mo;
}					t_texts;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map_2d;
	int				rows;
	int				columns;
	t_assets		assets;
	t_assets		old_assets;
	t_texts			texts;
	mlx_t			*window;
	int				move_count;
	int				m_flag;
	int				c_flag;
	int				c_count;
	int				state;
	bool			exit;
	int				screen_x;
	int				screen_y;
	bool			turn_east;
	bool			turn_west;
	int				collected_c;
	int				loop;
	int				pigeon;
	bool			gameover;
	bool			pi_right;
	bool			pi_left;
	bool			exit_flag;
}					t_game;

typedef enum e_id
{
	ID_FLOOR = 0,
	ID_P = 1,
	ID_ACORN = 2,
	ID_BUSH = 3,
	ID_TREE = 4,
	ID_PIGEON = 5,
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
void				ft_floodfill(t_game *game, int x, int y);
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
int					ft_check_for_cex(t_game *game, char c);
void				ft_print_message(t_game *game);
int					ft_count_c(t_game *game);
void				ft_print_moves(t_game *game);
void				ft_print_moves_and_acorns(t_game *game);
void				ft_print_collected_c(t_game *game);
void				ft_initialize_variables(t_game *game);
void				ft_game_won(t_game *game);
void				ft_game_over(t_game *game);
void				ft_animated_sprite(t_game *game);
void				ft_enemy_moves(t_game *game);
bool				ft_move_if_poss(t_game *game, int x, int y);
void				ft_espace(t_game *game);
void				ft_validate_length(char *str_map);

#endif