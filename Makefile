# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 17:37:07 by scosta-j          #+#    #+#              #
#    Updated: 2023/08/22 20:00:38 by scosta-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra 

EXTRAFLAGS = -g3 -fsanitize=address #extra flags to find leaks

RM = rm -rf

SRC = algorithm.c list_aux.c list_checker.c main.c operations.c \
stack_operations.c utils.c sort.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o push_swap

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all