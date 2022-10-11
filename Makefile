# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 12:16:17 by hepiment          #+#    #+#              #
#    Updated: 2022/10/11 15:50:03 by hepiment         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
INCLUDE = -I ./include/
CFLAGS = -g -Wall -Wextra -Werror


RM = rm -rf

PATH_SRC = ./src/

PATH_OBJS = ./objs/

SRC =	$(PATH_SRC)swap.c \
		$(PATH_SRC)push.c \
		$(PATH_SRC)rotate.c \
		$(PATH_SRC)reverse_rotate.c \
		$(PATH_SRC)main.c \
		$(PATH_SRC)init_stack.c \
		$(PATH_SRC)is_sorted.c \
		$(PATH_SRC)push_swap.c \
		$(PATH_SRC)get_values.c \
		$(PATH_SRC)error.c \
		$(PATH_SRC)fill_stack.c \
		$(PATH_SRC)validate.c \
		$(PATH_SRC)create_stack.c \
		$(PATH_SRC)algo.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -Llibft -lft -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re