##
## EPITECH PROJECT, 2023
## B-CCP-400-LIL-4-1-theplazza-alexis.salaun
## File description:
## Makefile
##

SRC = 	src/main.cpp							\
		src/Error/Error.cpp						\
		src/Utils/Utils.cpp						\
		src/Utils/Timer.cpp						\
		src/Utils/Sender.cpp					\
		src/Pizzas/Pizza.cpp					\
		src/Kitchen/Cook.cpp					\
		src/Pizzas/Regina.cpp					\
		src/Kitchen/Stock.cpp					\
		src/Utils/Message.cpp					\
		src/Utils/Reciever.cpp					\
		src/Pizzas/Fantasia.cpp					\
		src/Kitchen/Kitchen.cpp					\
		src/Parsing/Parsing.cpp					\
		src/Pizzas/Margarita.cpp				\
		src/Pizzas/Americana.cpp				\
		src/Utils/PizzaTools.cpp				\
		src/Kitchen/ThreadPool.cpp				\
		src/Reception/Reception.cpp				\

OBJ = $(SRC:.cpp=.o)

NAME = plazza

CXXFLAGS = -std=c++20 -Wall -Wextra -Werror

NUM_SRC := $(words $(SRC))

counter := 0

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "\033[32;01m\n[----------PLAZZA----------]\033[;0m"
	g++ $(OBJ) -o $(NAME) $(CXXFLAGS) -g

%.o: %.cpp
	@$(eval counter=$(shell echo $$(($(counter) + 1))))
	@echo -n -e "\033[0K\rCompiling $@ [\033[34m$(counter)/$(NUM_SRC)\033[0m] (\033[34m$(shell echo $$(($(counter) * 100 / $(NUM_SRC))))%\033[0m)"
	@g++ -c $< -o $@ $(CXXFLAGS)

clean:
	@echo -e "\033[31;01m[----------PLAZZA Clean----------]\033[;0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
