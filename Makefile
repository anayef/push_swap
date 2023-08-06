# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anayef <anayef@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 21:13:48 by anayef            #+#    #+#              #
#    Updated: 2023/08/06 08:09:06 by anayef           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap
CC =			gcc
CFLAGS =		-Wall -Wextra -Werror -g
HDRS =			push_swap.h
SRCS =			main.c input_handler.c find.c do_a.c do_b.c sorting.c sort_small.c stack_creator.c utils.c utils2.c
OBJS =			$(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
