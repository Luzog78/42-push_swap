# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 07:59:02 by ysabik            #+#    #+#              #
#    Updated: 2023/11/20 20:19:57 by ysabik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc
CFLAGS				= -Werror -Wall -Wextra -g
NAME				= push_swap
BONUS_NAME			= checker
SRC_FILES			= \
	ft_free_pos.c \
	ft_calc_path.c \
	ft_calc_path_ra_rrb.c \
	ft_calc_path_rra_rb.c \
	ft_calc_path_rr.c \
	ft_calc_path_rrr.c \
	ft_create_moves.c \
	ft_create_pos.c \
	ft_create_stack.c \
	ft_custom_split.c \
	ft_exec_move.c \
	ft_exec_move_cheapest.c \
	ft_free_moves.c \
	ft_stack_add_front.c \
	ft_free_split.c \
	ft_free_stack.c \
	ft_moves_add_back.c \
	ft_moves_add_front.c \
	ft_moves_get_last.c \
	ft_moves_size.c \
	ft_parse.c \
	ft_print_solution.c \
	ft_rotate_to_desc.c \
	ft_small_sort_algo.c \
	ft_stack_add_back.c \
	ft_stack_get_last.c \
	ft_stack_index_of.c \
	ft_stack_min.c \
	ft_stack_max.c \
	ft_stack_pop_back.c \
	ft_stack_size.c \
	ft_update_paths.c \
	ft_update_targets.c
MANDATORY_SRC_FILES	= push_swap.c
BONUS_SRC_FILES		= ft_read.c checker.c
OBJ_FILES			= $(SRC_FILES:.c=.o)
MANDATORY_OBJ_FILES	= $(MANDATORY_SRC_FILES:.c=.o)
BONUS_OBJ_FILES		= $(BONUS_SRC_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILES) $(MANDATORY_OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(MANDATORY_OBJ_FILES)

bonus : $(OBJ_FILES) $(BONUS_OBJ_FILES)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_FILES) $(BONUS_OBJ_FILES)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean :
	rm -rf $(OBJ_FILES) $(MANDATORY_OBJ_FILES) $(BONUS_OBJ_FILES)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : all bonus clean fclean re
