#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "raylib.h"

#include "Global.h"
#include "Utility.h"
#include "Drawing.h"
#include "Input.h"
#include "FileHandle.h"
#include "NumConv.h"

#define SCREEN_W        1920
#define SCREEN_H        1080

#define TITLE_SIZE      58
#define SUBTITLE_SIZE   38
#define TIME_SIZE       28
#define TEXT_SIZE       32
#define BUTTON_TEXT_SIZE 34
#define SMALL_TEXT_SIZE 22

#define LINE_GAP        55

// Centered Headers
#define TITLE_Y         80
#define SUBTITLE_Y      (TITLE_Y + LINE_GAP)
#define TIME_Y          (SUBTITLE_Y + LINE_GAP)

#define BTN_W           700
#define BTN_H           80
#define BTN_GAP         25
#define BTN_X           ((SCREEN_W - BTN_W) / 2)

// calculated vertical layout for buttons (centered on screen)
#define MENU_CONTENT_Y  290
#define BTN1_Y          MENU_CONTENT_Y
#define BTN2_Y          (BTN1_Y + BTN_H + BTN_GAP)
#define BTN3_Y          (BTN2_Y + BTN_H + BTN_GAP)
#define BTN4_Y          (BTN3_Y + BTN_H + BTN_GAP)
#define BTN5_Y          (BTN4_Y + BTN_H + BTN_GAP)

// For screens with 4 buttons (Base selectors)
#define BASE_CONTENT_Y  342
#define BASE_BTN1_Y     BASE_CONTENT_Y
#define BASE_BTN2_Y     (BASE_BTN1_Y + BTN_H + BTN_GAP)
#define BASE_BTN3_Y     (BASE_BTN2_Y + BTN_H + BTN_GAP)
#define BASE_BTN4_Y     (BASE_BTN3_Y + BTN_H + BTN_GAP)

// bitwise row and column 

#define BIT_BTN_W      420
#define BIT_BTN_H      80

#define BIT_COL1_X     250
#define BIT_COL2_X     ((SCREEN_W - BIT_BTN_W) / 2)
#define BIT_COL3_X     (SCREEN_W - BIT_BTN_W - 250)

#define BIT_ROW1_Y     340
#define BIT_ROW2_Y     (BIT_ROW1_Y + BIT_BTN_H + 40)
#define BIT_ROW3_Y     (BIT_ROW2_Y + BIT_BTN_H + 40)

#define BOX_W           850
#define BOX_H           70
#define BOX_X           ((SCREEN_W - BOX_W) / 2)

// Centered input/output layouts
#define CONFIG_INFO_Y   270
#define INPUT_BOX_Y     420
#define OUTPUT_BOX_Y    600

#define BACK_W          220
#define BACK_H          70
#define BACK_X          60
#define BACK_Y          950

