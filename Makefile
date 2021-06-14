# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 12:04:11 by sbensarg          #+#    #+#              #
#    Updated: 2021/06/14 13:34:48 by sbensarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
SRCS= ft_sort_3.c ft_sort_5.c ft_sort_100.c ft_sort_500.c ft_sort_utils.c push_swap.c push_swap_2.c push_swap_b.c ft_atoi.c ft_strncmp.c main.c 
BSRCS = main2.c push_swap.c push_swap_2.c push_swap_b.c ft_strncmp.c ft_atoi.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -D BUFFER_SIZE=10
FLAGS= -Wall -Wextra -Werror
CC=gcc
all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)


bonus:
	@$(CC) $(FLAGS) $(BSRCS) -o checker

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f checker
re: fclean all