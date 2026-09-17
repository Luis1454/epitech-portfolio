#include <unistd.h>
#include "include/my.h"
#include "include/my_macro_abs.h"

int rush3(char *buf);

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = 0;
    if (len < 0)
        return (84);
    return rush3(buff);
}
