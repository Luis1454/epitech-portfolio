##
## EPITECH PROJECT, 2022
## B-CPE-200-LIL-2-1-corewar-mathis.zucchero
## File description:
## Makefile
##

SRC =	src/main.c 									\
		src/command/add.c 							\
		src/command/aff.c 							\
		src/command/and.c 							\
		src/command/and2.c 							\
		src/command/and3.c 							\
		src/command/fork.c 							\
		src/command/ld.c 							\
		src/command/ldi.c 							\
		src/command/lfork.c 						\
		src/command/live.c 							\
		src/command/lld.c 							\
		src/command/lldi.c 							\
		src/command/or.c 							\
		src/command/st.c 							\
		src/command/sti.c 							\
		src/command/sti2.c 							\
		src/command/sub.c 							\
		src/command/xor.c 							\
		src/command/zjmp.c 							\
		src/command/find_cmd.c 						\
		src/command/find_label.c 					\
		src/command/write_command.c 				\
		src/command/search_type.c 					\
		src/compiler/compiler.c 					\
		src/compiler/open_file.c 					\
		src/error_handling/test_file.c 				\
		src/error_handling/entries_error.c			\
		src/fill_champion/test_content.c 			\
		src/fill_champion/fill_champ.c 				\
		src/fill_champion/fill_comment.c 			\
		src/fill_champion/fill_header.c 			\

NAME = asm

TRYHARDER = -Werror
FLAGS = -Wall -Wextra
INCLUDE = -I include/
LIB = -L lib -lmy
DEBUG_FLAGS = -g3

GCC = gcc -o $(NAME) $(SRC) $(FLAGS) $(INCLUDE) $(LIB)
GCC_DEBUG = gcc -o $(NAME) $(SRC) $(FLAGS) $(INCLUDE) $(LIB) $(DEBUG_FLAGS)

all: compile_lib $(NAME)

compile_lib:
	@ cd ./lib && make re

$(NAME):
	$(GCC)

clean:
	rm -f $(NAME)

fclean: clean
	@ cd ./lib && make fclean

re: fclean all

debug:
	$(GCC_DEBUG)
