#include <stdio.h>

#include "Input.h"
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
    number_conv_outputscreen();  
    return;
}
    Num_logs_input();
}

void bitwise_ope_input()
{
	    switch(choice1)
            {
                case 1:
                    AND();
                    break;

                case 2:
                    OR();
                    break;

                case 3:
                    NOT();
                    break;

                case 4:
                    XOR();
                    break;

                case 5:
                    XNOR();
                    break;

                case 6:
                    NAND();
                    break;

                case 7:
                    Left_Shift();
                    break;

                case 8:
                    Right_Shift();
                    break;

                case 9:
                    Count_Set_Bits();
                    break;
            }

    Bit_logs_input(); 

    while(IsKeyDown(KEY_ENTER))
    {
        BeginDrawing();
        EndDrawing();
    }
            return;
        }
