#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Global.h"
#include "raylib.h"
#include "Utility.h"
#include "FileHandle.h"
#include "Input.h"
#include "Drawing.h"

int main()
{
	InitWindow(1920, 1080, "Number Conversion");
	ToggleFullscreen();

    while (!WindowShouldClose())
    {
        menu();

        switch (choice)
        {
            case 1:
                number_conv_inputbase();
                break;

            case 2:
                bitwise_ope_interface();
                break;

            case 3:
                number_logs_screen();
                break;

            case 4:
			 	bitwise_logs_screen();
                break;

            case 5:
                CloseWindow();
                return 0;
        }
    }

    CloseWindow();
    return 0;
}