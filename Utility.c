#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"

void clear_screen()
{
#if _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void clear_buffer()
{
    int ch;

    while(1)
    {
        ch = getchar();

        if(ch == '\n' || ch == EOF)
            break;
    }
}