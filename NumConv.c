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
        if(number[i] != '0' &&
           number[i] != '1' &&
           number[i] != ' ')
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
        if((number[i] < '0' || number[i] > '9') &&
           number[i] != ' ')
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
		if((number[i] < '0' || number[i] > '7') &&
		   number[i] != ' ')
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
		if(
		    !((number[i] >= '0' && number[i] <= '9') ||
		      (number[i] >= 'A' && number[i] <= 'F') ||
		      (number[i] >= 'a' && number[i] <= 'f') ||
		      number[i] == ' ')
		)
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
	}
	else
	{
	    strcpy(clean, number);
	}
	
	long val = strtol(clean, NULL, base); // strtol() converts a string containing a number into a long integer value based on the specified base.

    int i = 0;
    int j;
    char temp[65];

	if(val <= 0)
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

// C does not support binary output, so we convert the input to decimal first and then display the binary value by storing it in a variable.

void decimal()
{
	// input number is converted to its decimal equivalent using strtol() and stored in a variable for display.
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
	}
	else
	{
	    strcpy(clean, number);
	}
	
	result_dec = strtol(clean, NULL, base);
}

void octal()
{
	/*
		input number is first converted to its decimal equivalent using strtol() and stored in a variable,
		then value is then displayed in octal format using the %lo format specifier
	*/
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
	}
	else
	{
	    strcpy(clean, number);
	}
	
	result_oct = strtol(clean, NULL, base);
}

void hexa_decimal()
{
	/*
		input number is first converted to its decimal equivalent using strtol() and stored in a variable,
		then value is then displayed in hexadecimal format using the %lX format specifier
	*/
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
	}
	else
	{
	    strcpy(clean, number);
	}
	
	result_hexa = strtol(clean, NULL, base);
}