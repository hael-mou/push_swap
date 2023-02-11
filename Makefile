# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 10:56:58 by hael-mou          #+#    #+#              #
#    Updated: 2023/02/11 18:44:25 by hael-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CHECKER	= checker

# directories :
SRC_DIR		= src/
OBJ_DIR 	= obj/
LIBFT_DIR	= libft/
INCLUDE		= include/

# libraries :
LIBFT		= ft

# command :
CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# files	:
SRC_FILES		= push_swap_utils argument sort_utils rules_stack rules_stack_a\
				  rules_stack_b other_rules
PHSP_FILES		= push_swap sort_stack $(SRC_FILES)
CHECKER_FILES	= checker $(SRC_FILES)

SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(PHSP_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(PHSP_FILES)))

CHECKER_SRC	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(CHECKER_FILES)))
CHECKER_OBJ	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(CHECKER_FILES)))

# Colors :
DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;40m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# compiling Rules:
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)/push_swap.h | .cache
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@
	@echo "$(MAGENTA)# Push_swap Compiling :$(GREEN) $< $(DEF_COLOR)"

# role :
all: $(NAME)

$(NAME): $(OBJ)
	@make -sC $(LIBFT_DIR)
	@$(CC) $(FLAGS) $^ -I$(INCLUDE) -L$(LIBFT_DIR) -l$(LIBFT) -o $@
	@echo "$(YELLOW)# Program is created : Push_swap$(DEF_COLOR)"

bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJ)
	@make -sC $(LIBFT_DIR)
	@$(CC) $(FLAGS) $^ -I$(INCLUDE) -L$(LIBFT_DIR) -l$(LIBFT) -o $@
	@echo "$(CYAN)# Program is created : Checker$(DEF_COLOR)"

clean:
	@if [ -d $(LIBFT_DIR)/$(OBJ_DIR) ]; then\
		make clean -sC $(LIBFT_DIR);\
	fi
	@if [ -d $(OBJ_DIR) ]; then\
		$(RM) $(OBJ_DIR);\
		echo "$(RED) # Remove : \"\
		\b\b\bPush_swap  Object files cleaned!\" $(DEF_COLOR)";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		$(RM) $(NAME);\
		echo "$(GRAY) # Remove : \"\
		\b\b\b$(NAME) executable file cleaned!\" $(DEF_COLOR)";\
	fi
	@if [ -f $(CHECKER) ]; then\
		$(RM) $(CHECKER);\
		echo "$(GRAY) # Remove : \"\
		\b\b\b$(CHECKER) executable file cleaned!\" $(DEF_COLOR)";\
	fi
	@if [ -f $(LIBFT_DIR)/libft.a ]; then\
		make -sC $(LIBFT_DIR) fclean;\
	fi

re: fclean all

# cache dirs:
.cache: $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $@

.PHONY:	all bonus clean fclean re