void menu(void)
{
    while(!WindowShouldClose())
    {
        updateTime();

        Vector2 mouse = GetMousePosition();

        Rectangle btnNumConv = {BTN_X, BTN1_Y, BTN_W, BTN_H};
        Rectangle btnBitwise = {BTN_X, BTN2_Y, BTN_W, BTN_H};
        Rectangle btnNumLogs = {BTN_X, BTN3_Y, BTN_W, BTN_H};
        Rectangle btnBitLogs = {BTN_X, BTN4_Y, BTN_W, BTN_H};
        Rectangle btnExit    = {BTN_X, BTN5_Y, BTN_W, BTN_H};

        choice = 0;

        if(CheckCollisionPointRec(mouse, btnNumConv) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			choice = 1;
			
        if(CheckCollisionPointRec(mouse, btnBitwise) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			choice = 2;
			
        if(CheckCollisionPointRec(mouse, btnNumLogs) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			choice = 3;
			
        if(CheckCollisionPointRec(mouse, btnBitLogs) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			choice = 4;
			
        if(CheckCollisionPointRec(mouse, btnExit)    && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			choice = 5;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("NUMBER CONVERSION SYSTEM",
            (SCREEN_W - MeasureText("NUMBER CONVERSION SYSTEM", TITLE_SIZE)) / 2,
            TITLE_Y, TITLE_SIZE, GREEN);

        DrawText("& BITWISE TOOLS",
            (SCREEN_W - MeasureText("& BITWISE TOOLS", TITLE_SIZE)) / 2,
            TITLE_Y + 65, TITLE_SIZE, GREEN);

        DrawText(currentTime,
            (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
            TITLE_Y + 125, SUBTITLE_SIZE, GRAY);

        DrawRectangleRec(btnNumConv, CheckCollisionPointRec(mouse, btnNumConv) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnBitwise, CheckCollisionPointRec(mouse, btnBitwise) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnNumLogs, CheckCollisionPointRec(mouse, btnNumLogs) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnBitLogs, CheckCollisionPointRec(mouse, btnBitLogs) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnExit, CheckCollisionPointRec(mouse, btnExit) ? RED : MAROON);
        
        DrawText("Number Conversion",
            BTN_X + (BTN_W - MeasureText("Number Conversion", BUTTON_TEXT_SIZE)) / 2,
            BTN1_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Bitwise Tools",
            BTN_X + (BTN_W - MeasureText("Bitwise Tools", BUTTON_TEXT_SIZE)) / 2,
            BTN2_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Number Logs",
            BTN_X + (BTN_W - MeasureText("Number Logs", BUTTON_TEXT_SIZE)) / 2,
            BTN3_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Bitwise Logs",
            BTN_X + (BTN_W - MeasureText("Bitwise Logs", BUTTON_TEXT_SIZE)) / 2,
            BTN4_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Exit",
            BTN_X + (BTN_W - MeasureText("Exit", BUTTON_TEXT_SIZE)) / 2,
            BTN5_Y + 20, BUTTON_TEXT_SIZE, WHITE);
            
        DrawText("CONTRIBUTORS: @sulavmhx, @saurav112-dot",
            BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
            BACK_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        EndDrawing();

        if(choice != 0) 
			return;
    }
}

void number_conv_inputbase(void)
{
    input_choice = -1;

    while(!WindowShouldClose())
    {
        updateTime();

        Vector2 mouse = GetMousePosition();

        Rectangle btnBin  = {BTN_X, BASE_BTN1_Y, BTN_W, BTN_H};
        Rectangle btnDec  = {BTN_X, BASE_BTN2_Y, BTN_W, BTN_H};
        Rectangle btnOct  = {BTN_X, BASE_BTN3_Y, BTN_W, BTN_H};
        Rectangle btnHex  = {BTN_X, BASE_BTN4_Y, BTN_W, BTN_H};
        Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

        if(CheckCollisionPointRec(mouse, btnBin)  && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			input_choice = 1;
			
        if(CheckCollisionPointRec(mouse, btnDec)  && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			input_choice = 2;
			
        if(CheckCollisionPointRec(mouse, btnOct)  && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			input_choice = 3;
			
        if(CheckCollisionPointRec(mouse, btnHex)  && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			input_choice = 4;
			
        if(CheckCollisionPointRec(mouse, btnBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			input_choice = 0;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("NUMBER CONVERSION SYSTEM",
            (SCREEN_W - MeasureText("NUMBER CONVERSION SYSTEM", TITLE_SIZE)) / 2,
            TITLE_Y, TITLE_SIZE, GREEN);

        DrawText(currentTime,
            (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
            SUBTITLE_Y, SUBTITLE_SIZE, GRAY);

        DrawText("SELECT",
            (SCREEN_W - MeasureText("SELECT", 34)) / 2,
            TIME_Y, 34, LIGHTGRAY);
        
		DrawText("INPUT BASE",
		    (SCREEN_W - MeasureText("INPUT BASE", 50)) / 2,
		    TIME_Y + 50,
		    50,
		    YELLOW);
            
        DrawRectangleRec(btnBin, CheckCollisionPointRec(mouse, btnBin) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnDec, CheckCollisionPointRec(mouse, btnDec) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnOct, CheckCollisionPointRec(mouse, btnOct) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnHex, CheckCollisionPointRec(mouse, btnHex) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnBack, CheckCollisionPointRec(mouse, btnBack) ? RED : MAROON);

        DrawText("Binary",
            BTN_X + (BTN_W - MeasureText("Binary", BUTTON_TEXT_SIZE)) / 2,
            BASE_BTN1_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Decimal",
            BTN_X + (BTN_W - MeasureText("Decimal", BUTTON_TEXT_SIZE)) / 2,
            BASE_BTN2_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Octal",
            BTN_X + (BTN_W - MeasureText("Octal", BUTTON_TEXT_SIZE)) / 2,
            BASE_BTN3_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Hexadecimal",
            BTN_X + (BTN_W - MeasureText("Hexadecimal", BUTTON_TEXT_SIZE)) / 2,
            BASE_BTN4_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Back",
            BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
            BACK_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        EndDrawing();

        if(input_choice == 0)
        {
            choice = 0;
            return;
        }
        if(input_choice != -1) break;
    }

    number_conv_outputbase();
}

void number_conv_outputbase(void)
{
    output_choice = -1;

    while(!WindowShouldClose())
    {
        updateTime();

        Vector2 mouse = GetMousePosition();

        Rectangle btnBin  = {BTN_X, BASE_BTN1_Y, BTN_W, BTN_H};
        Rectangle btnDec  = {BTN_X, BASE_BTN2_Y, BTN_W, BTN_H};
        Rectangle btnOct  = {BTN_X, BASE_BTN3_Y, BTN_W, BTN_H};
        Rectangle btnHex  = {BTN_X, BASE_BTN4_Y, BTN_W, BTN_H};
        Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

        if(CheckCollisionPointRec(mouse, btnBin)  && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			output_choice = 1;
			
        if(CheckCollisionPointRec(mouse, btnDec)  && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			output_choice = 2;
        
        if(CheckCollisionPointRec(mouse, btnOct)  && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			output_choice = 3;
			
        if(CheckCollisionPointRec(mouse, btnHex)  && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			output_choice = 4;
        
        if(CheckCollisionPointRec(mouse, btnBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
			output_choice = 0;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("NUMBER CONVERSION SYSTEM",
            (SCREEN_W - MeasureText("NUMBER CONVERSION SYSTEM", TITLE_SIZE)) / 2,
            TITLE_Y, TITLE_SIZE, GREEN);

        DrawText(currentTime,
            (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
            SUBTITLE_Y, SUBTITLE_SIZE, GRAY);

        DrawText("SELECT",
            (SCREEN_W - MeasureText("SELECT", 34)) / 2,
            TIME_Y, 34, LIGHTGRAY);
        
        DrawText("OUTPUT BASE",
            (SCREEN_W - MeasureText("OUTPUT BASE", 50)) / 2,
            TIME_Y + 50, 50, YELLOW);		            

        DrawRectangleRec(btnBin, CheckCollisionPointRec(mouse, btnBin) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnDec, CheckCollisionPointRec(mouse, btnDec) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnOct, CheckCollisionPointRec(mouse, btnOct) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnHex, CheckCollisionPointRec(mouse, btnHex) ? SKYBLUE : DARKBLUE);
        DrawRectangleRec(btnBack, CheckCollisionPointRec(mouse, btnBack) ? RED : MAROON);

        DrawText("Binary",
            BTN_X + (BTN_W - MeasureText("Binary", BUTTON_TEXT_SIZE)) / 2,
            BASE_BTN1_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Decimal",
            BTN_X + (BTN_W - MeasureText("Decimal", BUTTON_TEXT_SIZE)) / 2,
            BASE_BTN2_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Octal",
            BTN_X + (BTN_W - MeasureText("Octal", BUTTON_TEXT_SIZE)) / 2,
            BASE_BTN3_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Hexadecimal",
            BTN_X + (BTN_W - MeasureText("Hexadecimal", BUTTON_TEXT_SIZE)) / 2,
            BASE_BTN4_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Back",
            BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
            BACK_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        EndDrawing();

        if(output_choice == 0)
        {
            choice = 0;
            return;
        }
        if(output_choice != -1) break;
    }

    number_conv_inputscreen();
}

void number_conv_inputscreen(void)
{

    Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

    number[0] = '\0';

    while (!WindowShouldClose())
    {
        updateTime();

        Vector2 mouse = GetMousePosition();

        while ((key = GetCharPressed()) > 0)
        {
            if (letterCount < 63 && key >= 32 && key <= 126)
            {
                number[letterCount] = (char)key;
                letterCount++;
                number[letterCount] = '\0';
            }
        }

        if (IsKeyPressed(KEY_BACKSPACE) && letterCount > 0)
        {
            letterCount--;
            number[letterCount] = '\0';
        }

        if (IsKeyPressed(KEY_ESCAPE))
        {
            choice = 0;
            return;
        }

        if (CheckCollisionPointRec(mouse, btnBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            choice = 0;
            return;
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            invalid = 0;

            switch (input_choice)
            {
                case 1:
                    if (!binaryinput_check(number))
                        invalid = 1;
                    break;

                case 2:
                    if (!decimalinput_check(number))
                        invalid = 1;
                    break;

                case 3:
                    if (!octalinput_check(number))
                        invalid = 1;
                    break;

                case 4:
                    if (!hexainput_check(number))
                        invalid = 1;
                    break;
            }

			if (!invalid)
			{
			    num_conv_input();
				Num_logs_input();
			    
			    while (IsKeyDown(KEY_ENTER))
			    {
			        BeginDrawing();
			        EndDrawing();
			    }
			
			    number_conv_outputscreen();
			    return;
			}
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("NUMBER CONVERSION SYSTEM",
                 (SCREEN_W - MeasureText("NUMBER CONVERSION SYSTEM", TITLE_SIZE)) / 2,
                 TITLE_Y,
                 TITLE_SIZE,
                 GREEN);

        DrawText(currentTime,
                 (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
                 SUBTITLE_Y,
                 SUBTITLE_SIZE,
                 GRAY);

        DrawText("INPUT BASE :", 500, 220, TEXT_SIZE, WHITE);

        switch (input_choice)
        {
            case 1:
                DrawText("Binary [2]", 760, 220, TEXT_SIZE, GREEN);
                break;

            case 2:
                DrawText("Decimal [10]", 760, 220, TEXT_SIZE, GREEN);
                break;

            case 3:
                DrawText("Octal [8]", 760, 220, TEXT_SIZE, GREEN);
                break;

            case 4:
                DrawText("Hexadecimal [16]", 760, 220, TEXT_SIZE, GREEN);
                break;
        }

        DrawText("OUTPUT BASE :", 500, 280, TEXT_SIZE, WHITE);

        switch (output_choice)
        {
            case 1:
                DrawText(" Binary [2]", 760, 280, TEXT_SIZE, GREEN);
                break;

            case 2:
                DrawText(" Decimal [10]", 760, 280, TEXT_SIZE, GREEN);
                break;

            case 3:
                DrawText(" Octal [8]", 760, 280, TEXT_SIZE, GREEN);
                break;

            case 4:
                DrawText(" Hexadecimal [16]", 760, 280, TEXT_SIZE, GREEN);
                break;
        }

        DrawText("ENTER NUMBER", BOX_X, INPUT_BOX_Y - 40, 24, GREEN);

        DrawRectangle(BOX_X, 
					INPUT_BOX_Y, 
					BOX_W, 
					BOX_H,
					DARKGRAY);
					
        DrawRectangleLines(BOX_X, 
					INPUT_BOX_Y, 
					BOX_W, 
					BOX_H, 
					WHITE);

        DrawText(number,
                 BOX_X + 15,
                 INPUT_BOX_Y + 20,
                 TEXT_SIZE,
                 WHITE);

        DrawRectangleRec(btnBack,
            CheckCollisionPointRec(mouse, btnBack) ? ORANGE : RED);

        DrawText("Back",
                 BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
                 BACK_Y + 20,
                 BUTTON_TEXT_SIZE,
                 WHITE);

        if (invalid)
        {
            DrawText("INVALID INPUT",
                     (SCREEN_W - MeasureText("INVALID INPUT", 24)) / 2,
                     INPUT_BOX_Y + BOX_H + 30,
                     24,
                     RED);
        }
        else
        {
            DrawText("Press ENTER to Continue",
                     (SCREEN_W - MeasureText("Press ENTER to Continue", 22)) / 2,
                     INPUT_BOX_Y + BOX_H + 30,
                     22,
                     GRAY);
        }

        EndDrawing();
    }
}

void number_conv_outputscreen(void)
{
    Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

    while(!WindowShouldClose())
    {
        updateTime();
        Vector2 mouse = GetMousePosition();

		if (IsKeyPressed(KEY_ESCAPE))
		{
		    choice = 0;
		    return;
		}
		
		if (CheckCollisionPointRec(mouse, btnBack) &&
		    IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
		    choice = 0;
		    return;
		}
		
		if (IsKeyPressed(KEY_ENTER))
		{
		    while (IsKeyDown(KEY_ENTER))
		    {
		        BeginDrawing();
		        EndDrawing();
		    }
		
		    choice = 0;
		    return;
		}

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("NUMBER CONVERSION SYSTEM",
                 (SCREEN_W - MeasureText("NUMBER CONVERSION SYSTEM", TITLE_SIZE)) / 2,
                 TITLE_Y, TITLE_SIZE, GREEN);

        DrawText(currentTime,
                 (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
                 SUBTITLE_Y, SUBTITLE_SIZE, GRAY);

        DrawText("RESULT VIEW",
                 (SCREEN_W - MeasureText("RESULT VIEW", 40)) / 2,
                 TIME_Y, 40, LIGHTGRAY);

        DrawText("Input Base :", 520, CONFIG_INFO_Y, TEXT_SIZE, WHITE);

        switch(input_choice)
        {
            case 1: 
				DrawText("Binary [2]", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN); 
			break;
			
            case 2: 
				DrawText("Decimal [10]", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN); 
			break;
			
            case 3: 
				DrawText("Octal [8]", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN); 
			break;
			
            case 4: 
				DrawText("Hexadecimal [16]", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN); 
			break;
        }

        DrawText("Output Base :", 520, CONFIG_INFO_Y + 50, TEXT_SIZE, WHITE);

        switch(output_choice)
        {
            case 1: 
				DrawText("Binary [2]", 760, CONFIG_INFO_Y + 50, TEXT_SIZE, GREEN); 
			break;
			
            case 2: 
				DrawText("Decimal [10]", 760, CONFIG_INFO_Y + 50, TEXT_SIZE, GREEN); 
			break;
			
            case 3: 
				DrawText("Octal [8]", 760, CONFIG_INFO_Y + 50, TEXT_SIZE, GREEN); 
			break;
			
            case 4: 
				DrawText("Hexadecimal [16]", 760, CONFIG_INFO_Y + 50, TEXT_SIZE, GREEN); 
			break;
        }

        DrawText("INPUT NUMBER", BOX_X, INPUT_BOX_Y - 40, 24, GREEN);

        DrawRectangle(BOX_X, INPUT_BOX_Y, BOX_W, BOX_H, DARKGRAY);
        DrawRectangleLines(BOX_X, INPUT_BOX_Y, BOX_W, BOX_H, WHITE);

        DrawText(TextSubtext(number, strlen(number) > 30 ? strlen(number) - 30 : 0, 30),
                 BOX_X + 15, INPUT_BOX_Y + 20, TEXT_SIZE, WHITE);

        DrawText("OUTPUT NUMBER", BOX_X, OUTPUT_BOX_Y - 40, 24, GREEN);

        DrawRectangle(BOX_X, OUTPUT_BOX_Y, BOX_W, BOX_H, DARKGRAY);
        DrawRectangleLines(BOX_X, OUTPUT_BOX_Y, BOX_W, BOX_H, WHITE);

        if(invalid)
        {
            DrawText("INVALID INPUT", BOX_X + 15, OUTPUT_BOX_Y + 20, TEXT_SIZE, RED);
        }
        else
        {
            switch(output_choice)
            {
                case 1:
                    DrawText(TextSubtext(result_bin, strlen(result_bin) > 30 ? strlen(result_bin) - 30 : 0, 30),
                             BOX_X + 15, OUTPUT_BOX_Y + 20, TEXT_SIZE, WHITE);
                    break;

                case 2:
                {
                    char temp[50];
                    sprintf(temp, "%ld", result_dec);
                    DrawText(temp, BOX_X + 15, OUTPUT_BOX_Y + 20, TEXT_SIZE, WHITE);
                    break;
                }

                case 3:
                {
                    char temp[50];
                    sprintf(temp, "%lo", result_oct);
                    DrawText(temp, BOX_X + 15, OUTPUT_BOX_Y + 20, TEXT_SIZE, WHITE);
                    break;
                }

                case 4:
                {
                    char temp[50];
                    sprintf(temp, "%lX", result_hexa);
                    DrawText(temp, BOX_X + 15, OUTPUT_BOX_Y + 20, TEXT_SIZE, WHITE);
                    break;
                }
            }
        }

        DrawRectangleRec(btnBack, CheckCollisionPointRec(mouse, btnBack) ? ORANGE : RED);

        DrawText("Back",
                 BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
                 BACK_Y + 20, BUTTON_TEXT_SIZE, WHITE);

        DrawText("Press ENTER or ESC to return",
                 (SCREEN_W - MeasureText("Press ENTER or ESC to return", 22)) / 2,
                 OUTPUT_BOX_Y + BOX_H + 30, 22, GRAY);

        EndDrawing();
    }
}

void number_logs_screen(void)
{
    FILE *fp;
    NumLog log;

    Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};
    
	while (!WindowShouldClose())
	{
	    fp = fopen(NUM_LOG_FILE, "rb");
	
        updateTime();

        Vector2 mouse = GetMousePosition();


        if(IsKeyPressed(KEY_ESCAPE))
        {
            if(fp != NULL)
                fclose(fp);

            choice = 0;
            return;
        }

        if(CheckCollisionPointRec(mouse, btnBack) &&
           IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if(fp != NULL)
                fclose(fp);

            choice = 0;
            return;
        }

        BeginDrawing();
        ClearBackground(BLACK);

		DrawText("NUMBER CONVERSION LOGS",
		    (SCREEN_W - MeasureText("NUMBER CONVERSION LOGS", TITLE_SIZE)) / 2,
		    40,
		    TITLE_SIZE,
		    YELLOW);
		
		DrawText(currentTime,
		    (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
		    110,
		    SUBTITLE_SIZE,
		    GRAY);

		DrawLine(60,170,1860,170,WHITE);
		
		DrawText("DATE & TIME",80,185,22,GREEN);
		DrawText("INPUT",560,185,22,GREEN);
		DrawText("OUTPUT",900,185,22,GREEN);
		DrawText("IN",1270,185,22,GREEN);
		DrawText("OUT",1440,185,22,GREEN);
		
		DrawLine(60,220,1860,220,WHITE);

        y = 240 + scroll;
        
                if(fp == NULL)
        {
            DrawText("NO NUMBER CONVERSION LOGS FOUND",
                (SCREEN_W - MeasureText("NO NUMBER CONVERSION LOGS FOUND",30))/2,
                500,
                30,
                RED);
        }
        else
        {
		fseek(fp, 0, SEEK_END);
		
		long totalLogs = ftell(fp) / sizeof(NumLog);
		
		minScroll = -(totalLogs * 40 - 700);

		if(minScroll > 0)
		    minScroll = 0;
		    
		scroll += (int)GetMouseWheelMove() * 30;

        if(scroll > 0)
            scroll = 0;
        
        if(scroll < minScroll)
    		scroll = minScroll;
		    
		for(long i = totalLogs - 1; i >= 0; i--)
		{
		    fseek(fp, i * sizeof(NumLog), SEEK_SET);
		
			if(fread(&log, sizeof(NumLog), 1, fp) != 1)
			    continue;
			    
			if(y < 240)
			{
			    y += 40;
			    continue;
			}
			
		    if(y > 900)
		          break;
				
		    char timeStr[50];
		
		    strftime(timeStr,
		             sizeof(timeStr),
		             "%d %b %Y %I:%M %p",
		             localtime(&log.used_time));


                if(((y - 260) / 40) % 2 == 0)
                {
                    DrawRectangle(60, y - 5, 1800, 35, Fade(DARKGRAY, 0.35f));
                }

                DrawText(timeStr,
                         80,
                         y,
                         20,
                         WHITE);

				DrawText(
				    TextSubtext(log.input_number,0,20),
				    560,
				    y,
				    20,
				    GREEN
				);

				DrawText(
				    TextSubtext(log.output_number,0,20),
					900,
                    y,
                    20,
                    GREEN
				);

                switch(log.input_base)
                {
                    case 1:
                        DrawText("BIN",1270,y,20,YELLOW);
                        break;

                    case 2:
                        DrawText("DEC",1270,y,20,YELLOW);
                        break;

                    case 3:
                        DrawText("OCT",1270,y,20,YELLOW);
                        break;

                    case 4:
                        DrawText("HEX",1270,y,20,YELLOW);
                        break;
                }

                switch(log.output_base)
                {
                    case 1:
                        DrawText("BIN",1440,y,20,YELLOW);
                        break;

                    case 2:
                        DrawText("DEC",1440,y,20,YELLOW);
                        break;

                    case 3:
                        DrawText("OCT",1440,y,20,YELLOW);
                        break;

                    case 4:
                        DrawText("HEX",1440,y,20,YELLOW);
                        break;
                }

                y += 40;
            }
        }
        
                DrawRectangleRec(btnBack,
            CheckCollisionPointRec(mouse, btnBack) ? ORANGE : RED);

        DrawText("Back",
            BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
            BACK_Y + 20,
            BUTTON_TEXT_SIZE,
            WHITE);

        DrawText("Use Mouse Wheel to Scroll",
            (SCREEN_W - MeasureText("Use Mouse Wheel to Scroll", 22)) / 2,
            1010,
            22,
            GRAY);

		if(fp != NULL)
		{
		    fclose(fp);
		    fp = NULL;
		}
		
		EndDrawing();
    }

    if(fp != NULL)
    {
        fclose(fp);
    }
}

void bitwise_ope_interface(void)
{
    choice1 = -1;

    while(!WindowShouldClose())
    {
        updateTime();

        Vector2 mouse = GetMousePosition();

	Rectangle btnAnd   = {BIT_COL1_X, BIT_ROW1_Y, BIT_BTN_W, BIT_BTN_H};
	Rectangle btnOr    = {BIT_COL2_X, BIT_ROW1_Y, BIT_BTN_W, BIT_BTN_H};
	Rectangle btnNot   = {BIT_COL3_X, BIT_ROW1_Y, BIT_BTN_W, BIT_BTN_H};
	
	Rectangle btnXor   = {BIT_COL1_X, BIT_ROW2_Y, BIT_BTN_W, BIT_BTN_H};
	Rectangle btnXnor  = {BIT_COL2_X, BIT_ROW2_Y, BIT_BTN_W, BIT_BTN_H};
	Rectangle btnNand  = {BIT_COL3_X, BIT_ROW2_Y, BIT_BTN_W, BIT_BTN_H};
	
	Rectangle btnLeft  = {BIT_COL1_X, BIT_ROW3_Y, BIT_BTN_W, BIT_BTN_H};
	Rectangle btnRight = {BIT_COL2_X, BIT_ROW3_Y, BIT_BTN_W, BIT_BTN_H};
	Rectangle btnCount = {BIT_COL3_X, BIT_ROW3_Y, BIT_BTN_W, BIT_BTN_H};

        Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

        if(CheckCollisionPointRec(mouse, btnAnd) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 1;

        if(CheckCollisionPointRec(mouse, btnOr) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 2;

        if(CheckCollisionPointRec(mouse, btnNot) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 3;

        if(CheckCollisionPointRec(mouse, btnXor) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 4;

        if(CheckCollisionPointRec(mouse, btnXnor) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 5;

        if(CheckCollisionPointRec(mouse, btnNand) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 6;

        if(CheckCollisionPointRec(mouse, btnLeft) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 7;

        if(CheckCollisionPointRec(mouse, btnRight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 8;

        if(CheckCollisionPointRec(mouse, btnCount) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 9;

        if(CheckCollisionPointRec(mouse, btnBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            choice1 = 0;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("BITWISE TOOLS",
            (SCREEN_W - MeasureText("BITWISE TOOLS", TITLE_SIZE)) / 2,
            TITLE_Y,
            TITLE_SIZE,
            GREEN);

        DrawText(currentTime,
            (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
            SUBTITLE_Y,
            SUBTITLE_SIZE,
            GRAY);

        DrawText("SELECT",
            (SCREEN_W - MeasureText("SELECT", 34)) / 2,
            TIME_Y,
            34,
            LIGHTGRAY);

        DrawText("BITWISE OPERATION",
            (SCREEN_W - MeasureText("BITWISE OPERATION", 50)) / 2,
            TIME_Y + 50,
            50,
            YELLOW);

        DrawRectangleRec(btnAnd,
            CheckCollisionPointRec(mouse, btnAnd) ? SKYBLUE : DARKBLUE);

        DrawRectangleRec(btnOr,
            CheckCollisionPointRec(mouse, btnOr) ? SKYBLUE : DARKBLUE);

        DrawRectangleRec(btnNot,
            CheckCollisionPointRec(mouse, btnNot) ? SKYBLUE : DARKBLUE);

        DrawRectangleRec(btnXor,
            CheckCollisionPointRec(mouse, btnXor) ? SKYBLUE : DARKBLUE);

        DrawRectangleRec(btnXnor,
            CheckCollisionPointRec(mouse, btnXnor) ? SKYBLUE : DARKBLUE);

        DrawRectangleRec(btnNand,
            CheckCollisionPointRec(mouse, btnNand) ? SKYBLUE : DARKBLUE);

        DrawRectangleRec(btnLeft,
            CheckCollisionPointRec(mouse, btnLeft) ? SKYBLUE : DARKBLUE);

        DrawRectangleRec(btnRight,
            CheckCollisionPointRec(mouse, btnRight) ? SKYBLUE : DARKBLUE);

        DrawRectangleRec(btnCount,
            CheckCollisionPointRec(mouse, btnCount) ? SKYBLUE : DARKBLUE);

        DrawRectangleRec(btnBack,
            CheckCollisionPointRec(mouse, btnBack) ? RED : MAROON);

		DrawText("AND",
		    BIT_COL1_X + (BIT_BTN_W - MeasureText("AND", BUTTON_TEXT_SIZE)) / 2,
		    BIT_ROW1_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);
		
		DrawText("OR",
		    BIT_COL2_X + (BIT_BTN_W - MeasureText("OR", BUTTON_TEXT_SIZE)) / 2,
		    BIT_ROW1_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);
		
		DrawText("NOT",
		    BIT_COL3_X + (BIT_BTN_W - MeasureText("NOT", BUTTON_TEXT_SIZE)) / 2,
		    BIT_ROW1_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);
		
		DrawText("XOR",
		    BIT_COL1_X + (BIT_BTN_W - MeasureText("XOR", BUTTON_TEXT_SIZE)) / 2,
		    BIT_ROW2_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);
		
		DrawText("XNOR",
		    BIT_COL2_X + (BIT_BTN_W - MeasureText("XNOR", BUTTON_TEXT_SIZE)) / 2,
		    BIT_ROW2_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);
		
		DrawText("NAND",
		    BIT_COL3_X + (BIT_BTN_W - MeasureText("NAND", BUTTON_TEXT_SIZE)) / 2,
		    BIT_ROW2_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);
		
		DrawText("LEFT SHIFT",
		    BIT_COL1_X + (BIT_BTN_W - MeasureText("LEFT SHIFT", BUTTON_TEXT_SIZE)) / 2,
		    BIT_ROW3_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);
		
		DrawText("RIGHT SHIFT",
		    BIT_COL2_X + (BIT_BTN_W - MeasureText("RIGHT SHIFT", BUTTON_TEXT_SIZE)) / 2,
		    BIT_ROW3_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);
		
		DrawText("COUNT SET BITS",
		    BIT_COL3_X + (BIT_BTN_W - MeasureText("COUNT SET BITS", BUTTON_TEXT_SIZE)) / 2,
		    BIT_ROW3_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);
		
		DrawText("Back",
		    BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
		    BACK_Y + 20,
		    BUTTON_TEXT_SIZE,
		    WHITE);

        EndDrawing();

        if(choice1 == 0)
        {
            choice = 0;
            return;
        }

        if(choice1 != -1)
            break;
    }

    switch(choice1)
    {
        case 1:
            choice = 1;
            break;

        case 2:
            choice = 2;
            break;

        case 3:
            choice = 3;
            break;

        case 4:
            choice = 4;
            break;

        case 5:
            choice = 5;
            break;

        case 6:
            choice = 6;
            break;

        case 7:
            choice = 7;
            break;

        case 8:
            choice = 8;
            break;

        case 9:
            choice = 9;
            break;
    }

   bitwise_ope_inputscreen();
}

void bitwise_ope_inputscreen(void)
{
    Rectangle box1 = {BOX_X, INPUT_BOX_Y, BOX_W, BOX_H};
    Rectangle box2 = {BOX_X, INPUT_BOX_Y + 120, BOX_W, BOX_H};
    Rectangle boxShift = {BOX_X, INPUT_BOX_Y + 120, BOX_W, BOX_H};

    Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

    number1[0] = '\0';
    number2[0] = '\0';
    shiftText[0] = '\0';

    while(!WindowShouldClose())
    {
        updateTime();

        Vector2 mouse = GetMousePosition();

        if(CheckCollisionPointRec(mouse, box1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            activeBox = 1;

        if((choice1 != 3) && (choice1 != 9))
        {
            if(CheckCollisionPointRec(mouse, box2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                activeBox = 2;
        }

        if((choice1 == 7) || (choice1 == 8))
        {
            if(CheckCollisionPointRec(mouse, boxShift) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                activeBox = 2;
        }
		if(CheckCollisionPointRec(mouse, btnBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
		    return;   // back out to bitwise_ope_interface()
		}
        if(IsKeyPressed(KEY_TAB))
        {
            if(choice1 == 3 || choice1 == 9)
                activeBox = 1;
            else
                activeBox = (activeBox == 1) ? 2 : 1;
        }

        while((key = GetCharPressed()) > 0)
        {
            if(key >= '0' && key <= '9')
            {
                if(activeBox == 1 && letterCount1 < 63)
                {
                    number1[letterCount1++] = (char)key;
                    number1[letterCount1] = '\0';
                }

                if(activeBox == 2)
                {
                    if((choice1 == 7 || choice1 == 8))
                    {
                        if(letterCountShift < 15)
                        {
                            shiftText[letterCountShift++] = (char)key;
                            shiftText[letterCountShift] = '\0';
                        }
                    }
                    else
                    {
                        if(letterCount2 < 63)
                        {
                            number2[letterCount2++] = (char)key;
                            number2[letterCount2] = '\0';
                        }
                    }
                }
            }
        }

        if(IsKeyPressed(KEY_BACKSPACE))
        {
            if(activeBox == 1 && letterCount1 > 0)
            {
                letterCount1--;
                number1[letterCount1] = '\0';
            }

            if(activeBox == 2)
            {
                if(choice1 == 7 || choice1 == 8)
                {
                    if(letterCountShift > 0)
                    {
                        letterCountShift--;
                        shiftText[letterCountShift] = '\0';
                    }
                }
                else
                {
                    if(letterCount2 > 0)
                    {
                        letterCount2--;
                        number2[letterCount2] = '\0';
                    }
                }
            }
        
		}
		
		if(IsKeyPressed(KEY_ENTER))
		{
		    if(choice1 == 3 || choice1 == 9)
		    {
		        // Single-input ops: one Enter is enough
		        num1 = (unsigned int)strtoul(number1, NULL, 10);
		
		        bitwise_ope_input();
		        bitwise_ope_outputscreen();
		        return;
		    }
		    else if(activeBox == 1)
		    {
		        // First Enter: just move to the second box, don't submit yet
		        activeBox = 2;
		    }
		    else
		    {
		        // Second Enter (activeBox == 2): now submit
		        num1 = (unsigned int)strtoul(number1, NULL, 10);
		
		        if(choice1 == 7 || choice1 == 8)
		            shift = atoi(shiftText);
		        else
		            num2 = (unsigned int)strtoul(number2, NULL, 10);
		
		        bitwise_ope_input();
		        bitwise_ope_outputscreen();
		        return;
		    }
		}
		
		BeginDrawing();
		ClearBackground(BLACK);

        DrawText("BITWISE OPERATION SYSTEM",
            (SCREEN_W - MeasureText("BITWISE OPERATION SYSTEM", TITLE_SIZE))/2,
            TITLE_Y,
            TITLE_SIZE,
            GREEN);

        DrawText(currentTime,
            (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE))/2,
            SUBTITLE_Y,
            SUBTITLE_SIZE,
            GRAY);

        DrawText("OPERATION :",
            500,
            220,
            TEXT_SIZE,
            WHITE);

        switch(choice1)
        {
            case 1:
                DrawText("AND",760,220,TEXT_SIZE,GREEN);
                break;

            case 2:
                DrawText("OR",760,220,TEXT_SIZE,GREEN);
                break;

            case 3:
                DrawText("NOT",760,220,TEXT_SIZE,GREEN);
                break;

            case 4:
                DrawText("XOR",760,220,TEXT_SIZE,GREEN);
                break;

            case 5:
                DrawText("XNOR",760,220,TEXT_SIZE,GREEN);
                break;

            case 6:
                DrawText("NAND",760,220,TEXT_SIZE,GREEN);
                break;

            case 7:
                DrawText("LEFT SHIFT",760,220,TEXT_SIZE,GREEN);
                break;

            case 8:
                DrawText("RIGHT SHIFT",760,220,TEXT_SIZE,GREEN);
                break;

            case 9:
                DrawText("COUNT SET BITS",760,220,TEXT_SIZE,GREEN);
                break;
        }
        
                DrawText("FIRST NUMBER", BOX_X, INPUT_BOX_Y - 35, 24, GREEN);

        DrawRectangleRec(box1,
            activeBox == 1 ? DARKBLUE : DARKGRAY);
        DrawRectangleLinesEx(box1, 2, WHITE);

        DrawText(number1,
            BOX_X + 15,
            INPUT_BOX_Y + 20,
            TEXT_SIZE,
            WHITE);

		if(choice1 == 3 || choice1 == 9)
		{
		    DrawText("(Single input only)",
		        BOX_X,
		        INPUT_BOX_Y + 85,
		        20,
		        GRAY);
		}
		
        else if(choice1 == 7 || choice1 == 8)
        {
            DrawText("SHIFT COUNT",
                BOX_X,
                INPUT_BOX_Y + 85,
                24,
                GREEN);

            DrawRectangleRec(boxShift,
                activeBox == 2 ? DARKBLUE : DARKGRAY);
            DrawRectangleLinesEx(boxShift, 2, WHITE);

            DrawText(shiftText,
                BOX_X + 15,
                INPUT_BOX_Y + 140,
                TEXT_SIZE,
                WHITE);
        }
        else
        {
            DrawText("SECOND NUMBER",
                BOX_X,
                INPUT_BOX_Y + 85,
                24,
                GREEN);

            DrawRectangleRec(box2,
                activeBox == 2 ? DARKBLUE : DARKGRAY);
            DrawRectangleLinesEx(box2, 2, WHITE);

            DrawText(number2,
                BOX_X + 15,
                INPUT_BOX_Y + 140,
                TEXT_SIZE,
                WHITE);
        }

        DrawRectangleRec(btnBack,
            CheckCollisionPointRec(mouse, btnBack) ? ORANGE : RED);

        DrawText("Back",
            BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
            BACK_Y + 20,
            BUTTON_TEXT_SIZE,
            WHITE);

        DrawText("TAB : Switch Input Box",
            BOX_X,
            OUTPUT_BOX_Y + 70,
            22,
            GRAY);

        DrawText("ENTER : Continue",
            BOX_X,
            OUTPUT_BOX_Y + 105,
            22,
            GRAY);

        EndDrawing();
    }
}

void bitwise_ope_outputscreen(void)
{
    Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

    while(!WindowShouldClose())
    {
        updateTime();
        Vector2 mouse = GetMousePosition();

        if(IsKeyPressed(KEY_ESCAPE))
        {
            choice = 0;
            return;
        }

        if(CheckCollisionPointRec(mouse, btnBack) &&
           IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            choice = 0;
            return;
        }

        if(IsKeyPressed(KEY_ENTER))
        {
            while(IsKeyDown(KEY_ENTER))
            {
                BeginDrawing();
                EndDrawing();
            }

            choice = 0;
            return;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("BITWISE OPERATION SYSTEM",
                 (SCREEN_W - MeasureText("BITWISE OPERATION SYSTEM", TITLE_SIZE)) / 2,
                 TITLE_Y, TITLE_SIZE, GREEN);

        DrawText(currentTime,
                 (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
                 SUBTITLE_Y, SUBTITLE_SIZE, GRAY);

        DrawText("RESULT VIEW",
                 (SCREEN_W - MeasureText("RESULT VIEW", 40)) / 2,
                 TIME_Y, 40, LIGHTGRAY);

		DrawText("Operation :", 520, CONFIG_INFO_Y, TEXT_SIZE, WHITE);
		
		switch(choice1)
		{
		    case 1:
		        DrawText("AND (&)", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN);
		        break;
		
		    case 2:
		        DrawText("OR (|)", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN);
		        break;
		
		    case 3:
		        DrawText("NOT (~)", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN);
		        break;
		
		    case 4:
		        DrawText("XOR (^)", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN);
		        break;
		
		    case 5:
		        DrawText("XNOR", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN);
		        break;
		
		    case 6:
		        DrawText("NAND", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN);
		        break;
		
		    case 7:
		        DrawText("LEFT SHIFT (<<)", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN);
		        break;
		
		    case 8:
		        DrawText("RIGHT SHIFT (>>)", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN);
		        break;
		
		    case 9:
		        DrawText("COUNT SET BITS", 760, CONFIG_INFO_Y, TEXT_SIZE, GREEN);
		        break;
		}
		
		DrawText("FIRST VALUE", BOX_X, INPUT_BOX_Y - 40, 24, GREEN);
		
		DrawRectangle(BOX_X, INPUT_BOX_Y, BOX_W, BOX_H, DARKGRAY);
		DrawRectangleLines(BOX_X, INPUT_BOX_Y, BOX_W, BOX_H, WHITE);
		
		DrawText(number1,
		         BOX_X + 15,
		         INPUT_BOX_Y + 20,
		         TEXT_SIZE,
		         WHITE);
		
		if(choice1 != 3 && choice1 != 9)
		{
		    DrawText(choice1 == 7 || choice1 == 8 ?
		             "SHIFT COUNT" : "SECOND VALUE",
		             BOX_X,
		             OUTPUT_BOX_Y - 40,
		             24,
		             GREEN);
		
		    DrawRectangle(BOX_X, OUTPUT_BOX_Y, BOX_W, BOX_H, DARKGRAY);
		    DrawRectangleLines(BOX_X, OUTPUT_BOX_Y, BOX_W, BOX_H, WHITE);
		
		    if(choice1 == 7 || choice1 == 8)
		    {
		        DrawText(shiftText,
		                 BOX_X + 15,
		                 OUTPUT_BOX_Y + 20,
		                 TEXT_SIZE,
		                 WHITE);
		    }
		    else
		    {
		        DrawText(number2,
		                 BOX_X + 15,
		                 OUTPUT_BOX_Y + 20,
		                 TEXT_SIZE,
		                 WHITE);
		    }
		}

        DrawText("RESULT", BOX_X, OUTPUT_BOX_Y + 140, 24, GREEN);

        DrawRectangle(BOX_X, OUTPUT_BOX_Y + 180, BOX_W, BOX_H, DARKGRAY);
        DrawRectangleLines(BOX_X, OUTPUT_BOX_Y + 180, BOX_W, BOX_H, WHITE);

        {
            sprintf(temp, "%u", result);

            DrawText(temp,
                     BOX_X + 15,
                     OUTPUT_BOX_Y + 200,
                     TEXT_SIZE,
                     WHITE);
        }

        DrawRectangleRec(btnBack,
                         CheckCollisionPointRec(mouse, btnBack) ? ORANGE : RED);

        DrawText("Back",
                 BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
                 BACK_Y + 20,
                 BUTTON_TEXT_SIZE,
                 WHITE);

        DrawText("Press ENTER or ESC to return",
                 (SCREEN_W - MeasureText("Press ENTER or ESC to return", 22)) / 2,
                 OUTPUT_BOX_Y + 340,
                 22,
                 GRAY);

        EndDrawing();
    }
}

void bitwise_logs_screen(void)
{
    FILE *fp;
    BitLog log;

    Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

    while (!WindowShouldClose())
    {
        fp = fopen(BIT_LOG_FILE, "rb");

        updateTime();

        Vector2 mouse = GetMousePosition();

        if(IsKeyPressed(KEY_ESCAPE))
        {
            if(fp != NULL)
                fclose(fp);

            choice = 0;
            return;
        }

        if(CheckCollisionPointRec(mouse, btnBack) &&
           IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if(fp != NULL)
                fclose(fp);

            choice = 0;
            return;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("BITWISE OPERATION LOGS",
            (SCREEN_W - MeasureText("BITWISE OPERATION LOGS", TITLE_SIZE)) / 2,
            40,
            TITLE_SIZE,
            YELLOW);

        DrawText(currentTime,
            (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
            110,
            SUBTITLE_SIZE,
            GRAY);

        DrawLine(60,170,1860,170,WHITE);

        DrawText("DATE & TIME",80,185,22,GREEN);
        DrawText("OPERATION",560,185,22,GREEN);
        DrawText("FIRST NUM",900,185,22,GREEN);
        DrawText("SECOND NUM",1150,185,22,GREEN);
        DrawText("RESULT",1440,185,22,GREEN);

        DrawLine(60,220,1860,220,WHITE);

        y = 240 + scroll;

        if(fp == NULL)
        {
            DrawText("NO BITWISE OPERATION LOGS FOUND",
                (SCREEN_W - MeasureText("NO BITWISE OPERATION LOGS FOUND",30))/2,
                500,
                30,
                RED);
        }
        else
        {
            fseek(fp, 0, SEEK_END);

            long totalLogs = ftell(fp) / sizeof(BitLog);

            minScroll = -(totalLogs * 40 - 700);

            if(minScroll > 0)
                minScroll = 0;

            scroll += (int)GetMouseWheelMove() * 30;

            if(scroll > 0)
                scroll = 0;

            if(scroll < minScroll)
                scroll = minScroll;

            for(long i = totalLogs - 1; i >= 0; i--)
            {
                fseek(fp, i * sizeof(BitLog), SEEK_SET);

                if(fread(&log, sizeof(BitLog), 1, fp) != 1)
                    continue;

                if(y < 240)
                {
                    y += 40;
                    continue;
                }

                if(y > 900)
                    break;

                char timeStr[50];

                strftime(timeStr,
                         sizeof(timeStr),
                         "%d %b %Y %I:%M %p",
                         localtime(&log.used_time));

                if(((y - 260) / 40) % 2 == 0)
                {
                    DrawRectangle(60, y - 5, 1800, 35, Fade(DARKGRAY, 0.35f));
                }

                DrawText(timeStr,
                         80,
                         y,
                         20,
                         WHITE);

                char opStr[16];
                switch(log.operation)
                {
                    case 1: 
						strcpy(opStr, "AND");  
						break;
                    case 2: 
						strcpy(opStr, "OR");   
						break;
                    case 3: 
						strcpy(opStr, "NOT"); 
						break;
                    case 4: 
						strcpy(opStr, "XOR");  
						break;
                    case 5: 
						strcpy(opStr, "XNOR"); 
						break;
                    case 6: 
						strcpy(opStr, "NAND"); 
						break;
                    case 7: 
						strcpy(opStr, "LSHIFT"); 
						break;
                    case 8: 
						strcpy(opStr, "RSHIFT"); 
						break;
                    case 9: 
						strcpy(opStr, "COUNT"); 
						break;
                    default: 
						strcpy(opStr, "?"); 
						break;
                }

                DrawText(opStr, 560, y, 20, YELLOW);

                char numStr[32];

                snprintf(numStr, sizeof(numStr), "%u", log.first_number);
                DrawText(numStr, 900, y, 20, GREEN);

                if(log.operation == 3 || log.operation == 9)
                {
                    DrawText("-", 1150, y, 20, GRAY);
                }
                else
                {
                    snprintf(numStr, sizeof(numStr), "%u", log.second_number);
                    DrawText(numStr, 1150, y, 20, GREEN);
                }

                snprintf(numStr, sizeof(numStr), "%u", log.result);
                DrawText(numStr, 1440, y, 20, GREEN);

                y += 40;
            }
        }

        DrawRectangleRec(btnBack,
            CheckCollisionPointRec(mouse, btnBack) ? ORANGE : RED);

        DrawText("Back",
            BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
            BACK_Y + 20,
            BUTTON_TEXT_SIZE,
            WHITE);

        DrawText("Use Mouse Wheel to Scroll",
            (SCREEN_W - MeasureText("Use Mouse Wheel to Scroll", 22)) / 2,
            1010,
            22,
            GRAY);

        if(fp != NULL)
        {
            fclose(fp);
            fp = NULL;
        }

        EndDrawing();
    }

    if(fp != NULL)
    {
        fclose(fp);
    }
}