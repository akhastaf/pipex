C = gcc
FLAGS = -Wall -Wextra -Werror
NAME = pipex
D = -g
SRC = ./srcs/*.c
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