gcc *.c -I../include/ -c
ar rc libmy.a *.o
mv libmy.a ..
rm *.o
