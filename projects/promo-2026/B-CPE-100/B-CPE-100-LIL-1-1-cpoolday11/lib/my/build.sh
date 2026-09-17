#!/bin/bash

gcc -c my_*.c
ar rc libmy.a *.o
rm *.o
