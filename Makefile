# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otangkab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:39:06 by otangkab          #+#    #+#              #
#    Updated: 2023/01/23 14:36:15 by otangkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long

CC	:= gcc
CFLAGS	:= -Wall -Wextra -Werror

LIB_DIR	:= ./lib

SRCS	:= so_long.c lib/gnl/get_next_line.c lib/gnl/get_next_line_utils.c \
	check_file.c flood_fill.c so_long_utils.c render.c check_pce.c \
	ft_mlx_hook.c

OBJS	:= $(SRCS:.c=.o)

GNL_DIR	:= $(LIB_DIR)/gnl
GNL	:= $(wildcard (GNL_DIR)/*.o)
LIBFT_DIR	:= $(LIB_DIR)/Libft
LIBFT	:= $(LIBFT_DIR)/libft.a

MLX_DIR	:= ./mlx
MINILIBX	:= $(MLX_DIR)/libmlx.a

FRAME_W	:= -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@



all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -I$(LIBFT_DIR) -I$(GNL_DIR)\
		-L$(LIBFT_DIR) -Lmlx -lft -lmlx $(FRAME_W) -o $(NAME)

$(MINILIBX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean: 
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(GNL_DIR)/*.o
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
