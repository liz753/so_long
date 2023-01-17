# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 12:54:41 by lfrank            #+#    #+#              #
#    Updated: 2023/01/16 16:27:44 by lfrank           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

CC		= gcc

CFLAGS	=	-Wall -Werror -Wextra 

LIB		= ./MLX42/libmlx42.a

RM		= rm -f 

MAKE_MLX = cd ./MLX42/ && make

SRC = ./src/main.c ./src/ft_read_map.c ./src/ft_validate_map.c ./src/ft_error.c ./src/ft_string_to_2d.c \
		./src/ft_validate_2dmap.c ./libs/libft/ft_split.c ./libs/printf/ft_printf.c ./libs/printf/ft_printchar.c \
		./libs/printf/ft_printstr.c ./libs/printf/ft_printnbr.c  ./libs/printf/ft_printhex.c ./libs/printf/ft_digitlen.c \
		./libs/printf/ft_printpointer.c ./libs/printf/ft_printnbr_u.c ./libs/libft/ft_strlen.c ./src/ft_validate_path.c \
		./src/ft_put_image_in_map.c ./src/ft_key_hook.c ./src/ft_move.c ./libs/libft/ft_bzero.c \
		./src/ft_free_map_2d.c ./src/ft_print_message.c ./src/ft_assets.c 

SRC_B =  ./bonus/main_bonus.c ./bonus/ft_read_map_bonus.c ./bonus/ft_validate_map_bonus.c ./bonus/ft_error_bonus.c \
		./bonus/ft_string_to_2d_bonus.c ./bonus/ft_validate_2dmap_bonus.c ./libs/libft/ft_split.c ./libs/printf/ft_printf.c \
		./libs/printf/ft_printstr.c ./libs/printf/ft_printnbr.c ./libs/printf/ft_printhex.c ./libs/printf/ft_digitlen.c \
		./libs/printf/ft_printpointer.c ./libs/printf/ft_printnbr_u.c ./libs/libft/ft_strlen.c ./bonus/ft_validate_path_bonus.c \
		./bonus/ft_put_image_in_map_bonus.c ./bonus/ft_key_hook_bonus.c ./bonus/ft_move_bonus.c ./libs/libft/ft_strchr.c  \
		./bonus/ft_free_map_2d_bonus.c ./bonus/ft_print_message_bonus.c ./libs/printf/ft_printchar.c \
		./bonus/ft_animated_sprite_bonus.c ./libs/libft/ft_bzero.c ./libs/libft/ft_itoa.c ./bonus/ft_assets_bonus.c \
		./bonus/ft_status_in_window_bonus.c 

OBJS = ${SRC:%.c=%.o}

OBJS_B = ${SRC_B:%.c=%.o} 

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(MAKE_MLX)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME) -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/" -I ./MLX42/include

$(BONUS) : $(OBJS_B)
	$(MAKE_MLX)
	$(CC) $(OBJS_B) $(LIB) $(CFLAGS) -o $(BONUS) -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/" -I ./MLX42/include

clean	: 
	$(RM) $(OBJS) $(OBJS_B)

fclean	: clean
	$(RM) $(NAME) $(BONUS)

bonus	: $(BONUS)

re		: fclean all