##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## dsk
##

SRC = $(shell find -name '*.c')

OBJ = $(SRC:.c=.o);

NAMELIB = libmy.a

CFLAGS = -I./../../include/

all:	$(NAMELIB)

$(NAMELIB): $(OBJ)
	@echo -e "\033[33;01m[--------lib-------------]\033[;0m"
	@echo -e "ar rc $(NAMELIB) $(OBJ)"
	@ar rc $(NAMELIB) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean :	clean
	@echo -e "\033[31;01m--------fclean_lib-------------\033[;0m"
	@echo -e "rm -f $(NAMELIB)"
	@rm -f $(NAMELIB)

re : fclean all
