gcc *.c -I../include/ -c
ar rc libmy.a *.o
rm *.o
