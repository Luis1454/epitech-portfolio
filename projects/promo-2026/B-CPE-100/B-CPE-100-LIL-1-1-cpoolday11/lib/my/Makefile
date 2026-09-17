#
# EPITECH PROJECT, 2021
# my.h
# File description:
# all libraries in one file
#

CC = gcc

ALL: CREATE CLEAN

CREATE:
	gcc -c my_*.c
	ar rc libmy.a *.o
	cp ../../include/my.h ../include

CLEAN:
	rm *.o
