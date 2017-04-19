#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysalata <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 12:17:27 by ysalata           #+#    #+#              #
#    Updated: 2017/04/13 18:40:39 by ysalata          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libftprintf.a

SRC =	ft_printf.c		\
		itoa_base.c		\
		for_specif.c	\
		lft_func.c		\
		parse_core.c	\
		small_shit.c	\
		to_write.c		\
		woodman.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar -cru $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c ft_printf.h
	gcc -Wall -Wextra -Werror -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

norm:
	norminette	./ft_*.c