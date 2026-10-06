##
## EPITECH PROJECT, 2023
## B-CCP-400-LIL-4-1-theplazza-alexis.salaun
## File description:
## Makefile
##

SRC_MAIN = src/main.cpp

SRC_MAP = src/Map/Tile.cpp						\
		  src/Map/Tiles.cpp						\
		  src/Map/Players.cpp					\
		  src/Map/Map.cpp						\
		  src/Map/Eggs.cpp						\
		  src/Map/Teams.cpp

SRC_PLAYER = src/Player/Player.cpp				\
			 src/Player/Inventory.cpp			\
			 src/Player/Egg.cpp					\
		  	 src/Player/Team.cpp

SRC_WINDOW = src/Window/Renderer.cpp			\
			 src/Window/Events.cpp				\
			 src/Window/Fonts.cpp				\
			 src/Window/Port.cpp				\
			 src/Window/Texture.cpp				\
			 src/Window/Window.cpp				\
			 src/Window/Scoreboard.cpp			\
			 src/Window/Info.cpp

SRC_SERVER = src/ServerConnection/ServerConnect.cpp

SRC_COMMANDS = src/Commands/Cmd.cpp             \
			   src/Commands/Bct.cpp             \
			   src/Commands/Msz.cpp             \
			   src/Commands/Pnw.cpp             \
			   src/Commands/Ppo.cpp             \
			   src/Commands/Plv.cpp             \
			   src/Commands/Pdi.cpp             \
			   src/Commands/Tna.cpp             \
			   src/Commands/Ebo.cpp             \
			   src/Commands/Seg.cpp				\
			   src/Commands/Enw.cpp				\
			   src/Commands/Edi.cpp				\
			   src/Commands/Pin.cpp
			#    src/Commands/Smg.cpp				\
			#    src/Commands/Suc.cpp				\
			#    src/Commands/Sbp.cpp				\
			#    src/Commands/Sst.cpp				\
			#    src/Commands/Sgt.cpp				\
			#    src/Commands/Pic.cpp				\
			#    src/Commands/Pie.cpp				\

SRC_RESOURCES = src/Resources/Resource.cpp		\
				src/Resources/Item.cpp			\
				src/Resources/Food.cpp			\
				src/Resources/Linemate.cpp		\
				src/Resources/Deraumere.cpp		\
				src/Resources/Sibur.cpp			\
				src/Resources/Mendiane.cpp		\
				src/Resources/Phiras.cpp		\
				src/Resources/Thystame.cpp

SRC = $(SRC_MAIN) $(SRC_MAP) $(SRC_PLAYER) $(SRC_WINDOW) $(SRC_SERVER) $(SRC_COMMANDS) $(SRC_RESOURCES)

OBJ = $(SRC:.cpp=.o)

NAME = zappy_gui

CXXFLAGS = -std=c++20 -Wall -Wextra -Werror
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

NUM_SRC := $(words $(SRC))

counter := 0

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@echo -e "\033[32;01m[----------ZAPPY GUI----------]\033[;0m"
	g++ $(OBJ) -o $(NAME) $(CXXFLAGS) -g $(SFML_LIBS)

%.o: %.cpp
	@$(eval counter=$(shell echo $$(($(counter) + 1))))
	@echo -n -e "\033[0K\rCompiling $@ [\033[34m$(counter)/$(NUM_SRC)\033[0m] (\033[34m$(shell echo $$(($(counter) * 100 / $(NUM_SRC))))%\033[0m)"
	@g++ -c $< -o $@ $(CXXFLAGS)

clean:
	@echo -e "\033[31;01m[----------ZAPPY GUI Clean----------]\033[;0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
