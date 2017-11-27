#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 10:55:46 by mhaiduk           #+#    #+#              #
#    Updated: 2017/11/27 12:26:40 by mhaiduk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# iEdit: main.o Editor.o TextLine.o
#       gcc  $^  -o $@              ---->>>   main.o Editor.o TextLine.o -o iEdit
# $^, $@ автоматические переменные
# $^ - означает список зависимостей (main.o Editor.o TextLine.o)
# $@ - означает имя цели (iEdit)

# % - любое кол-во произвольных символов

NAME	:= fillit

# Directories
SRC_DIR	:= ./src
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./libft

CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror

# Source and objects files
SRC		:= main.c
OBJ		:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Library file
L_FT	:= $(LIB_DIR)/libft.a

# .PHONY - описывает имена абстрактных правил
# для избежания совпадений имен правил с файлами на диске 
.PHONY: all clean fclean re

#print:
#	@echo $(OBJ)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ $(L_FT) -o $(NAME)


$(OBJ): $(SRC_DIR)/$(SRC)
	$(CC) $(FLAGS) -c  $^ -o $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all