##
## EPITECH PROJECT, 2023
## B-CCP-400-LIL-4-1-theplazza-alexis.salaun
## File description:
## Makefile
##

SRC = 			src/main.c								\
				src/Parsing/error.c						\
				src/Parsing/usage.c						\
				src/Parsing/parsing.c					\
				src/Server/run_server.c					\
				src/Server/handle_client.c				\
				src/Server/stock_request.c				\
				src/Server/handle_command.c				\
				src/Server/new_connection.c				\
				src/Server/update_ressource.c			\
				src/Server/handle_disconnection.c		\
				src/Server/handle_first_connection.c

UTILS =			src/Utils/add_in_str.c			\
 				src/Utils/write_log_file.c		\
				src/Utils/get_player_by_id.c	\
				src/Utils/str_to_word_array.c

CMD_CLIENTS =	src/Command/Client_command/fork.c					\
				src/Command/Client_command/left.c					\
				src/Command/Client_command/look.c					\
				src/Command/Client_command/eject.c					\
				src/Command/Client_command/right.c					\
				src/Command/Client_command/forward.c				\
				src/Command/Client_command/unknown.c				\
				src/Command/Client_command/broadcast.c				\
				src/Command/Client_command/inventory.c				\
				src/Command/Client_command/set_object.c				\
				src/Command/Client_command/connect_nbr.c			\
				src/Command/Client_command/take_object.c			\
				src/Command/Client_command/incantation.c			\
				src/Command/Client_command/look_second.c			\
				src/Command/Client_command/eject_second.c			\
				src/Command/Client_command/broadcast_second.c		\
				src/Command/Client_command/incantation_second.c		\
				src/Command/Client_command/handle_clients_command.c

COMMAND_RECEIVE =	src/Command/Command_receive_by_gui/command_bct.c 	\
					src/Command/Command_receive_by_gui/command_mct.c 	\
					src/Command/Command_receive_by_gui/command_msz.c 	\
					src/Command/Command_receive_by_gui/command_pin.c 	\
					src/Command/Command_receive_by_gui/command_plv.c 	\
					src/Command/Command_receive_by_gui/command_ppo.c 	\
					src/Command/Command_receive_by_gui/command_sgt.c 	\
					src/Command/Command_receive_by_gui/command_sst.c 	\
					src/Command/Command_receive_by_gui/command_suc.c 	\
					src/Command/Command_receive_by_gui/command_tna.c

CMD_GUI =		src/Command/Gui_command/bct.c			\
				src/Command/Gui_command/ebo.c			\
				src/Command/Gui_command/edi.c			\
				src/Command/Gui_command/enw.c			\
				src/Command/Gui_command/msz.c			\
				src/Command/Gui_command/pbc.c			\
				src/Command/Gui_command/pdi.c			\
				src/Command/Gui_command/pdr.c			\
				src/Command/Gui_command/pex.c			\
				src/Command/Gui_command/pfk.c			\
				src/Command/Gui_command/pgt.c			\
				src/Command/Gui_command/pic.c			\
				src/Command/Gui_command/pie.c			\
				src/Command/Gui_command/pin.c			\
				src/Command/Gui_command/plv.c			\
				src/Command/Gui_command/pnw.c			\
				src/Command/Gui_command/ppo.c			\
				src/Command/Gui_command/sbp.c			\
				src/Command/Gui_command/seg.c			\
				src/Command/Gui_command/sgt.c			\
				src/Command/Gui_command/smg.c			\
				src/Command/Gui_command/sst.c			\
				src/Command/Gui_command/suc.c			\
				src/Command/Gui_command/tna.c

INIT =			src/Server/Init/init_map.c				\
 				src/Server/Init/init_server.c			\
				src/Server/Init/init_client.c

SRC += $(CMD_GUI) $(INIT) $(CMD_CLIENTS) $(UTILS) $(COMMAND_RECEIVE)

OBJ = $(SRC:.c=.o)

NAME = zappy_server

CXXFLAGS = -Wall -Wextra -Werror -g

NUM_SRC := $(words $(SRC))

counter := 0

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@echo -e "\033[32;01m[----------ZAPPY SERVER----------]\033[;0m"
	@gcc $(OBJ) -o $(NAME) $(CXXFLAGS) -g

%.o: %.c
	@$(eval counter=$(shell echo $$(($(counter) + 1))))
	@echo -n -e "\033[0K\rCompiling $@ [\033[34m$(counter)/$(NUM_SRC)\033[0m]\
	(\033[34m$(shell echo $$(($(counter) * 100 / $(NUM_SRC))))%\033[0m)"
	@gcc -c $< -o $@ $(CXXFLAGS)

clean:
	@echo -e "\033[31;01m[----------ZAPPY SERVER Clean----------]\033[;0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
