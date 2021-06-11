# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 17:43:38 by akhastaf          #+#    #+#              #
#    Updated: 2021/06/11 16:00:01 by akhastaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = pipex
NAME_BONUS = pipex_bonus

D = -g

SRC = ./srcs/execute.c \
		./srcs/ft_delete_arg.c \
		./srcs/ft_lst_size.c \
		./srcs/ft_putendl_fd.c \
		./srcs/ft_split.c \
		./srcs/ft_strappend.c \
		./srcs/ft_strdup.c \
		./srcs/ft_strjoin.c \
		./srcs/ft_strlen.c \
		./srcs/ft_strncmp.c \
		./srcs/ft_substr.c \
		./srcs/get_cmds.c \
		./srcs/get_path.c \
		./srcs/linkedlist.c \
		./srcs/pipe.c \
		./srcs/check_args.c \
		./srcs/ft_is_empty.c \
		./srcs/wait_execute.c

SRC_BONUS = ./srcs/ft_delete_arg.c \
			./srcs/ft_lst_size.c \
			./srcs/ft_putendl_fd.c \
			./srcs/ft_split.c \
			./srcs/ft_strappend.c \
			./srcs/ft_strdup.c \
			./srcs/ft_strjoin.c \
			./srcs/ft_strlen.c \
			./srcs/ft_strncmp.c \
			./srcs/ft_substr.c \
			./srcs/get_path.c \
			./srcs/linkedlist.c \
			./srcs/pipe.c \
			./srcs/check_args.c \
			./srcs/ft_is_empty.c \
			./srcs/wait_execute.c \
			./srcs/get_cmds_bonus.c \
			./srcs/ft_strchr_bonus.c \
			./srcs/ft_strndup_bonus.c \
			./srcs/gnl_bonus.c \
			./srcs/get_input_bonus.c \
			./srcs/execute_bonus.c \
			./srcs/ft_putstr_fd_bonus.c \
			./srcs/ft_strcmp_bonus.c

OBJ = pipex

all: $(NAME)

$(NAME):
	@$(C) -o $(NAME) main.c $(SRC)

bonus:
	@$(C) -o $(NAME_BONUS) main_bonus.c $(SRC_BONUS)
	
debug:
	@$(C) -g -o $(NAME) main.c $(SRC) -fsanitize=address 

clean:
	@rm -f $(NAME) $(NAME_BONUS)

fclean: clean
		@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: re fclean clean all
