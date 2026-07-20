#include <stdlib.h>
#include <string.h>
#include "Global.h"
#include "NumConv.h"
#include "Utility.h"

int binaryinput_check(char number[])
{
    int i = 0;
    while(number[i] != '\0')
    {
        if(number[i] != '0' && number[i] != '1' && number[i] != ' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int decimalinput_check(char number[])
{
    int i = 0;
    while(number[i] != '\0')
    {
        if((number[i] < '0' || number[i] > '9') && number[i] != ' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int octalinput_check(char number[])
{
    int i = 0;
    while(number[i] != '\0')
    {
        if((number[i] < '0' || number[i] > '7') && number[i] != ' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int hexainput_check(char number[])
{
    int i = 0;
    while(number[i] != '\0')
    {
        if( !((number[i] >= '0' && number[i] <= '9') || (number[i] >= 'A' && number[i] <= 'F') || (number[i] >= 'a' && number[i] <= 'f') || number[i] == ' ') )
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void binary()
{
    int base;
    if(input_choice == 1)
        base = 2;
    else if(input_choice == 2)
        base = 10;
    else if(input_choice == 3)
        base = 8;
    else
        base = 16;

    if(base == 2)
    {
        remove_spaces(number, clean);

		if (input_choice == 1 && strlen(clean) > 64)
		{
		    invalid = 1;
		    return;
		}
    }
    else
    {
        strcpy(clean, number);
    }

    unsigned long long val = strtoull(clean, NULL, base);

    int i = 0;
    int j;
    char temp[65];

    if(val == 0)
    {
        strcpy(result_bin, "0");
        return;
    }

    while(val > 0)
    {
        temp[i++] = (val % 2) + '0';
        val /= 2;
    }

    j = 0;
    while(i > 0)
    {
        result_bin[j++] = temp[--i];
    }
    result_bin[j] = '\0';
}

void decimal()
{
    int base;
    if(input_choice == 1)
        base = 2;
    else if(input_choice == 2)
        base = 10;
    else if(input_choice == 3)
        base = 8;
    else
        base = 16;

    if(base == 2)
    {
        remove_spaces(number, clean);

		if (input_choice == 1 && strlen(clean) > 64)
		{
		    invalid = 1;
		    return;
		}
    }
    else
    {
        strcpy(clean, number);
    }

    result_dec = strtoull(clean, NULL, base);
}

void octal()
{
    int base;
    if(input_choice == 1)
        base = 2;
    else if(input_choice == 2)
        base = 10;
    else if(input_choice == 3)
        base = 8;
    else
        base = 16;

    if(base == 2)
    {
        remove_spaces(number, clean);

		if (input_choice == 1 && strlen(clean) > 64)
		{
		    invalid = 1;
		    return;
		}
    }
    else
    {
        strcpy(clean, number);
    }

    result_oct = strtoull(clean, NULL, base);
}

void hexa_decimal()
{
    int base;
    if(input_choice == 1)
        base = 2;
    else if(input_choice == 2)
        base = 10;
    else if(input_choice == 3)
        base = 8;
    else
        base = 16;

    if(base == 2)
    {
        remove_spaces(number, clean);

		if (input_choice == 1 && strlen(clean) > 64)
		{
		    invalid = 1;
		    return;
		}
    }
    else
    {
        strcpy(clean, number);
    }

    result_hexa = strtoull(clean, NULL, base);
}