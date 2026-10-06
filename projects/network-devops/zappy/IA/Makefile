##
## EPITECH PROJECT, 2024
## zappy_IA
## File description:
## Makefile
##

SRC	=	Zappy_IA.py	\
		client.py	\
		parse.py	\
		function.py	\

NAME	=	zappy_ai

NBR_SRC := $(words $(SRC))

all:	$(NAME)

$(NAME):
	@echo -e "Compiling $(SRC) [\033[34m$(NBR_SRC)/$(NBR_SRC)\033[0m]\
	(\033[34m100%\033[0m)"
	@echo -e "\033[32;01m[----------ZAPPY IA----------]\033[;0m"
	cat $(SRC) > $(NAME)
	chmod +x $(NAME)

clean:
	@echo -e "\033[31;01m[----------ZAPPY IA Clean----------]\033[;0m"
	rm -rf $(NAME)
	rm -rf __pycache__
	find . -type f -name "*#" -a -name "#*" -delete -o -name "*~" -delete

fclean: clean
	rm -rf $(NAME)

re: fclean all
