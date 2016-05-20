# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssicard <ssicard@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:17:18 by ssicard           #+#    #+#              #
#    Updated: 2016/05/20 17:30:08 by tmanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = corewar

ASM = asm

all: $(COREWAR) $(ASM)

$(COREWAR):
	make -C corewar_dir/

$(ASM):
	make -C asm_dir/

clean:
	make -C corewar_dir/ clean
	make -C asm_dir/ clean

fclean:
	make -C corewar_dir/ fclean
	make -C asm_dir/ fclean

re: fclean all

.PHONY: all clean fclean re corewar asm
