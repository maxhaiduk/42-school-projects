# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaiduk <mhaiduk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 08:37:35 by mhaiduk           #+#    #+#              #
#    Updated: 2018/03/06 18:16:36 by mhaiduk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

# Output settings
DEFAULT	:=\033[0m
BOLD	:=\033[1m
GREEN	:=\033[0;32m
RED		:=\033[0;31m

# Compiler
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g

# Directories
SRC_DIR := ./sources
OBJ_DIR := ./objects
INC_DIR := ./includes ./libft/includes
LFT_DIR := ./libft

# Source files for push_swap
SRC :=	push_swap.c 		\
		reader.c			\
		input_error.c		\
		helpers.c			\
		ps_tools.c			\
		ps_tools_wrap1.c	\
		ps_tools_wrap2.c	\
		ps_tools_wrap3.c	\
		sorter.c 			\
		compute_a_stack.c	\
		compute_b_stack.c 	\
		mediana.c    		\
		sort_group_a.c 		\
		sort_group_a_last.c \
		sort_group_b.c 		\
		printer.c

# Object files for push_swap
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Source files for checker
SRC2 := checker.c			\
		reader.c			\
		input_error.c		\
		helpers.c			\
		ps_tools.c			\
		ps_tools_wrap1.c	\
		ps_tools_wrap2.c	\
		ps_tools_wrap3.c	\

# Object files for checker
OBJ2 := $(addprefix $(OBJ_DIR)/, $(SRC2:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
LFT := libft.a

.PHONY = all clean fclean re

all: $(NAME) $(NAME2)

$(NAME): $(OBJ) $(LFT)
	@echo "$(GREEN)Compiling $(NAME)...$(DEFAULT)"
	@$(CC) $(FLAGS) $(OBJ) $(LFT_DIR)/$(LFT) $(INC) -o $(NAME)
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

$(NAME2): $(OBJ2) $(LFT) 
	@echo "$(GREEN)Compiling $(NAME2)...$(DEFAULT)"
	@$(CC) $(FLAGS) $(OBJ2) $(LFT_DIR)/$(LFT) $(INC) -o $(NAME2)
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

$(LFT):
	@echo "$(GREEN)Compiling libft...$(DEFAULT)"
	@make -C $(LFT_DIR) all --silent

clean:
	@echo "$(RED)Cleaning libft o-files...$(DEFAULT)" 
	@make -C $(LFT_DIR) clean --silent
	@echo "$(RED)Cleaning $(NAME) o-files...$(DEFAULT)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

fclean: clean
	@echo "$(RED)Deleting libft.a...$(DEFAULT)" 
	@rm -rf $(LFT_DIR)/$(LFT)
	@echo "$(RED)Deleting $(NAME)...$(DEFAULT)" 
	@rm -rf $(NAME)
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

re: fclean all



