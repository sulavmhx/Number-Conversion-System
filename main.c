#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "Global.h"
#include "Utility.h"
#include "Input.h"
#include "Output.h"
#include "FileHandle.h"

int main()
{
	while(1)
	{
	start:

	clear_screen();
	time_t now = time(NULL);
	char *string = ctime(&now);
	
	printf("Started Program on:\n%s\n",string);
	
	printf("\n[1] Number Conversion System");
	printf("\n[2] BITWISE Tools");
	printf("\n[3] View Number Conversion Logs");
	printf("\n[4] View Bitwise Tools Logs");
	printf("\n[5] Exit");
	printf("\nEnter Choice: ");
	int choice;
	if(scanf("%d",&choice) != 1)
	{
   		clear_buffer();
   		clear_screen();
  		printf("\nINVALID INPUT!!!!!!\n");
		printf("\n LOADING PLEASE WAIT..... \n");
 		Sleep(1000);
    	goto start;
	}
	
	switch(choice)
	{
		case 1:	
			number_conv_input(); 
		break;
		
		case 2:
			bitwise_ope_input();
		break;
		
		case 3:
			Num_logs_output();
		break;
		
		case 4:
			Bit_logs_output();
		break;
		
		case 5:
			exit(0);
		break;
		
		default:
			clear_screen();
			printf("\n INVALID CHOICE !!!!! \n");
			printf("\n LOADING PLEASE WAIT..... \n");
			Sleep(1000); 
			goto start;
		break;
			
	}
	
	}
	
	return 0;
}