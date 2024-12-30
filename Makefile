# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 10:26:56 by kokamoto          #+#    #+#              #
#    Updated: 2024/12/30 12:30:25 by kokamoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRCS = main.c \
	error.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	radix_sort.c \
	chunk_sort.c

LIBFT_SRCS = libft/ft_atoi.c \
	libft/ft_lstnew.c \
	libft/ft_lstlast.c \
	libft/ft_lstclear.c \
	libft/ft_lstsize.c \
	libft/ft_lstadd_front.c

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_OBJS) -o $(NAME)

%.o: %.c push_swap.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
