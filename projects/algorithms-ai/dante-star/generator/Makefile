##
## EPITECH PROJECT, 2021
## makefile
## File description:
## Makefile
##

SRC	= 	my_generator.c 	\
		len.c 			\

OBJ	= $(SRC:.c=.o)

NAME 	= generator

FLAGS	= -I./includes -L../libpf/ -lpfmy -Wall -Wextra

all:	$(NAME)

$(NAME):$(OBJ)
		make all -C ../libpf/my/
		make clean -C ../libpf/my/
		gcc -o $(NAME) $(OBJ) $(FLAGS) 
		rm *.o

run:	all
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind :	$(OBJ)
			$(MAKE) -C ../libpf/my/ all
			$(MAKE) -C ../libpf/my/ clean
			gcc -o $(NAME) $(SRC) $(FLAGS) $(FLAGSCSFML) -g 
			rm *.o
