#include <stdio.h>

#include "Input.h"
#include "Output.h"
#include "Utility.h"
#include "Global.h"
#include "Bitwise.h"
#include "NumConv.h"
#include "FileHandle.h"
#include "raylib.h"
#include "Drawing.h"

void num_conv_input(void)
{
    switch(input_choice)
    {
        case 1:
            if(binaryinput_check(number) == 0)
            {
                invalid = 1;
                return; 
            }
            break;

        case 2:
            if(decimalinput_check(number) == 0)
            {
                invalid = 1;
                return;
            }
            break;

        case 3:
            if(octalinput_check(number) == 0)
            {
                invalid = 1;
                return;
            }
            break;

        case 4:
            if(hexainput_check(number) == 0)
            {
                invalid = 1;
                return;
            }
            break;
    }

    invalid = 0; 

    switch(output_choice)
    {
        case 1:
            binary();
            break;
        case 2:
            decimal();
            break;
        case 3:
            octal();
            break;
        case 4:
            hexa_decimal();
            break;
    }
    
	if(invalid)
{
    int letterCount = 0;
    number[0] = '\0';
}
else
{
    number_conv_outputscreen();   // now the ONLY call
    return;
}

    // Save history data log cleanly
    Num_logs_input();
}

void bitwise_ope_input(void)
{
    // Keeping structural signature intact for your future Bitwise integrations
}