# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:17:18 by ssicard           #+#    #+#              #
#    Updated: 2016/05/19 19:59:44 by eozdek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEAD = ../libft/

LIB = ../libft/libft.a

SDL_TTF = -I ../../SDL/SDL2_ttf.framework/Headers

SDL_IMAGE = -I ../../SDL/SDL2_image.framework/Headers

SDL2 = -I ../../SDL/SDL2.framework/Headers

FRAMEWORK = -F ../../SDL -framework SDL2_ttf -framework SDL2 -framework SDL2_image

SRC =	sources/ft_check_champion.c sources/ft_stock_champion.c \
		sources/ft_memrev.c sources/ft_print_champion.c \
		sources/ft_handle.c \
		sources/main.c \
		sources/reverse_octet.c \
		sources/cpu.c sources/ocp.c sources/stock_types.c \
		sources/init.c \
		sources/get_mem.c \
		sources/put_mem.c \
		sources/ft_load.c \
		sources/ft_jump.c \
		sources/ft_kill_proc.c \
		sources/ft_live.c \
		sources/ft_store.c \
		sources/ft_basic_functions.c \
		sources/ft_aff.c\
		sources/ft_fetch_next.c \
		sources/init_2.c \
		sources/ft_manage.c \
		sources/check_cycle.c \
		sources/ft_wait.c \
		sources/ft_print_operations.c \
		sources/ft_print_header.c \
		sources/ft_display_arena.c \
		sources/ft_visu.c \
# sources/testdav.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	make -C ../libft/ fclean
	make -C ../libft/

$(NAME): $(LIB) $(OBJ)
	# $(CC) $(FLAGS) -o $@ $(OBJ) $(LIB)
	$(CC) $(SDL2) $(SDL_TTF) $(SDL_IMAGE) $(FRAMEWORK) $(FLAGS) -o $@ $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<
clean:
	/bin/rm -f $(OBJ)
	make -C ../libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ../libft/ fclean

re: fclean all

.PHONY: all clean fclean re
