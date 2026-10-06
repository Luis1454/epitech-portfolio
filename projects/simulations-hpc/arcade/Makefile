##
## EPITECH PROJECT, 2024
## B-OOP-400-LIL-4-1-arcade-alexis.salaun
## File description:
## Makefile
##

MAKEFLAGS += --silent

# Core

SRC_ARCADE = 	core/Core.cpp			\
				core/main.cpp           \
				core/Parser.cpp			\
				core/menu/Menu.cpp      \
				core/dlfonction/Dl.cpp  \
				core/menu/Register.cpp	\
				core/dlfonction/Dlsym.cpp	\
				core/dlfonction/Dlopen.cpp  \
				core/dlfonction/Dlclose.cpp  \
				core/dlfonction/Dlerror.cpp
OBJECTS_CPP = $(SRC_ARCADE:.cpp=.o)
NAME_ARCADE = arcade
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -fPIC

# Games

SRC_NIBBLER = games/nibbler/Nibbler.cpp
SRC_SNAKE = games/snake/Snake.cpp
OBJ_NIBBLER = $(SRC_NIBBLER:.cpp=.o)
OBJ_SNAKE = $(SRC_SNAKE:.cpp=.o)
NAME_NIBBLER = arcade_nibler.so
NAME_SNAKE = arcade_snake.so
CXXFLAGS_GAME = -std=c++20 -Wall -Wextra -Werror -fPIC

# Graphicals

SRC_SFML = graphicals/sfml/Sfml.cpp
SRC_NCURSES = graphicals/ncurses/Ncurses.cpp
SRC_SDL = graphicals/sdl/Sdl.cpp
OBJ_SFML = $(SRC_SFML:.cpp=.o)
OBJ_NCURSES = $(SRC_NCURSES:.cpp=.o)
OBJ_SDL = $(SRC_SDL:.cpp=.o)
SFML_NAME = arcade_sfml.so
NCURSES_NAME = arcade_ncurses.so
SDL_NAME = arcade_sdl2.so
GENERAL_LIB_FLAGS = -std=c++20 -Wall -Wextra -Werror -fPIC
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
NCURSES_FLAGS = -lncurses
SDL_FLAGS = -lSDL2 -lSDL2_ttf

# Targets

all: core games graphicals

core: $(NAME_ARCADE)

$(NAME_ARCADE): $(OBJECTS_CPP)
	@echo -e "\033[32;01m[----------Core compiled----------]\033[;0m"
	@g++ $(CXXFLAGS) $(OBJECTS_CPP) -o $@

games: $(NAME_NIBBLER) $(NAME_SNAKE)

$(NAME_NIBBLER): $(OBJ_NIBBLER)
	@echo -e "\033[34;01m[----------Nibbler compiled----------]\033[;0m"
	@g++ -shared -fPIC $(OBJ_NIBBLER) -o $(NAME_NIBBLER) $(CXXFLAGS_GAME) -g
	@mkdir -p ./lib
	@mv $(NAME_NIBBLER) ./lib

$(NAME_SNAKE): $(OBJ_SNAKE)
	@echo -e "\033[34;01m[----------Snake compiled----------]\033[;0m"
	@g++ -shared -fPIC $(OBJ_SNAKE) -o $(NAME_SNAKE) $(CXXFLAGS_GAME) -g
	@mkdir -p ./lib
	@mv $(NAME_SNAKE) ./lib

graphicals: $(SFML_NAME) $(NCURSES_NAME) $(SDL_NAME)

$(SFML_NAME): $(OBJ_SFML)
	@echo -e "\033[35;01m[----------SFML compiled----------]\033[;0m"
	@g++ -shared -fPIC $(OBJ_SFML) -o $(SFML_NAME) $(GENERAL_LIB_FLAGS) \
	$(SFML_FLAGS) -g
	@mkdir -p ./lib
	@mv $(SFML_NAME) ./lib

$(NCURSES_NAME): $(OBJ_NCURSES)
	@echo -e "\033[35;01m[----------Ncurses compiled----------]\033[;0m"
	@g++ -shared -fPIC $(OBJ_NCURSES) -o $(NCURSES_NAME) $(GENERAL_LIB_FLAGS) \
	$(NCURSES_FLAGS) -g
	@mkdir -p ./lib
	@mv $(NCURSES_NAME) ./lib

$(SDL_NAME): $(OBJ_SDL)
	@echo -e "\033[35;01m[----------SDL compiled----------]\033[;0m"
	@g++ -shared -fPIC $(OBJ_SDL) -o $(SDL_NAME) $(GENERAL_LIB_FLAGS) \
	$(SDL_FLAGS) -g
	@mkdir -p ./lib
	@mv $(SDL_NAME) ./lib

%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@
	@echo -e "\033[37;01m COMPILE:\033[37;00m $<\033[;0m"

clean:
	@echo -e "\033[31;01m[----------Clean----------]\033[;0m"
	@rm -f $(OBJ) $(OBJ_NIBBLER) $(OBJ_SNAKE) $(OBJ_SFML) $(OBJ_NCURSES) \
	$(OBJ_SDL) $(OBJECTS_C) $(OBJECTS_CPP)

fclean: clean
	@echo -e "\033[31;01m[----------Fclean----------]\033[;0m"
	@rm -f $(NAME_ARCADE) $(NAME_NIBBLER) $(NAME_SNAKE) $(SFML_NAME) \
	$(NCURSES_NAME) $(SDL_NAME)
	@rm -r -f ./lib

re: fclean all
