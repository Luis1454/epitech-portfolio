cd lib/my/
rm libmy.a
./build.sh
cd ../..
gcc *.c -o test  main.o -I./include/ -L./lib/my/ -lmy
