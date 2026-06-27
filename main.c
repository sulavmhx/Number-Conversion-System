#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "Global.h"
#include "Utility.h"
#include "Input.h"
#include "Output.h"
#include "FileHandle.h"

int main(void)
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    system("chcp 65001 > nul");

    while (1)
    {
start:

        clear_screen();

        time_t now = time(NULL);
        char *string = ctime(&now);
        
        printf("\nStarted Program on: %s\n", string);
        
	printf("███╗   ██╗██╗   ██╗███╗   ███╗     ██████╗ ██████╗ ███╗   ██╗██╗   ██╗███████╗██████╗ ████████╗███████╗██████╗ \n");
	printf("████╗  ██║██║   ██║████╗ ████║    ██╔════╝██╔═══██╗████╗  ██║██║   ██║██╔════╝██╔══██╗╚══██╔══╝██╔════╝██╔══██╗\n");
	printf("██╔██╗ ██║██║   ██║██╔████╔██║    ██║     ██║   ██║██╔██╗ ██║██║   ██║█████╗  ██████╔╝   ██║   █████╗  ██████╔╝\n");
	printf("██║╚██╗██║██║   ██║██║╚██╔╝██║    ██║     ██║   ██║██║╚██╗██║╚██╗ ██╔╝██╔══╝  ██╔══██╗   ██║   ██╔══╝  ██╔══██╗\n");
	printf("██║ ╚████║╚██████╔╝██║ ╚═╝ ██║    ╚██████╗╚██████╔╝██║ ╚████║ ╚████╔╝ ███████╗██║  ██║   ██║   ███████╗██║  ██║\n");
	printf("╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝\n");
	printf("\n");
	printf(" █████╗  ███╗   ██╗██████╗       ██████╗ ██╗████████╗██╗    ██╗██╗███████╗███████╗      ███████╗██╗   ██╗███████╗\n");
	printf("██╔══██╗ ████╗  ██║██╔══██╗      ██╔══██╗██║╚══██╔══╝██║    ██║██║██╔════╝██╔════╝      ██╔════╝╚██╗ ██╔╝██╔════╝\n");
	printf("███████║ ██╔██╗ ██║██║  ██║      ██████╔╝██║   ██║   ██║ █╗ ██║██║███████╗█████╗        ███████╗ ╚████╔╝ ███████╗\n");
	printf("██╔══██║ ██║╚██╗██║██║  ██║      ██╔══██╗██║   ██║   ██║███╗██║██║╚════██║██╔══╝        ╚════██║  ╚██╔╝  ╚════██║\n");
	printf("██║  ██║ ██║ ╚████║██████╔╝      ██████╔╝██║   ██║   ╚███╔███╔╝██║███████║███████╗      ███████║   ██║   ███████║\n");
	printf("╚═╝  ╚═╝ ╚═╝  ╚═══╝╚═════╝       ╚═════╝ ╚═╝   ╚═╝    ╚══╝╚══╝ ╚═╝╚══════╝╚══════╝      ╚══════╝   ╚═╝   ╚══════╝\n");

        printf("\n-------------------------------- MAIN MENU --------------------------------\n");
        printf(" [1] Number Conversion System\n");
        printf(" [2] Bitwise Tools\n");
        printf(" [3] View Number Conversion Logs\n");
        printf(" [4] View Bitwise Tools Logs\n");
        printf(" [5] Exit\n");
        printf("-----------------------------------------------------------------------------");

        printf("\nEnter Choice: ");

        int choice;

        if (scanf("%d", &choice) != 1)
        {
            clear_buffer();
            clear_screen();
            printf("\nINVALID INPUT!\n");
            printf("Loading...\n");
            Sleep(1000);
            goto start;
        }

        switch (choice)
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
                printf("\nThank you for using the system.\n");
                Sleep(500);
                exit(0);

            default:
                clear_screen();
                printf("\nINVALID CHOICE!\n");
                printf("Loading...\n");
                Sleep(1000);
                goto start;
        }
    }

    return 0;
}