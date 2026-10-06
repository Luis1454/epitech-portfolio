##
## EPITECH PROJECT, 2024
## cryptography
## File description:
## Makefile
##

NAME	=	my_pgp
SRC_DIR	=	src
SRC	=	$(SRC_DIR)/xor.py \
		$(SRC_DIR)/aes.py \
		$(SRC_DIR)/rsa.py \
		$(SRC_DIR)/pgp.py \
		$(SRC_DIR)/main.py \

all: $(NAME)

$(NAME):
	echo "#!/usr/bin/env python3" > $(NAME)
	for s in $(SRC); do \
		cat $$s >> $(NAME); \
	done
	chmod +x $(NAME)
	@echo "Cryptography is ready to use!"


run:
	./$(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	@echo "Full cleaning..."

re: fclean all

.PHONY: all clean fclean re
