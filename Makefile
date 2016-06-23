# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 16:12:54 by fdel-car          #+#    #+#              #
#    Updated: 2016/06/23 15:06:53 by fdel-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCS = main.c ft_draw.c ft_shortcut.c ft_map.c ft_move_rot.c ft_color.c \
	   ft_raycast.c ft_skybox.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@cd libft && make re && cd ..
	@echo "\033[1;31mCompiling Project"
	@echo "\033[1A\033[0;39m"
	@gcc $(CFLAGS) -o $@ $(OBJS) ./libft/libft.a $(MLXFLAGS)

%.o: %.c
	@echo "\033[1A\033[1;35mCreating Objects of the Project"
	@echo "\033[1A\033[0;39m"
	@gcc $(CFLAGS) -c $^ -I./libft/includes

clean:
	@cd libft && make clean && cd ..
	@rm -rf $(OBJS)
fclean: clean
	@echo "\033[1;37mFull Cleaning"
	@echo "\033[1A\033[0;39m"
	@rm -rf $(NAME)

re: fclean
	@make all

.PHONY: all clean fclean re
