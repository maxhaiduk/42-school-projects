#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 08:37:35 by mhaiduk           #+#    #+#              #
#    Updated: 2018/01/16 11:19:44 by mhaiduk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	 := libftprintf.a

# Output settings
DEFAULT	:=\033[0m
BOLD	:=\033[1m
GREEN	:=\033[0;32m
RED		:=\033[0;31m

# Compiler
CC		= gcc
FLAGS	= -Wall -Wextra -Werror


# Directories
SRC_DIR := ./srcs
OBJ_DIR := ./objs
INC_DIR := ./includes
LFT_DIR := ./libft

# Source files
SRC :=	ft_printf.c		        	\
		parser.c 					\
		checker.c 					\
		former.c 					\
		form_s.c 					\
		form_c.c 					\
		form_c_wide.c				\
		form_i_d.c					\
		form_xou.c					\
		form_p.c 					\
		compute_width.c				\
		compute_width_unsigned.c	\
		


# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
LFT := libft.a

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling libft.a...$(DEFAULT)"
	@make -C $(LFT_DIR) all --silent
	@echo "$(GREEN)Compiling $(NAME)...$(DEFAULT)"
	@ar rc $(NAME) $(OBJ) $(LFT_DIR)/objs/*.o
	@ranlib $(NAME) 
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@echo "$(RED)Cleaning libft o-files...$(DEFAULT)" 
	@make -C $(LFT_DIR) clean --silent
	@echo "$(RED)Cleaning ft_printf o-files...$(DEFAULT)" 
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

fclean: clean
	@echo "$(RED)Deleting libft.a ...$(DEFAULT)" 
	@rm -rf $(LFT_DIR)/$(LFT)
	@echo "$(RED)Deleting libftprintf.a ...$(DEFAULT)" 
	@rm -rf $(NAME)
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

re: fclean all



