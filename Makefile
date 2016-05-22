# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:17:18 by ssicard           #+#    #+#              #
#    Updated: 2016/05/22 23:03:50 by eozdek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = corewar

ASM = asm

all: $(COREWAR) $(ASM)

$(COREWAR):
	@make -C corewar_dir/
	@echo "   ___ ___  _ __ _____      ____ _ _ __ "
	@echo "  / __/ _ \| '__/ _ \ \ /\ / / _ | '__|"
	@echo " | (_| (_) | | |  __/\ V  V / (_| | |"
	@echo "  \___\___/|_|  \___| \_/\_/ \__,_|_|"


$(ASM):
	@make -C asm_dir/

clean:
	make -C corewar_dir/ clean
	make -C asm_dir/ clean

fclean:
	make -C corewar_dir/ fclean
	make -C asm_dir/ fclean

re: fclean all

.PHONY: all clean fclean re corewar asm
