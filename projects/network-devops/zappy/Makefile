##
## EPITECH PROJECT, 2024
## B-YEP-400-LIL-4-1-zappy-alexis.salaun
## File description:
## Makefile
##

MAKEFLAGS += --silent

exec_gui = GUI/zappy_gui
exec_server = Server/zappy_server
exec_ia = IA/zappy_ai

all: FORCE
	@make -C GUI/
	@make -C Server/
	@make -C IA/
	@mv $(exec_gui) .
	@mv $(exec_server) .
	@mv $(exec_ia) .

clean:
	@make clean -C GUI/
	@make clean -C Server/
	@make clean -C IA/

fclean:
	@make fclean -C GUI/
	@make fclean -C Server/
	@make fclean -C IA/
	rm -f zappy_gui zappy_server zappy_ai server.log

re:
	@make re -C GUI/
	@make re -C Server/
	@make re -C IA/
	@mv $(exec_gui) .
	@mv $(exec_server) .
	@mv $(exec_ia) .

FORCE:
