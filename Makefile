# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woberon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 16:22:13 by woberon           #+#    #+#              #
#    Updated: 2021/12/18 19:08:22 by woberon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INC_DIR = ./includes/
SRCS = ./srcs/ft_printf.c ./srcs/ft_put_addr.c \
	./srcs/ft_put_hex.c \
		./srcs/ft_putchar_fd.c ./srcs/ft_putnbr_fd.c ./srcs/ft_putstr_fd.c
HEADER = ./includes/ft_printf.h
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	gcc -Wall -Wextra -Werror -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re