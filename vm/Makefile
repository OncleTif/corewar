# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoly <djoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:17:18 by ssicard           #+#    #+#              #
#    Updated: 2016/04/28 17:25:20 by djoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEAD = ../libft/

LIB = ../libft/libft.a

SRC = sources/testdav.c \
		sources/reverse_octet.c sources/vm_init.c \


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
