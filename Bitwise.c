#include <stdio.h>

#include "Global.h"
#include "utility.h"
#include "bitwise.h"

void AND()
{
    clear_screen();

    printf("========== AND ==========\n");

    printf("Enter First Number : ");
    scanf("%u", &num1);

    printf("Enter Second Number : ");
    scanf("%u", &num2);

    result = num1 & num2;
}

void OR()
{
    clear_screen();

    printf("========== OR ==========\n");

    printf("Enter First Number : ");
    scanf("%u", &num1);

    printf("Enter Second Number : ");
    scanf("%u", &num2);

    result = num1 | num2;
}
void NOT()
{
    clear_screen();

    printf("========== NOT ==========\n");

    printf("Enter Number : ");
    scanf("%u", &num1);

    result = ~num1;
}
void XOR()
{
    clear_screen();

    printf("========== XOR ==========\n");

    printf("Enter First Number : ");
    scanf("%u", &num1);

    printf("Enter Second Number : ");
    scanf("%u", &num2);

    result = num1 ^ num2;
}
void XNOR()
{
    clear_screen();

    printf("========== XNOR ==========\n");

    printf("Enter First Number : ");
    scanf("%u", &num1);

    printf("Enter Second Number : ");
    scanf("%u", &num2);

    result = ~(num1 ^ num2);
}
void NAND()
{
    clear_screen();

    printf("========== NAND ==========\n");

    printf("Enter First Number : ");
    scanf("%u", &num1);

    printf("Enter Second Number : ");
    scanf("%u", &num2);

    result = ~(num1 & num2);

}
void Left_Shift()
{
    clear_screen();

    printf("========== LEFT SHIFT ==========\n");

    printf("Enter Number : ");
    scanf("%u", &num1);

    printf("Enter Shift Count : ");
    scanf("%d", &shift);

    result = num1 << shift;    
}
void Right_Shift()
{
    clear_screen();

    printf("========== RIGHT SHIFT ==========\n");

    printf("Enter Number : ");
    scanf("%u", &num1);

    printf("Enter Shift Count : ");
    scanf("%d", &shift);

    result = num1 >> shift;
}
void Count_Set_Bits()
{
    clear_screen();

    printf("========== COUNT SET BITS ==========\n");

    printf("Enter Number : ");
    scanf("%u", &num1);

    while(num1)
    {
        count += num1 & 1;
        num1 >>= 1;
    }
}