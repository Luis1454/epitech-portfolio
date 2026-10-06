##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file that compiles
##

SRC	 	=	my_putstr.c					\
			my_putchar.c				\
			my_put_nbr.c				\
			my_printf.c 				\
			print.c 					\
			my_strlen.c 				\

OBJ		=	$(SRC:.c=.o)

NAME	=	libpfmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp libpfmy.a ../

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re: 	clean
		all
