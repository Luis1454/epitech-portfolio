cd lib/my/
rm libmy.a
./build.sh
cd ../..
gcc rush.c tests/*.c -o unit_test -I./include/ -L./lib/my/ -lmy --coverage -lcriterion
