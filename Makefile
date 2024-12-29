# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 10:26:56 by kokamoto          #+#    #+#              #
#    Updated: 2024/12/29 12:40:14 by kokamoto         ###   ########.fr        #
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
	quick_sort.c \
	get_median.c

LIBFT_SRCS = libft/ft_hexlen.c \
	libft/ft_atoi.c \
	libft/ft_putstr_fd.c \
	libft/ft_putint_fd.c \
	libft/ft_put_uint_hex_fd.c \
	libft/ft_lstnew.c \
	libft/ft_strlen.c \
	libft/ft_lstlast.c \
	libft/ft_lstclear.c \
	libft/ft_lstsize.c \
	libft/ft_printf.c \
	libft/ft_putpointer_fd.c \
	libft/ft_lstadd_front.c \
	libft/ft_putunsignedint_fd.c \
	libft/ft_putchar_fd.c \
	libft/ft_numlen.c \
	libft/ft_strchr_n.c 

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