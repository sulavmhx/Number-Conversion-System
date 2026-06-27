#include <stdio.h>
#include <windows.h>

#include "Global.h"
#include "utility.h"
#include "bitwise.h"

void AND()
{
    And:
	clear_screen();

    printf("============================= AND =============================\n");

    printf("Enter First Number : ");
	if(scanf("%u", &num1) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto And;
	} 
	
    printf("Enter Second Number : ");
	if(scanf("%u", &num2) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto And;
	}
	
    result = num1 & num2;
}

void OR()
{
	Or:
    clear_screen();

    printf("============================= OR =============================\n");

    printf("Enter First Number : ");
    if(scanf("%u", &num1) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto Or;
	} 

    printf("Enter Second Number : ");
	if(scanf("%u", &num2) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto Or;
	}
	
    result = num1 | num2;
}
void NOT()
{
	Not:
    clear_screen();

    printf("============================= NOT =============================\n");

    printf("Enter Number : ");
	if(scanf("%u", &num1) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto Not;
	} 
	
    result = ~num1;
}
void XOR()
{
	Xor:
    clear_screen();

    printf("============================= XOR =============================\n");

    printf("Enter First Number : ");
	if(scanf("%u", &num1) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto Xor;
	} 
	
    printf("Enter Second Number : ");
    if(scanf("%u", &num2) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto Xor;
	} 

    result = num1 ^ num2;
}
void XNOR()
{
	Xnor:
    clear_screen();

    printf("============================= XNOR =============================\n");

    printf("Enter First Number : ");	
	if(scanf("%u", &num1) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto Xnor;
	} 
	
    printf("Enter Second Number : ");
   	if(scanf("%u", &num2) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto Xnor;
	}
	
    result = ~(num1 ^ num2);
}
void NAND()
{
	Nand:
    clear_screen();

    printf("============================= NAND =============================\n");

    printf("Enter First Number : ");
	if(scanf("%u", &num1) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto Nand;
	}
	
    printf("Enter Second Number : ");	
	if(scanf("%u", &num2) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto Nand;
	}
	
    result = ~(num1 & num2);

}
void Left_Shift()
{
lsif:
    clear_screen();

    printf("============================= LEFT SHIFT =============================\n");

    printf("Enter Number : ");
    if(scanf("%u", &num1) != 1)
    {
        clear_buffer();
        clear_screen();
        printf("\nINVALID INPUT!!!!!!\n");
        printf("\nLOADING PLEASE WAIT.....\n");
        Sleep(1000);
        goto lsif;
    }

    printf("Enter Shift Count : ");
    if(scanf("%d", &shift) != 1)
    {
        clear_buffer();
        clear_screen();
        printf("\nINVALID INPUT!!!!!!\n");
        printf("\nLOADING PLEASE WAIT.....\n");
        Sleep(1000);
        goto lsif;
    }

    if(shift < 0 || shift >= 32)
    {
        clear_screen();
        printf("\nINVALID SHIFT COUNT!!!!!!\n");
        printf("Shift count must be between 0 and 31.\n");
        printf("\nLOADING PLEASE WAIT.....\n");
        Sleep(1000);
        goto lsif;
    }

    result = num1 << shift;
}

void Right_Shift()
{
rsif:
    clear_screen();

    printf("============================= RIGHT SHIFT =============================\n");

    printf("Enter Number : ");
    if(scanf("%u", &num1) != 1)
    {
        clear_buffer();
        clear_screen();
        printf("\nINVALID INPUT!!!!!!\n");
        printf("\nLOADING PLEASE WAIT.....\n");
        Sleep(1000);
        goto rsif;
    }

    printf("Enter Shift Count : ");
    if(scanf("%d", &shift) != 1)
    {
        clear_buffer();
        clear_screen();
        printf("\nINVALID INPUT!!!!!!\n");
        printf("\nLOADING PLEASE WAIT.....\n");
        Sleep(1000);
        goto rsif;
    }

    if(shift < 0 || shift >= 32)
    {
        clear_screen();
        printf("\nINVALID SHIFT COUNT!!!!!!\n");
        printf("Shift count must be between 0 and 31.\n");
        printf("\nLOADING PLEASE WAIT.....\n");
        Sleep(1000);
        goto rsif;
    }

    result = num1 >> shift;
}

void Count_Set_Bits()
{
	cnt:
    clear_screen();
	
	count = 0; 
	num1 = 0;
	
    printf("============================= COUNT SET BITS =============================\n");

    printf("Enter Number : ");
    
	if(scanf("%u", &num1) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto cnt;
	}
	
	temp = num1;
	
    while(temp)
    {
        count += num1 & 1;
        num1 >>= 1;
    }
}