# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshereme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 22:29:42 by dshereme          #+#    #+#              #
#    Updated: 2019/02/06 22:29:44 by dshereme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	:=	fillit

CC		:=	gcc

FLAGS	:=	-Wall -Werror -Wextra

SRC_DIR	=	./src/
OBJ_DIR	=	./obj/
INC_DIR	=	./inc/
LIB_DIR	=	./lib/

INCLUDES = ./inc/

SRC		:=	main.c\
			put_figure.c\
			to_coordinate_tetrimino.c\
			map_creator.c\
			reader_tetrimino.c\
			list_function.c\
			norme_tetrimino.c\

OBJ		:=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)