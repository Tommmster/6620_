#include <stdio.h>


static int
atoi_loop(char *p, int sign)
{
    int num = 0;


    while (*p != 0)
    {
        num = num * 10 + (*p - '0');
        p ++;
    }

    return sign * num;
}

int
atoi(char *p)
{
    if (p[0] == '-') {
        return atoi_loop(p++, -1);
    } 
    else {
        return atoi_loop(p, 1);
    }
}
