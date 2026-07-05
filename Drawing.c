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

// Mathematically calculated vertical layout for buttons (centered on screen)
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
            (SCREEN_W - MeasureText("& BITWISE TOOLS", 40)) / 2,
            TITLE_Y + 65, 40, LIGHTGRAY);

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
    int letterCount = 0;
    int key;

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
			    // Wait until Enter is released
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

        DrawRectangle(BOX_X, INPUT_BOX_Y, BOX_W, BOX_H, DARKGRAY);
        DrawRectangleLines(BOX_X, INPUT_BOX_Y, BOX_W, BOX_H, WHITE);

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
		
		// Allow Enter to return to the menu only after the key
		// from the previous screen has been released.
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

    int y;
    int scroll = 0;

	while (!WindowShouldClose())
	{
	    fp = fopen(NUM_LOG_FILE, "rb");
	
        updateTime();

        Vector2 mouse = GetMousePosition();

        scroll += (int)GetMouseWheelMove() * 30;

        if(scroll > 0)
            scroll = 0;

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