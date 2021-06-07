# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhastaf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 17:43:38 by akhastaf          #+#    #+#              #
#    Updated: 2021/06/07 17:43:40 by akhastaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = pipex

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
		./srcs/pipe.c

OBJ = pipex

all: $(NAME)

$(NAME):
	@$(C) -o $(NAME) main.c $(SRC)

bonus:
	@$(C) -o $(NAME) main_bonus.c $(SRC)
	
debug:
	@$(C) -g -o $(NAME) main.c $(SRC) -fsanitize=address 

clean:
	@rm -f $(NAME)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
