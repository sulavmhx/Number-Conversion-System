#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Input.h"
#include "Output.h"
#include "Global.h"
#include "NumConv.h"
#include "Bitwise.h"
#include "Utility.h"
#include "FileHandle.h"

void number_conv_output()
{
    // output
    clear_screen();
	printf("███╗   ██╗██╗   ██╗███╗   ███╗     ██████╗ ██████╗ ███╗   ██╗██╗   ██╗███████╗██████╗ ████████╗███████╗██████╗ \n");
	printf("████╗  ██║██║   ██║████╗ ████║    ██╔════╝██╔═══██╗████╗  ██║██║   ██║██╔════╝██╔══██╗╚══██╔══╝██╔════╝██╔══██╗\n");
	printf("██╔██╗ ██║██║   ██║██╔████╔██║    ██║     ██║   ██║██╔██╗ ██║██║   ██║█████╗  ██████╔╝   ██║   █████╗  ██████╔╝\n");
	printf("██║╚██╗██║██║   ██║██║╚██╔╝██║    ██║     ██║   ██║██║╚██╗██║╚██╗ ██╔╝██╔══╝  ██╔══██╗   ██║   ██╔══╝  ██╔══██╗\n");
	printf("██║ ╚████║╚██████╔╝██║ ╚═╝ ██║    ╚██████╗╚██████╔╝██║ ╚████║ ╚████╔╝ ███████╗██║  ██║   ██║   ███████╗██║  ██║\n");
	printf("╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝\n");
	
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
    
    switch(output_choice)
    {
    	case 1:
    		binary();
            printf("\nOutput Binary Number: %s",result_bin);
            break;

        case 2:
        	decimal();
            printf("\nOutput Decimal Number: %ld",result_dec);
            break;

        case 3:
        	octal();
            printf("\nOutput Octal Number: %lo",result_oct);
            break;

        case 4:
        	hexa_decimal();
            printf("\nOutput Hexa-Decimal Number: %lX",result_hexa);
            break;
    }
    Num_logs_input();
    
	printf("\n========================================");

	printf("\n[0] Back To Number Conversion System");
	printf("\n[1] Exit");
	printf("\nEnter Choice: ");

	if(scanf("%d",&back) != 1)
	{
 		clear_buffer();
   		return;
	}

		switch(back)
		{
	    	case 1:
	    		return;
	       	break;
	
	    	case 2:
	        	exit(0);
	        break;
	
	    	default:
	        	return;
	        break;
		}
	}
void bitwise_ope_output()
{
	printf("██████╗ ██╗████████╗██╗    ██╗██╗███████╗███████╗    ███████╗██╗   ██╗███████╗\n");
	printf("██╔══██╗██║╚══██╔══╝██║    ██║██║██╔════╝██╔════╝    ██╔════╝╚██╗ ██╔╝██╔════╝\n");
	printf("██████╔╝██║   ██║   ██║ █╗ ██║██║███████╗█████╗      ███████╗ ╚████╔╝ ███████╗\n");
	printf("██╔══██╗██║   ██║   ██║███╗██║██║╚════██║██╔══╝      ╚════██║  ╚██╔╝  ╚════██║\n");
	printf("██████╔╝██║   ██║   ╚███╔███╔╝██║███████║███████╗    ███████║   ██║   ███████║\n");
	printf("╚═════╝ ╚═╝   ╚═╝    ╚══╝╚══╝ ╚═╝╚══════╝╚══════╝    ╚══════╝   ╚═╝   ╚══════╝\n");
	switch(choice1)
	{
		case 1:
			printf("\nResult AND = %u", result);
		break;
		
		case 2:
			printf("\nResult OR = %u", result);
		break;
		
		case 3:
			printf("\nResult NOT = %u", result);
		break;
		
		case 4:
			printf("\nResult XOR = %u", result);
		break;
		
		case 5:
			printf("\nResult X-NOR = %u", result);
		break;
		
		case 6:
			printf("\nResult NAND = %u", result);
		break;
		
		case 7:
			printf("\nResult Left Shift = %u", result);
		break;
		
		case 8:
			printf("\nResult Right Shift = %u", result);
		break;
		
		case 9:
			printf("\nSet Bits = %d", count);
		break;
		
		default:
			clear_screen();
			printf("\n INVALID CHOICE !!!!! \n");
			printf("\n LOADING PLEASE WAIT..... \n");
			Sleep(1000); 
			bitwise_ope_input();
		break;
	}
	
	Bit_logs_input();
	
	printf("\n========================================");
	
	printf("\n[0] Back To BitTools System");
	printf("\n[1] Exit");
	printf("\nEnter Choice: ");
	
	if(scanf("%d",&back) != 1)
	{
 		clear_buffer();
   		return;
	}

		switch(back)
		{
	    	case 0:
	    		return;
	       	break;
	
	    	case 1:
	        	exit(0);
	        break;
	
	    	default:
	        	return;
	        break;
		}
}