#include <stdio.h>
#include <windows.h>

#include "Input.h"
#include "Output.h"
#include "Utility.h"
#include "Global.h"
#include "Bitwise.h"
#include "NumConv.h"
#include "FileHandle.h"

void number_conv_input()
{
num_start:
	
	clear_screen();
	
	//Title
	printf("███╗   ██╗██╗   ██╗███╗   ███╗     ██████╗ ██████╗ ███╗   ██╗██╗   ██╗███████╗██████╗ ████████╗███████╗██████╗ \n");
	printf("████╗  ██║██║   ██║████╗ ████║    ██╔════╝██╔═══██╗████╗  ██║██║   ██║██╔════╝██╔══██╗╚══██╔══╝██╔════╝██╔══██╗\n");
	printf("██╔██╗ ██║██║   ██║██╔████╔██║    ██║     ██║   ██║██╔██╗ ██║██║   ██║█████╗  ██████╔╝   ██║   █████╗  ██████╔╝\n");
	printf("██║╚██╗██║██║   ██║██║╚██╔╝██║    ██║     ██║   ██║██║╚██╗██║╚██╗ ██╔╝██╔══╝  ██╔══██╗   ██║   ██╔══╝  ██╔══██╗\n");
	printf("██║ ╚████║╚██████╔╝██║ ╚═╝ ██║    ╚██████╗╚██████╔╝██║ ╚████║ ╚████╔╝ ███████╗██║  ██║   ██║   ███████╗██║  ██║\n");
	printf("╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝\n");
	
	//Input Base
	printf("-----------------------------------------------------------------------------");
    printf("\nSelect Input Base");
    printf("\n[1] Binary");
    printf("\n[2] Decimal");
    printf("\n[3] Octal");
    printf("\n[4] Hexa-Decimal");
    printf("\n[0] Back");
    printf("-----------------------------------------------------------------------------");
    printf("\nEnter choice: ");
    
	if(scanf("%d", &input_choice) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto num_start;
	}    
	
	if(input_choice < 0 || input_choice > 4)
	{
	    clear_screen();
	    printf("\nINVALID INPUT BASE !!!!!\n");
	    printf("\n LOADING PLEASE WAIT..... \n");
	    Sleep(1000);
	    goto num_start;
	}

	if(input_choice == 0)
	{
	   return;    // Back to Main Menu
	}
	
    
    output:
    clear_screen();
    
	printf("███╗   ██╗██╗   ██╗███╗   ███╗     ██████╗ ██████╗ ███╗   ██╗██╗   ██╗███████╗██████╗ ████████╗███████╗██████╗ \n");
	printf("████╗  ██║██║   ██║████╗ ████║    ██╔════╝██╔═══██╗████╗  ██║██║   ██║██╔════╝██╔══██╗╚══██╔══╝██╔════╝██╔══██╗\n");
	printf("██╔██╗ ██║██║   ██║██╔████╔██║    ██║     ██║   ██║██╔██╗ ██║██║   ██║█████╗  ██████╔╝   ██║   █████╗  ██████╔╝\n");
	printf("██║╚██╗██║██║   ██║██║╚██╔╝██║    ██║     ██║   ██║██║╚██╗██║╚██╗ ██╔╝██╔══╝  ██╔══██╗   ██║   ██╔══╝  ██╔══██╗\n");
	printf("██║ ╚████║╚██████╔╝██║ ╚═╝ ██║    ╚██████╗╚██████╔╝██║ ╚████║ ╚████╔╝ ███████╗██║  ██║   ██║   ███████╗██║  ██║\n");
	printf("╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝\n");
	
    //Output Base
    printf("-----------------------------------------------------------------------------");
    printf("\nSelect Output Base");
    printf("\n[1] Binary");
    printf("\n[2] Decimal");
    printf("\n[3] Octal");
    printf("\n[4] Hexa-Decimal");
    printf("\n[0] Back");
    printf("\n-----------------------------------------------------------------------------");
    printf("\nEnter choice: ");
    if(scanf("%d", &output_choice) != 1)
	{
	    clear_buffer();
	    clear_screen();
	    printf("\nINVALID INPUT!!!!!!\n");
	    printf("\n LOADING PLEASE WAIT..... \n");
	    Sleep(1000);
	    goto output;
	}

	if(output_choice < 0 || output_choice > 4)
	{
	    clear_screen();
	    printf("\nINVALID OUTPUT BASE !!!!!\n");
	    printf("\n LOADING PLEASE WAIT..... \n");
	    Sleep(1000);
	    goto output;
	}
	
	if(output_choice == 0)
	{
	   goto num_start;    // Back to Main Menu
	}
	num_input:
    clear_screen();
    
   	printf("███╗   ██╗██╗   ██╗███╗   ███╗     ██████╗ ██████╗ ███╗   ██╗██╗   ██╗███████╗██████╗ ████████╗███████╗██████╗ \n");
	printf("████╗  ██║██║   ██║████╗ ████║    ██╔════╝██╔═══██╗████╗  ██║██║   ██║██╔════╝██╔══██╗╚══██╔══╝██╔════╝██╔══██╗\n");
	printf("██╔██╗ ██║██║   ██║██╔████╔██║    ██║     ██║   ██║██╔██╗ ██║██║   ██║█████╗  ██████╔╝   ██║   █████╗  ██████╔╝\n");
	printf("██║╚██╗██║██║   ██║██║╚██╔╝██║    ██║     ██║   ██║██║╚██╗██║╚██╗ ██╔╝██╔══╝  ██╔══██╗   ██║   ██╔══╝  ██╔══██╗\n");
	printf("██║ ╚████║╚██████╔╝██║ ╚═╝ ██║    ╚██████╗╚██████╔╝██║ ╚████║ ╚████╔╝ ███████╗██║  ██║   ██║   ███████╗██║  ██║\n");
	printf("╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝\n");
	
    printf("\n-----------------------------------------------------------------------------");

	//Input type
	
    printf("\nInput Base   : ");
    switch(input_choice)
    {
        case 1:
			printf("Binary(2)"); 
		break;
        case 2: 
			printf("Decimal(10)"); 
		break;
        case 3: 
			printf("Octal(8)"); 
		break;
        case 4: 
			printf("Hexa-Decimal(16)"); 
		break;
    }
    
	//Output type
	
    printf("\nOutput Base  : ");
    switch(output_choice)
    {
    	case 0:
    		return;
    	break;
        case 1: 
			printf("Binary(2)"); 
		break;
        case 2:
			printf("Decimal(10)"); 
		break;
        case 3:
			printf("Octal(8)"); 
		break;
        case 4:
			printf("Hexa-Decimal(16)"); 
		break;
    }
    
    // Input
    printf("\n-----------------------------------------------------------------------------");
	switch(input_choice)
    {
        case 1:
            printf("\nInput Binary Number: ");
            scanf("%s", number);
            if(binaryinput_check(number) == 0)
				{
					clear_screen();
				    printf("\nINVALID BINARY NUMBER!\n");
	 				printf("\n LOADING PLEASE WAIT..... \n");
				    Sleep(1000);
				    goto num_input;
				}
            break;

        case 2:
            printf("\nInput Decimal Number: ");
            scanf("%s", number);
            if(decimalinput_check(number) == 0)
				{
					clear_screen();
				    printf("\nINVALID Decimal NUMBER!\n");
	 				printf("\n LOADING PLEASE WAIT..... \n");
				    Sleep(1000);
				    goto num_input;
				}
            break;

        case 3:
            printf("\nInput Octal Number: ");
            scanf("%s", number);
            if(octalinput_check(number) == 0)
				{
					clear_screen();
				    printf("\nINVALID Octal NUMBER!\n");
	 				printf("\n LOADING PLEASE WAIT..... \n");
				    Sleep(1000);
				    goto num_input;
				}
            break;

        case 4:
            printf("\nInput Hexa-Decimal Number: ");
            scanf("%s", number);
            if(hexainput_check(number) == 0)
				{
					clear_screen();
				    printf("\nINVALID Hexa-Decimal NUMBER!\n");
	 				printf("\n LOADING PLEASE WAIT..... \n");
				    Sleep(1000);
				    goto num_input;
				}
            break;
    }
	number_conv_output();
}

