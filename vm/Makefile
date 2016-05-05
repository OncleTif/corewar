# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:17:18 by ssicard           #+#    #+#              #
#    Updated: 2016/05/05 09:25:30 by ssicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEAD = ../libft/

LIB = ../libft/libft.a

SRC =	sources/ft_check_champion.c sources/ft_stock_champion.c \
		sources/ft_memrev.c sources/ft_print_champion.c \
		sources/ft_handle.c \
		sources/main.c \
		sources/reverse_octet.c \
		sources/cpu.c sources/ocp.c sources/stock_types.c \
		sources/init.c
# sources/testdav.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	make -C ../libft/ fclean
	make -C ../libft/

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C ../libft/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
