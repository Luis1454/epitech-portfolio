##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
        src/utils.c \

OBJ = 	$(SRC:.c=.o)

NAME =	ai
CFLAGS	=	-Wall -Wextra -g
L_FLAGS 	=	-L lib/my -lmy

I_FLAGS	=	-I include/

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C lib/my/ all -s
	@gcc -o $(NAME) $(OBJ) $(L_FLAGS) $(I_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/my/ fclean

re: fclean all
