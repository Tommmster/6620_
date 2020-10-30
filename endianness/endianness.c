#include <stdio.h>

int
main(void) 
{
    int x = 0xFFEEDDCC;
    char f = 0xFF;

    char *p = (char *)&x;

    printf("%s\n", (*p == f) ? "BE": "LE" );
    return 0;
}
