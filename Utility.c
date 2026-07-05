#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"
#include <time.h>
#include "Global.h"

void updateTime(void)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(currentTime, sizeof(currentTime),
             "%A, %d %B %Y  %I:%M:%S %p", t);
}

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

void remove_spaces(char source[], char destination[])
{
    int i = 0;
    int j = 0;

    while(source[i] != '\0')
    {
        if(source[i] != ' ')
        {
            destination[j] = source[i];
            j++;
        }

        i++;
    }

    destination[j] = '\0';
}