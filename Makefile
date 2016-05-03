# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssicard <ssicard@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:17:18 by ssicard           #+#    #+#              #
#    Updated: 2016/05/03 14:14:01 by ssicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEAD = libft/

LIB = libft/libft.a

SRC = asm.c \
	  sources/get_s_file.c \
	  sources/ft_print_champ.c \
	  sources/ft_add_label.c \
	  sources/structure.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	make -C libft/ fclean
	make -C libft/

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test: all
	./asm goinfre/champions/examples/helltrain.s
	hexdump -vC goinfre/champions/examples/helltrain.s.cor
.PHONY: all clean fclean re
