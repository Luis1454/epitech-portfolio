##
## EPITECH PROJECT, 2023
## B-PSU-400-LIL-4-1-strace-alexis.salaun
## File description:
## Makefile
##

SRC	=	main.c	       \
		src/error.c     \
		src/parser.c     \
		src/process.c     \
		src/start_tracer.c \
		src/display_regs.c  \
		src/signal_manager.c \
		src/syscall_manager.c \
		src/trace_programme.c  \
		src/fonction_manager.c  \
		src/get_fonction_name.c

OBJ = 	$(SRC:.c=.o)

NAME =	ftrace

CFLAGS	= -lelf -Wall -Wextra -g

NUM_SRC := $(words $(SRC))

counter := 0

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;01m\nFtrace compiled\033[;0m"
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

%.o: %.c
	@$(eval counter=$(shell echo $$(($(counter) + 1))))
	@echo -n "\033[0K\rCompiling $@ [\033[34m$(counter)/$(NUM_SRC)\033[0m]\
	(\033[34m$(shell echo $$(($(counter) * 100 / $(NUM_SRC))))%\033[0m)"
	@gcc -c $< -o $@ $(CFLAGS)

clean:
	@echo "\033[31;01mFtrace clean\033[;0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
