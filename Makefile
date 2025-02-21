# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuthayak <tuthayak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 11:17:20 by tuthayak          #+#    #+#              #
#    Updated: 2025/02/21 11:17:20 by tuthayak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lXrender -lXrandr -lXcursor -lm -lpthread
LIBFTPRINTF		= libftprintf/libftprintf.a
INCLUDES	= -Iinc -Ilibftprintf/inc
SRC_DIR		= src
OBJ_DIR		= obj
LIBFTPRINTF_DIR	= libftprintf

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/fractol_utils.c \
			  $(SRC_DIR)/render.c \
			  $(SRC_DIR)/mandelbrot.c \
			  $(SRC_DIR)/julia.c \
			  $(SRC_DIR)/hooks.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFTPRINTF):
	@make -C $(LIBFTPRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFTPRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
