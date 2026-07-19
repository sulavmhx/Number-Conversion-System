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

	InitWindow(SCREEN_W, SCREEN_H, "Number Conversion");
	ToggleFullscreen();
	InitializeAdmin();

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
            case LOGIN_SCREEN:
                BeginDrawing();
                DrawMenuBackdrop();
                login_screen();
                EndDrawing();
                break;

            case SIGNUP_SCREEN:
                BeginDrawing();
                DrawMenuBackdrop();
                signup_screen();
                EndDrawing();
                break;

            case FORGOT_SCREEN:
                BeginDrawing();
                DrawMenuBackdrop();
                forgot_password_screen();
                EndDrawing();
                break;

            case SETTINGS_SCREEN:
                BeginDrawing();
                DrawMenuBackdrop();
                settings_screen();
                EndDrawing();
                break;

            case ADMIN_MENU:
                BeginDrawing();
                ClearBackground(BLACK);
                admin_panel();
                EndDrawing();
                break;

            case ADMIN_NUM_LOGS:
                number_logs_screen();
                currentScreen = ADMIN_MENU;
                break;

            case ADMIN_BIT_LOGS:
                bitwise_logs_screen();
                currentScreen = ADMIN_MENU;
                break;

            case USER_MENU:
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
                break;
        }
    }

    CloseWindow();
    return 0;
}