void bitwise_ope_input()
{
	bit_start:
	clear_screen();
	
	printf("██████╗ ██╗████████╗██╗    ██╗██╗███████╗███████╗    ███████╗██╗   ██╗███████╗\n");
	printf("██╔══██╗██║╚══██╔══╝██║    ██║██║██╔════╝██╔════╝    ██╔════╝╚██╗ ██╔╝██╔════╝\n");
	printf("██████╔╝██║   ██║   ██║ █╗ ██║██║███████╗█████╗      ███████╗ ╚████╔╝ ███████╗\n");
	printf("██╔══██╗██║   ██║   ██║███╗██║██║╚════██║██╔══╝      ╚════██║  ╚██╔╝  ╚════██║\n");
	printf("██████╔╝██║   ██║   ╚███╔███╔╝██║███████║███████╗    ███████║   ██║   ███████║\n");
	printf("╚═════╝ ╚═╝   ╚═╝    ╚══╝╚══╝ ╚═╝╚══════╝╚══════╝    ╚══════╝   ╚═╝   ╚══════╝\n");
	
		printf("-----------------------------------------------------------------------------");
		printf("\nInput Base");
		printf("\n[1] AND");
		printf("\n[2] OR");
		printf("\n[3] NOT");
		printf("\n[4] XOR");
		printf("\n[5] X-NOR");
		printf("\n[6] NAND");
		printf("\n[7] Left Shift");
		printf("\n[8] Right Shift");
		printf("\n[9] Count Set Bits");
		printf("\n[0] Back");
		printf("\n-----------------------------------------------------------------------------");
		printf("\nEnter choice: ");
		
	if(scanf("%d", &choice1) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto bit_start;
	} 
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
		
		default:
			clear_screen();
			printf("\n INVALID CHOICE !!!!! \n");
			printf("\n LOADING PLEASE WAIT..... \n");
			Sleep(1000); 
			goto bit_start;
		break;
	}	
	bitwise_ope_output();
}