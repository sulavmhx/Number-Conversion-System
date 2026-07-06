#include <stdio.h>


#include "Global.h"
#include "utility.h"
#include "bitwise.h"
#include "raylib.h"

void AND(void)
{
    result = num1 & num2;
}

void OR(void)
{
    result = num1 | num2;
}

void NOT(void)
{
    result = ~num1;
}

void XOR(void)
{
    result = num1 ^ num2;
}

void XNOR(void)
{
    result = ~(num1 ^ num2);
}

void NAND(void)
{
    result = ~(num1 & num2);
}

void Left_Shift(void)
{
    result = num1 << shift;
}

void Right_Shift(void)
{
    result = num1 >> shift;
}

void Count_Set_Bits(void)
{
    count = 0;
    temp = num1;

    while(temp)
    {
        count += temp & 1;
        temp >>= 1;
    }

    result = count;
}