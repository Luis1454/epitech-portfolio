##
## EPITECH PROJECT, 2023
## Nanotekspice
## File description:
## Makefile
##

PHYSICS =	src/Physics/Ray.cpp					\
			src/Physics/Color.cpp				\
			src/Physics/Point.cpp				\
			src/Physics/Light.cpp				\
			src/Physics/Vector.cpp 				\
			src/Physics/Matrix.cpp				\

OBJECTS =	src/Objects/Cube.cpp				\
			src/Objects/Cone.cpp 				\
			src/Objects/Rect.cpp				\
			src/Objects/Plane.cpp				\
			src/Objects/Object.cpp				\
			src/Objects/Sphere.cpp				\
			src/Objects/Circle.cpp				\
			src/Objects/Triangle.cpp			\
			src/Objects/Cylinder.cpp			\

ENGINE =	src/Engine/Camera.cpp				\
			src/Engine/Scene.cpp				\
			src/Engine/Renderer.cpp				\
			src/Engine/Exporter.cpp				\

PARSER =	src/Parser/Parser.cpp				\
			src/Parser/StringUtils.cpp			\
			src/Parser/RecupLight.cpp			\
			src/Parser/RecupEffect.cpp			\
			src/Parser/RecupCamera.cpp			\
			src/Parser/RecupPrimitive.cpp		\

LIGHTS = 	src/Lights/Spot.cpp				\
			src/Lights/Ambient.cpp				\
			src/Lights/LightPoint.cpp			\
			src/Lights/Directional.cpp			\
			src/Lights/Environment.cpp			\

EFFECTS =	src/Effects/Bloom.cpp				\
			src/Effects/Clamp.cpp				\
			src/Effects/GaussianBlur.cpp		\
			src/Effects/ChromaticAberration.cpp	\

SRC = 		src/main.cpp						\
			src/RayTracer.cpp					\
			$(PHYSICS)							\
			$(LIGHTS)							\
			$(OBJECTS)							\
			$(EFFECTS)							\
			$(ENGINE)							\
			$(PARSER)							\

OBJ = $(SRC:.cpp=.o)

NAME = raytracer

CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system

NUM_SRC := $(words $(SRC))

counter := 0

all: test

test: $(NAME)

$(NAME): $(OBJ)
	@g++ $(OBJ) -o $(NAME) $(CXXFLAGS) -g

%.o: %.cpp
	@$(eval counter=$(shell echo $$(($(counter) + 1))))
	@echo -n -e "\033[0K\rCompiling $@ [\033[34m$(counter)/$(NUM_SRC)\033[0m]\
	(\033[34m$(shell echo $$(($(counter) * 100 / $(NUM_SRC))))%\033[0m)"
	@g++ $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all