#include <stdio.h>

int my_atoi(char*);
int atoi_loop(char *, int);

#ifndef USE_MIPS32
int
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

#else /* USE_MIPS32 */
extern int atoi_loop(char *, int);
#endif 

int
my_atoi(char *p)
{
    if (p[0] == '-') {
        return atoi_loop(p + 1, -1);
    } 
    else {
        return atoi_loop(p, 1);
    }
}

int 
main(void) 
{
    printf("my_atoi('1'):  %d\n", my_atoi("1"));
    printf("my_atoi('-9'): %d\n", my_atoi("-9"));
    printf("my_atoi('1521'): %d\n", my_atoi("1521"));
    printf("my_atoi('-3501'): %d\n", my_atoi("-3501"));

    return 0;
}

