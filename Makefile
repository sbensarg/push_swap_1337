# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 12:04:11 by sbensarg          #+#    #+#              #
#    Updated: 2021/06/19 12:32:07 by sbensarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
SRCS= ft_sort_3.c ft_sort_5.c ft_sort_100.c ft_sort_500.c ft_sort_utils.c push_swap.c push_swap_2.c push_swap_b.c ft_get_nbr.c main.c 
FLAGS= -Wall -Wextra -Werror
CC=gcc
all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@$(CC) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)
re: fclean all