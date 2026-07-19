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

void DrawMenuBackdrop(void) {
	updateTime();

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

	Rectangle btnNumConv = {BTN_X, BTN1_Y, BTN_W, BTN_H};
	Rectangle btnBitwise = {BTN_X, BTN2_Y, BTN_W, BTN_H};
	Rectangle btnNumLogs = {BTN_X, BTN3_Y, BTN_W, BTN_H};
	Rectangle btnBitLogs = {BTN_X, BTN4_Y, BTN_W, BTN_H};
	Rectangle btnExit    = {BTN_X, BTN5_Y, BTN_W, BTN_H};

	DrawRectangleRec(btnNumConv, DARKBLUE);
	DrawRectangleRec(btnBitwise, DARKBLUE);
	DrawRectangleRec(btnNumLogs, DARKBLUE);
	DrawRectangleRec(btnBitLogs, DARKBLUE);
	DrawRectangleRec(btnExit, MAROON);

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

	// Dim the backdrop so the floating card drawn on top of it reads clearly
	DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.65f));
}

void menu(void) {
	while(!WindowShouldClose()) {
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

		DrawAccountBadge();

		EndDrawing();

		if(choice != 0)
			return;

		if(!loggedIn)
			return;
	}
}

void number_conv_inputbase(void) {
	input_choice = -1;

	while(!WindowShouldClose()) {
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

		if(input_choice == 0) {
			choice = 0;
			return;
		}
		if(input_choice != -1) break;
	}

	number_conv_outputbase();
}

void number_conv_outputbase(void) {
	output_choice = -1;

	while(!WindowShouldClose()) {
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

		if(output_choice == 0) {
			choice = 0;
			return;
		}
		if(output_choice != -1) break;
	}

	number_conv_inputscreen();
}

void number_conv_inputscreen(void) {

	Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

	letterCount = 0;
	invalid = 0;
	number[0] = '\0';

	int cursorPos = 0;

	while (!WindowShouldClose()) {
		updateTime();

		Vector2 mouse = GetMousePosition();

		while ((key = GetCharPressed()) > 0) {
			if (letterCount < 63 && key >= 32 && key <= 126) {
				for (int i = letterCount; i > cursorPos; i--)
					number[i] = number[i - 1];

				number[cursorPos] = (char)key;
				letterCount++;
				cursorPos++;
				number[letterCount] = '\0';
			}
		}

		if (IsKeyPressed(KEY_BACKSPACE) && cursorPos > 0) {
			for (int i = cursorPos - 1; i < letterCount - 1; i++)
				number[i] = number[i + 1];

			letterCount--;
			cursorPos--;
			number[letterCount] = '\0';
		}

		if (IsKeyPressed(KEY_DELETE) && cursorPos < letterCount) {
			for (int i = cursorPos; i < letterCount - 1; i++)
				number[i] = number[i + 1];

			letterCount--;
			number[letterCount] = '\0';
		}

		if (IsKeyPressed(KEY_LEFT) && cursorPos > 0)
			cursorPos--;

		if (IsKeyPressed(KEY_RIGHT) && cursorPos < letterCount)
			cursorPos++;

		if (IsKeyPressed(KEY_ESCAPE)) {
			while (IsKeyDown(KEY_ESCAPE)) {
				BeginDrawing();
				EndDrawing();
			}

			choice = 0;
			return;
		}

		if (CheckCollisionPointRec(mouse, btnBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			choice = 0;
			return;
		}

		if (IsKeyPressed(KEY_ENTER)) {
			invalid = 0;

			switch (input_choice) {
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

			if (!invalid) {
				num_conv_input();

				if (!invalid) {
					Num_logs_input();
				}

				while (IsKeyDown(KEY_ENTER)) {
					BeginDrawing();
					EndDrawing();
				}

				number_conv_outputscreen();
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

		switch (input_choice) {
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

		switch (output_choice) {
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

		{
			int start = 0;
			while (MeasureText(number + start, TEXT_SIZE) > BOX_W - 30 && start < cursorPos)
				start++;

			DrawText(number + start,
			         BOX_X + 15,
			         INPUT_BOX_Y + 20,
			         TEXT_SIZE,
			         WHITE);

			if (((int)(GetTime() * 2) % 2) == 0) {
				char saved = number[cursorPos];
				number[cursorPos] = '\0';
				int cursorX = BOX_X + 15 + MeasureText(number + start, TEXT_SIZE);
				number[cursorPos] = saved;

				DrawRectangle(cursorX, INPUT_BOX_Y + 15, 3, TEXT_SIZE, WHITE);
			}
		}

		DrawRectangleRec(btnBack,
		                 CheckCollisionPointRec(mouse, btnBack) ? ORANGE : RED);

		DrawText("Back",
		         BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
		         BACK_Y + 20,
		         BUTTON_TEXT_SIZE,
		         WHITE);

		if (invalid) {
			DrawText("INVALID INPUT",
			         (SCREEN_W - MeasureText("INVALID INPUT", 24)) / 2,
			         INPUT_BOX_Y + BOX_H + 30,
			         24,
			         RED);
		} else {
			DrawText("Press ENTER to Continue",
			         (SCREEN_W - MeasureText("Press ENTER to Continue", 22)) / 2,
			         INPUT_BOX_Y + BOX_H + 30,
			         22,
			         GRAY);
		}
		EndDrawing();
	}

}

void number_conv_outputscreen(void) {
	Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

	while(!WindowShouldClose()) {
		updateTime();
		Vector2 mouse = GetMousePosition();

		if (IsKeyPressed(KEY_ESCAPE)) {
			choice = 0;
			return;
		}

		if (CheckCollisionPointRec(mouse, btnBack) &&
		        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			choice = 0;
			return;
		}

		if (IsKeyPressed(KEY_ENTER)) {
			if(IsKeyReleased(KEY_ENTER)) {
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

		switch(input_choice) {
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

		switch(output_choice) {
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

		if(invalid) {
			DrawText("INVALID INPUT", BOX_X + 15, OUTPUT_BOX_Y + 20, TEXT_SIZE, RED);
		} else {
			switch(output_choice) {
				case 1:
					DrawText(TextSubtext(result_bin, strlen(result_bin) > 30 ? strlen(result_bin) - 30 : 0, 30),
					         BOX_X + 15, OUTPUT_BOX_Y + 20, TEXT_SIZE, WHITE);
					break;

				case 2: {
					char temp[50];
					sprintf(temp, "%lld", result_dec);
					DrawText(temp, BOX_X + 15, OUTPUT_BOX_Y + 20, TEXT_SIZE, WHITE);
					break;
				}

				case 3: {
					char temp[50];
					sprintf(temp, "%llo", result_oct);
					DrawText(temp, BOX_X + 15, OUTPUT_BOX_Y + 20, TEXT_SIZE, WHITE);
					break;
				}

				case 4: {
					char temp[50];
					sprintf(temp, "%llX", result_hexa);
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

void number_logs_screen(void) {
	FILE *fp;
	NumLog log;

	Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

	while (!WindowShouldClose()) {
		fp = fopen(NUM_LOG_FILE, "rb");

		updateTime();

		Vector2 mouse = GetMousePosition();


		if(IsKeyPressed(KEY_ESCAPE)) {
			if(fp != NULL)
				fclose(fp);

			choice = 0;
			return;
		}

		if(CheckCollisionPointRec(mouse, btnBack) &&
		        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
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
		         (SCREEN_W - MeasureText(currentTime, 22)) / 2,
		         95,
		         22,
		         GRAY);
			
		DrawText(TextFormat(currentUser.isAdmin ?
		                    "Viewing: ALL ACCOUNTS (Admin)" :
		                    "			Viewing: %s",currentUser.username),
		         (SCREEN_W - MeasureText("Viewing: ALL ACCOUNTS (Admin)", 22)) / 2,
		         130,
		         22,
		         SKYBLUE);

		DrawLine(60,170,1860,170,WHITE);

		DrawText("DATE & TIME",80,185,22,GREEN);
		DrawText("INPUT",560,185,22,GREEN);
		DrawText("OUTPUT",900,185,22,GREEN);
		DrawText("IN",1270,185,22,GREEN);
		DrawText("OUT",1440,185,22,GREEN);

		if(currentUser.isAdmin)
			DrawText("USER",340,185,22,GREEN);

		DrawLine(60,220,1860,220,WHITE);

		y = 240 + scroll;

		if(fp == NULL) {
			DrawText("NO NUMBER CONVERSION LOGS FOUND",
			         (SCREEN_W - MeasureText("NO NUMBER CONVERSION LOGS FOUND",30))/2,
			         500,
			         30,
			         RED);
		} else {
			fseek(fp, 0, SEEK_END);

			long totalLogs = ftell(fp) / sizeof(NumLog);

			long visibleLogs = 0;

			if(currentUser.isAdmin) {
				visibleLogs = totalLogs;
			} else {
				for(long i = 0; i < totalLogs; i++) {
					fseek(fp, i * sizeof(NumLog), SEEK_SET);

					if(fread(&log, sizeof(NumLog), 1, fp) == 1 &&
					        strcmp(log.username, currentUser.username) == 0) {
						visibleLogs++;
					}
				}
			}

			minScroll = -(visibleLogs * 40 - 700);

			if(minScroll > 0)
				minScroll = 0;

			scroll += (int)GetMouseWheelMove() * 30;

			if(scroll > 0)
				scroll = 0;

			if(scroll < minScroll)
				scroll = minScroll;

			for(long i = totalLogs - 1; i >= 0; i--) {
				fseek(fp, i * sizeof(NumLog), SEEK_SET);

				if(fread(&log, sizeof(NumLog), 1, fp) != 1)
					continue;

				if(!currentUser.isAdmin &&
				        strcmp(log.username, currentUser.username) != 0)
					continue;

				if(y < 240) {
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


				if(((y - 260) / 40) % 2 == 0) {
					DrawRectangle(60, y - 5, 1800, 35, Fade(DARKGRAY, 0.35f));
				}

				DrawText(timeStr,
				         80,
				         y,
				         20,
				         WHITE);

				if(currentUser.isAdmin) {
					DrawText(
					    TextSubtext(log.username,0,15),
					    340,
					    y,
					    20,
					    ORANGE
					);
				}

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

				switch(log.input_base) {
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

				switch(log.output_base) {
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

		if(fp != NULL) {
			fclose(fp);
			fp = NULL;
		}

		EndDrawing();
	}

	if(fp != NULL) {
		fclose(fp);
	}
}

void bitwise_ope_interface(void) {
	choice1 = -1;

	while(!WindowShouldClose()) {
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

		if(choice1 == 0) {
			choice = 0;
			return;
		}

		if(choice1 != -1)
			break;
	}

	switch(choice1) {
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

void bitwise_ope_inputscreen(void) {
	letterCount1=0;
	letterCount2=0;
	letterCountShift=0;
	activeBox=1;

	int cursorPos1 = 0;
	int cursorPos2 = 0;
	int cursorPosShift = 0;

	Vector2 mouse = GetMousePosition();

	Rectangle box1 = {BOX_X, INPUT_BOX_Y, BOX_W, BOX_H};
	Rectangle box2 = {BOX_X, INPUT_BOX_Y + 120, BOX_W, BOX_H};
	Rectangle boxShift = {BOX_X, INPUT_BOX_Y + 120, BOX_W, BOX_H};

	Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

	number1[0] = '\0';
	number2[0] = '\0';
	shiftText[0] = '\0';

	while(!WindowShouldClose()) {
		updateTime();

		Vector2 mouse = GetMousePosition();

		if(CheckCollisionPointRec(mouse, box1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			activeBox = 1;
			cursorPos1 = letterCount1;
		}

		if((choice1 != 3) && (choice1 != 9)) {
			if(CheckCollisionPointRec(mouse, box2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				activeBox = 2;
				cursorPos2 = letterCount2;
			}
		}

		if((choice1 == 7) || (choice1 == 8)) {
			if(CheckCollisionPointRec(mouse, boxShift) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				activeBox = 2;
				cursorPosShift = letterCountShift;
			}
		}
		if(CheckCollisionPointRec(mouse, btnBack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			return;   // back out to bitwise_ope_interface()
		}

		if(IsKeyPressed(KEY_ESCAPE)) {
			return;
		}

		if(IsKeyPressed(KEY_TAB)) {
			if(choice1 == 3 || choice1 == 9) {
				activeBox = 1;
				cursorPos1 = letterCount1;
			} else {
				activeBox = (activeBox == 1) ? 2 : 1;

				if(activeBox == 1)
					cursorPos1 = letterCount1;
				else if(choice1 == 7 || choice1 == 8)
					cursorPosShift = letterCountShift;
				else
					cursorPos2 = letterCount2;
			}
		}

		while((key = GetCharPressed()) > 0) {
			if(key >= '0' && key <= '9') {
				if(activeBox == 1 && letterCount1 < 63) {
					for(int i = letterCount1; i > cursorPos1; i--)
						number1[i] = number1[i - 1];

					number1[cursorPos1] = (char)key;
					letterCount1++;
					cursorPos1++;
					number1[letterCount1] = '\0';
				}

				if(activeBox == 2) {
					if((choice1 == 7 || choice1 == 8)) {
						if(letterCountShift < 15) {
							for(int i = letterCountShift; i > cursorPosShift; i--)
								shiftText[i] = shiftText[i - 1];

							shiftText[cursorPosShift] = (char)key;
							letterCountShift++;
							cursorPosShift++;
							shiftText[letterCountShift] = '\0';
						}
					} else {
						if(letterCount2 < 63) {
							for(int i = letterCount2; i > cursorPos2; i--)
								number2[i] = number2[i - 1];

							number2[cursorPos2] = (char)key;
							letterCount2++;
							cursorPos2++;
							number2[letterCount2] = '\0';
						}
					}
				}
			}
		}

		if(IsKeyPressed(KEY_BACKSPACE)) {
			if(activeBox == 1 && cursorPos1 > 0) {
				for(int i = cursorPos1 - 1; i < letterCount1 - 1; i++)
					number1[i] = number1[i + 1];

				letterCount1--;
				cursorPos1--;
				number1[letterCount1] = '\0';
			}

			if(activeBox == 2) {
				if(choice1 == 7 || choice1 == 8) {
					if(cursorPosShift > 0) {
						for(int i = cursorPosShift - 1; i < letterCountShift - 1; i++)
							shiftText[i] = shiftText[i + 1];

						letterCountShift--;
						cursorPosShift--;
						shiftText[letterCountShift] = '\0';
					}
				} else {
					if(cursorPos2 > 0) {
						for(int i = cursorPos2 - 1; i < letterCount2 - 1; i++)
							number2[i] = number2[i + 1];

						letterCount2--;
						cursorPos2--;
						number2[letterCount2] = '\0';
					}
				}
			}
		}

		if(IsKeyPressed(KEY_DELETE)) {
			if(activeBox == 1 && cursorPos1 < letterCount1) {
				for(int i = cursorPos1; i < letterCount1 - 1; i++)
					number1[i] = number1[i + 1];

				letterCount1--;
				number1[letterCount1] = '\0';
			}

			if(activeBox == 2) {
				if(choice1 == 7 || choice1 == 8) {
					if(cursorPosShift < letterCountShift) {
						for(int i = cursorPosShift; i < letterCountShift - 1; i++)
							shiftText[i] = shiftText[i + 1];

						letterCountShift--;
						shiftText[letterCountShift] = '\0';
					}
				} else {
					if(cursorPos2 < letterCount2) {
						for(int i = cursorPos2; i < letterCount2 - 1; i++)
							number2[i] = number2[i + 1];

						letterCount2--;
						number2[letterCount2] = '\0';
					}
				}
			}
		}

		if(IsKeyPressed(KEY_LEFT)) {
			if(activeBox == 1 && cursorPos1 > 0)
				cursorPos1--;
			else if(activeBox == 2) {
				if(choice1 == 7 || choice1 == 8) {
					if(cursorPosShift > 0) cursorPosShift--;
				} else if(cursorPos2 > 0) cursorPos2--;
			}
		}

		if(IsKeyPressed(KEY_RIGHT)) {
			if(activeBox == 1 && cursorPos1 < letterCount1)
				cursorPos1++;
			else if(activeBox == 2) {
				if(choice1 == 7 || choice1 == 8) {
					if(cursorPosShift < letterCountShift) cursorPosShift++;
				} else if(cursorPos2 < letterCount2) cursorPos2++;
			}
		}

		if(IsKeyPressed(KEY_ENTER)) {
			invalid = 0;

			if(choice1 == 3 || choice1 == 9) {
				if(strlen(number1) == 0) {
					invalid = 1;
				} else {
					num1 = (unsigned int)strtoul(number1, NULL, 10);

					bitwise_ope_input();
					bitwise_ope_outputscreen();
				}
			} else if(activeBox == 1) {
				if(strlen(number1) == 0) {
					invalid = 1;
				} else {
					activeBox = 2;
					cursorPosShift = letterCountShift;
					cursorPos2 = letterCount2;
				}
			} else {
				if(choice1 == 7 || choice1 == 8) {
					if(strlen(shiftText) == 0) {
						invalid = 1;
					} else {
						num1 = (unsigned int)strtoul(number1, NULL, 10);
						shift = atoi(shiftText);

						bitwise_ope_input();
						bitwise_ope_outputscreen();
					}
				} else {
					if(strlen(number2) == 0) {
						invalid = 1;
					} else {
						num1 = (unsigned int)strtoul(number1, NULL, 10);
						num2 = (unsigned int)strtoul(number2, NULL, 10);

						bitwise_ope_input();
						bitwise_ope_outputscreen();
					}
				}
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

		switch(choice1) {
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

		{
			int start1 = 0;
			while(MeasureText(number1 + start1, TEXT_SIZE) > BOX_W - 30 && start1 < cursorPos1)
				start1++;

			DrawText(number1 + start1,
			         BOX_X + 15,
			         INPUT_BOX_Y + 20,
			         TEXT_SIZE,
			         WHITE);

			if(activeBox == 1 && ((int)(GetTime() * 2) % 2) == 0) {
				char saved = number1[cursorPos1];
				number1[cursorPos1] = '\0';
				int cursorX = BOX_X + 15 + MeasureText(number1 + start1, TEXT_SIZE);
				number1[cursorPos1] = saved;

				DrawRectangle(cursorX, INPUT_BOX_Y + 15, 3, TEXT_SIZE, WHITE);
			}
		}

		if(choice1 == 3 || choice1 == 9) {
			DrawText("(Single input only)",
			         BOX_X,
			         INPUT_BOX_Y + 85,
			         20,
			         GRAY);
		}

		else if(choice1 == 7 || choice1 == 8) {
			DrawText("SHIFT COUNT",
			         BOX_X,
			         INPUT_BOX_Y + 85,
			         24,
			         GREEN);

			DrawRectangleRec(boxShift,
			                 activeBox == 2 ? DARKBLUE : DARKGRAY);
			DrawRectangleLinesEx(boxShift, 2, WHITE);

			int startS = 0;
			while(MeasureText(shiftText + startS, TEXT_SIZE) > BOX_W - 30 && startS < cursorPosShift)
				startS++;

			DrawText(shiftText + startS,
			         BOX_X + 15,
			         INPUT_BOX_Y + 140,
			         TEXT_SIZE,
			         WHITE);

			if(activeBox == 2 && ((int)(GetTime() * 2) % 2) == 0) {
				char saved = shiftText[cursorPosShift];
				shiftText[cursorPosShift] = '\0';
				int cursorX = BOX_X + 15 + MeasureText(shiftText + startS, TEXT_SIZE);
				shiftText[cursorPosShift] = saved;

				DrawRectangle(cursorX, INPUT_BOX_Y + 135, 3, TEXT_SIZE, WHITE);
			}
		} else {
			DrawText("SECOND NUMBER",
			         BOX_X,
			         INPUT_BOX_Y + 85,
			         24,
			         GREEN);

			DrawRectangleRec(box2,
			                 activeBox == 2 ? DARKBLUE : DARKGRAY);
			DrawRectangleLinesEx(box2, 2, WHITE);

			int start2 = 0;
			while(MeasureText(number2 + start2, TEXT_SIZE) > BOX_W - 30 && start2 < cursorPos2)
				start2++;

			DrawText(number2 + start2,
			         BOX_X + 15,
			         INPUT_BOX_Y + 140,
			         TEXT_SIZE,
			         WHITE);

			if(activeBox == 2 && ((int)(GetTime() * 2) % 2) == 0) {
				char saved = number2[cursorPos2];
				number2[cursorPos2] = '\0';
				int cursorX = BOX_X + 15 + MeasureText(number2 + start2, TEXT_SIZE);
				number2[cursorPos2] = saved;

				DrawRectangle(cursorX, INPUT_BOX_Y + 135, 3, TEXT_SIZE, WHITE);
			}
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

		if(invalid) {
			DrawText("PLEASE ENTER ALL REQUIRED VALUES",
			         (SCREEN_W - MeasureText("PLEASE ENTER ALL REQUIRED VALUES", 24)) / 2,
			         OUTPUT_BOX_Y + 145,
			         24,
			         RED);
		}
		EndDrawing();
	}
}

void bitwise_ope_outputscreen(void) {
	Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

	while(!WindowShouldClose()) {
		updateTime();
		Vector2 mouse = GetMousePosition();

		if(IsKeyPressed(KEY_ESCAPE)) {
			choice = 0;
			return;
		}

		if(CheckCollisionPointRec(mouse, btnBack) &&
		        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			choice = 0;
			return;
		}

		if(IsKeyPressed(KEY_ENTER)) {
			while(IsKeyDown(KEY_ENTER)) {
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

		switch(choice1) {
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

		if(choice1 != 3 && choice1 != 9) {
			DrawText(choice1 == 7 || choice1 == 8 ?
			         "SHIFT COUNT" : "SECOND VALUE",
			         BOX_X,
			         OUTPUT_BOX_Y - 40,
			         24,
			         GREEN);

			DrawRectangle(BOX_X, OUTPUT_BOX_Y, BOX_W, BOX_H, DARKGRAY);
			DrawRectangleLines(BOX_X, OUTPUT_BOX_Y, BOX_W, BOX_H, WHITE);

			if(choice1 == 7 || choice1 == 8) {
				DrawText(shiftText,
				         BOX_X + 15,
				         OUTPUT_BOX_Y + 20,
				         TEXT_SIZE,
				         WHITE);
			} else {
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

void bitwise_logs_screen(void) {
	FILE *fp;
	BitLog log;

	Rectangle btnBack = {BACK_X, BACK_Y, BACK_W, BACK_H};

	while (!WindowShouldClose()) {
		fp = fopen(BIT_LOG_FILE, "rb");

		updateTime();

		Vector2 mouse = GetMousePosition();

		if(IsKeyPressed(KEY_ESCAPE)) {
			if(fp != NULL)
				fclose(fp);

			choice = 0;
			return;
		}

		if(CheckCollisionPointRec(mouse, btnBack) &&
		        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
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
		         (SCREEN_W - MeasureText(currentTime, 22)) / 2,
		         95,
		         22,
		         GRAY);
				
		DrawText(TextFormat(currentUser.isAdmin ?
		                    "Viewing: ALL ACCOUNTS (Admin)" :
		                    "			Viewing: %s",currentUser.username),
		         (SCREEN_W - MeasureText("Viewing: ALL ACCOUNTS (Admin)", 22)) / 2,
		         130,
		         22,
		         SKYBLUE);

		DrawLine(60,170,1860,170,WHITE);

		DrawText("DATE & TIME",80,185,22,GREEN);
		DrawText("OPERATION",560,185,22,GREEN);
		DrawText("FIRST NUM",900,185,22,GREEN);
		DrawText("SECOND NUM",1150,185,22,GREEN);
		DrawText("RESULT",1440,185,22,GREEN);

		if(currentUser.isAdmin)
			DrawText("USER",340,185,22,GREEN);

		DrawLine(60,220,1860,220,WHITE);

		y = 240 + scroll;

		if(fp == NULL) {
			DrawText("NO BITWISE OPERATION LOGS FOUND",
			         (SCREEN_W - MeasureText("NO BITWISE OPERATION LOGS FOUND",30))/2,
			         500,
			         30,
			         RED);
		} else {
			fseek(fp, 0, SEEK_END);

			long totalLogs = ftell(fp) / sizeof(BitLog);

			long visibleLogs = 0;

			if(currentUser.isAdmin) {
				visibleLogs = totalLogs;
			} else {
				for(long i = 0; i < totalLogs; i++) {
					fseek(fp, i * sizeof(BitLog), SEEK_SET);

					if(fread(&log, sizeof(BitLog), 1, fp) == 1 &&
					        strcmp(log.username, currentUser.username) == 0) {
						visibleLogs++;
					}
				}
			}

			minScroll = -(visibleLogs * 40 - 700);

			if(minScroll > 0)
				minScroll = 0;

			scroll += (int)GetMouseWheelMove() * 30;

			if(scroll > 0)
				scroll = 0;

			if(scroll < minScroll)
				scroll = minScroll;

			for(long i = totalLogs - 1; i >= 0; i--) {
				fseek(fp, i * sizeof(BitLog), SEEK_SET);


				if(fread(&log, sizeof(BitLog), 1, fp) != 1)
					continue;

				if(!currentUser.isAdmin &&
				        strcmp(log.username, currentUser.username) != 0)
					continue;

				if(y < 240) {
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

				if(((y - 260) / 40) % 2 == 0) {
					DrawRectangle(60, y - 5, 1800, 35, Fade(DARKGRAY, 0.35f));
				}

				DrawText(timeStr,
				         80,
				         y,
				         20,
				         WHITE);

				if(currentUser.isAdmin) {
					DrawText(
					    TextSubtext(log.username,0,15),
					    340,
					    y,
					    20,
					    ORANGE
					);
				}

				char opStr[16];
				switch(log.operation) {
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

				if(log.operation == 3 || log.operation == 9) {
					DrawText("-", 1150, y, 20, GRAY);
				} else {
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

		if(fp != NULL) {
			fclose(fp);
			fp = NULL;
		}

		EndDrawing();
	}

	if(fp != NULL) {
		fclose(fp);
	}
}


bool HoverButton(Rectangle button,
                 const char text[],
                 Color normal,
                 Color hover,
                 Color textColor) {
	Vector2 mouse = GetMousePosition();

	bool over = CheckCollisionPointRec(mouse, button);

	DrawRectangleRounded(
	    button,
	    0.25f,
	    10,
	    over ? hover : normal
	);

	int fontSize = 24;

	int width = MeasureText(text, fontSize);

	DrawText(
	    text,
	    button.x + button.width / 2 - width / 2,
	    button.y + button.height / 2 - fontSize / 2,
	    fontSize,
	    textColor
	);

	return over && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void TextInputBox(Rectangle box,
                  char text[],
                  int maxLength,
                  int *letterCount,
                  int id,
                  bool isPassword)
{
    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        if (CheckCollisionPointRec(mouse, box))
            activeBox = id;
    }

    Color border = (activeBox == id) ? BLUE : GRAY;

    DrawRectangleRounded(box, 0.2f, 10, RAYWHITE);

    DrawRectangleRoundedLines(box,
                              0.2f,
                              10,
                              2,
                              border);

    if (activeBox == id)
    {
        int key = GetCharPressed();

        while (key > 0)
        {
            if (key >= 32 &&
                key <= 125 &&
                *letterCount < maxLength - 1)
            {
                text[*letterCount] = (char)key;
                (*letterCount)++;
                text[*letterCount] = '\0';
            }

            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (*letterCount > 0)
            {
                (*letterCount)--;
                text[*letterCount] = '\0';
            }
        }

        // Move to the next field when Enter is pressed
        if (IsKeyPressed(KEY_ENTER))
        {
            activeBox++;
        }
    }

    char displayText[MAX_LEN];

    if (isPassword)
    {
        int len = strlen(text);

        for (int i = 0; i < len; i++)
            displayText[i] = '*';

        displayText[len] = '\0';
    }
    else
    {
        strcpy(displayText, text);
    }

    // Text only ever grows/shrinks at the end here (no left/right cursor
    // movement in this widget), so trim from the front until what's left
    // fits inside the box -- same approach used for the number-conversion
    // and bitwise input boxes.
    int start = 0;
    while (MeasureText(displayText + start, 24) > box.width - 20 && displayText[start] != '\0')
        start++;

    DrawText(displayText + start,
             box.x + 10,
             box.y + 12,
             24,
             BLACK);

    if (activeBox == id && ((int)(GetTime() * 2) % 2) == 0)
    {
        int textWidth = MeasureText(displayText + start, 24);

        DrawRectangle(box.x + 10 + textWidth + 2,
                      box.y + 10,
                      2,
                      28,
                      BLACK);
    }
}

void Popup(const char title[],
           const char message[],
           Color color) {
	Rectangle box = {
		CENTER_X(440),
		CENTER_Y(220),
		440,
		220
	};

	DrawRectangleRounded(box,
	                     0.25f,
	                     10,
	                     RAYWHITE);

	DrawRectangleRoundedLines(box,
	                          0.25f,
	                          10,
	                          3,
	                          color);

	DrawText(title,
	         box.x+20,
	         box.y+20,
	         30,
	         color);

	DrawText(message,
	         box.x+20,
	         box.y+80,
	         22,
	         BLACK);
}

void DrawAccountBadge(void) {
	if(!loggedIn)
		return;

	Rectangle badge     = {SCREEN_W - 360, SCREEN_H - 110, 320, 90};
	Rectangle logoutBtn = {badge.x + 15, badge.y + 45, 290, 32};

	DrawRectangleRounded(badge, 0.15f, 10, DARKBLUE);
	DrawRectangleRoundedLines(badge, 0.15f, 10, 2, SKYBLUE);

	DrawText(TextFormat("Logged in: %s", currentUser.username),
	         badge.x + 15,
	         badge.y + 12,
	         20,
	         WHITE);

	if(HoverButton(logoutBtn,
	               "LOGOUT",
	               RED,
	               MAROON,
	               WHITE)) {
		loggedIn = 0;

		memset(&currentUser, 0, sizeof(User));

		loginUsername[0] = '\0';
		loginPassword[0] = '\0';

		loginUsernameCount = 0;
		loginPasswordCount = 0;

		loginError = false;

		currentScreen = LOGIN_SCREEN;
	}
}

void login_screen(void) {
	int cardH = 560;

	Rectangle card = {CENTER_X(AUTH_CARD_W), CENTER_Y(cardH), AUTH_CARD_W, cardH};

	int fieldX = AUTH_FIELD_X(card.x);

	Rectangle usernameBox = {fieldX, card.y + 200, AUTH_FIELD_W, AUTH_FIELD_H};
	Rectangle passwordBox = {fieldX, card.y + 280, AUTH_FIELD_W, AUTH_FIELD_H};

	Rectangle loginButton  = {fieldX, card.y + 380, AUTH_FIELD_W, 55};
	Rectangle signupButton = {fieldX, card.y + 450, 190, 45};
	Rectangle forgotButton = {fieldX + AUTH_FIELD_W - 190, card.y + 450, 190, 45};
		

	DrawRectangleRounded(card, 0.08f, 10, DARKBLUE);
	DrawRectangleRoundedLines(card, 0.08f, 10, 3, SKYBLUE);

	Vector2 exitCenter = { card.x + card.width - 30, card.y + 30 };
	float exitRadius = 18.0f;
	
	Vector2 mouse = GetMousePosition();
	bool hoverExit = CheckCollisionPointCircle(mouse, exitCenter, exitRadius);
	
	DrawCircleV(exitCenter, exitRadius, hoverExit ? MAROON : RED);
	DrawCircleLines((int)exitCenter.x, (int)exitCenter.y, exitRadius, WHITE);
	
	DrawText("x",
	         exitCenter.x - MeasureText("X", 30) / 2,
	         exitCenter.y - 15,
	         30,
	         WHITE);
	
	
	if (hoverExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
	    CloseWindow();
	}
	DrawText("LOGIN",
	         SCREEN_W/2 - MeasureText("LOGIN",40)/2,
	         card.y + 50,
	         40,
	         WHITE);

	DrawText("Username", fieldX, usernameBox.y - 25, 18, WHITE);
	TextInputBox(usernameBox,
	             loginUsername,
	             MAX_LEN,
	             &loginUsernameCount,
	             1,
	             false);


	DrawText("Password", fieldX, passwordBox.y - 25, 18, WHITE);
	TextInputBox(passwordBox,
	             loginPassword,
	             MAX_LEN,
	             &loginPasswordCount,
	             2,
	             !showPassword);
             
	// Press Enter on Password to Login
	if (activeBox > 2)
	{
	    activeBox = 2;
	
	    registerSuccess = false;
	    forgotSuccess = false;
	
	    if (LoginUser(loginUsername, loginPassword))
	    {
	        loggedIn = 1;
	        loginError = false;
	
	        if (currentUser.isAdmin)
	            currentScreen = ADMIN_MENU;
	        else
	            currentScreen = USER_MENU;
	    }
	    else
	    {
	        loginError = true;
	    }
	}


	if(HoverButton(loginButton,
	               "LOGIN",
	               BLUE,
	               GREEN,
	               WHITE)) {
		registerSuccess = false;
		forgotSuccess = false;

		if(LoginUser(loginUsername,loginPassword)) {
			loggedIn = 1;

			loginError = false;

			if(currentUser.isAdmin) {
				currentScreen = ADMIN_MENU;
			} else {
				currentScreen = USER_MENU;
			}
		} else {
			loginError = true;
		}
	}


	if(HoverButton(signupButton,
	               "REGISTER",
	               GRAY,
	               RED,
	               WHITE)) {
		loginError = false;
		registerSuccess = false;
		forgotSuccess = false;

		currentScreen = SIGNUP_SCREEN;
	}


	if(HoverButton(forgotButton,
	               "FORGOT",
	               GRAY,
	               RED,
	               WHITE)) {
		loginError = false;
		registerSuccess = false;
		forgotSuccess = false;

		currentScreen = FORGOT_SCREEN;
	}

	if(loginError) {
		DrawText("Invalid Username or Password",
		         fieldX,
		         card.y + 340,
		         22,
		         RED);
	}

	// Messages handed off from REGISTER / FORGOT PASSWORD, shown here
	// once we've already navigated back to the login screen.
	if(registerSuccess) {
		DrawText("Account Created Successfully! Please login.",
		         SCREEN_W/2 - MeasureText("Account Created Successfully! Please login.", 22)/2,
		         card.y + 340,
		         22,
		         GREEN);
	}

	if(forgotSuccess) {
		DrawText("Password Changed Successfully! Please login.",
		         SCREEN_W/2 - MeasureText("Password Changed Successfully! Please login.", 22)/2,
		         card.y + 340,
		         22,
		         GREEN);
	}
		DrawText("Press ESC to Quit",
		         fieldX,
		         card.y + 530,
		         22,
		         GRAY);
}

void signup_screen(void) {
	int cardH = 730;

	Rectangle card = {CENTER_X(AUTH_CARD_W), CENTER_Y(cardH), AUTH_CARD_W, cardH};

	int fieldX = AUTH_FIELD_X(card.x);

	Rectangle usernameBox = {fieldX, card.y + 130, AUTH_FIELD_W, AUTH_FIELD_H};
	Rectangle passwordBox = {fieldX, card.y + 215, AUTH_FIELD_W, AUTH_FIELD_H};
	Rectangle confirmBox  = {fieldX, card.y + 300, AUTH_FIELD_W, AUTH_FIELD_H};
	Rectangle questionBox = {fieldX, card.y + 385, AUTH_FIELD_W, AUTH_FIELD_H};
	Rectangle answerBox   = {fieldX, card.y + 470, AUTH_FIELD_W, AUTH_FIELD_H};

	Rectangle registerButton = {fieldX, card.y + 555, AUTH_FIELD_W, 55};
	Rectangle backButton     = {fieldX, card.y + 635, AUTH_FIELD_W, 45};

	DrawRectangleRounded(card, 0.08f, 10, DARKBLUE);
	DrawRectangleRoundedLines(card, 0.08f, 10, 3, SKYBLUE);

	DrawText("REGISTER",
	         SCREEN_W/2 -
	         MeasureText("REGISTER",40)/2,
	         card.y + 40,
	         40,
	         WHITE);

	DrawText("Username", fieldX, usernameBox.y - 20, 18, WHITE);
	TextInputBox(usernameBox,
	             newUser.username,
	             MAX_LEN,
	             &registerUsernameCount,
	             1,
	             false);

	DrawText("Password", fieldX, passwordBox.y - 25, 18, WHITE);
	TextInputBox(passwordBox,
	             newUser.password,
	             MAX_LEN,
	             &registerPasswordCount,
	             2,
	             true);

	DrawText("Confirm Password", fieldX, confirmBox.y - 25, 18, WHITE);
	TextInputBox(confirmBox,
	             confirmPassword,
	             MAX_LEN,
	             &confirmPasswordCount,
	             3,
	             true);

	DrawText("Security Question", fieldX, questionBox.y - 25, 18, WHITE);
	TextInputBox(questionBox,
	             newUser.question,
	             MAX_LEN,
	             &questionCount,
	             4,
	             false);

	DrawText("Security Answer", fieldX, answerBox.y - 25, 18, WHITE);
	TextInputBox(answerBox,
	             newUser.answer,
	             MAX_LEN,
	             &answerCount,
	             5,
	             false);

	if(HoverButton(registerButton,
	               "REGISTER",
	               BLUE,
	               GREEN,
	               WHITE)) {
		if(registerUsernameCount == 0 ||
		   registerPasswordCount == 0 ||
		   confirmPasswordCount == 0 ||
		   questionCount == 0 ||
		   answerCount == 0) {
			registerError = true;
			registerSuccess = false;
		} else if(strcmp(newUser.password,
		          confirmPassword)==0) {
			newUser.isAdmin = 0;

			if(RegisterUser(newUser)) {
				registerSuccess = true;
				registerError = false;

				memset(confirmPassword,0,sizeof(confirmPassword));

				registerUsernameCount = 0;
				registerPasswordCount = 0;
				confirmPasswordCount = 0;
				questionCount = 0;
				answerCount = 0;

				memset(&newUser,0,sizeof(User));

				// Hand off to the login screen: it shows the success
				// message and lets the new user log straight in.
				currentScreen = LOGIN_SCREEN;
			} else {
				registerError = true;
				registerSuccess = false;
			}
		} else {
			registerError = true;
			registerSuccess = false;
		}
	}

	if(HoverButton(backButton,
	               "BACK",
	               GRAY,
	               RED,
	               WHITE)) {
		registerError = false;
		registerSuccess = false;

		currentScreen = LOGIN_SCREEN;
	}

	if(registerError) {
		const char *registerErrorMsg = "Registration Failed!";

		if(registerUsernameCount == 0 ||
		   registerPasswordCount == 0 ||
		   confirmPasswordCount == 0 ||
		   questionCount == 0 ||
		   answerCount == 0) {
			registerErrorMsg = "Please fill in all fields!";
		} else if(strcmp(newUser.password, confirmPassword) != 0) {
			registerErrorMsg = "Passwords do not match!";
		}

		DrawText(registerErrorMsg,
		         fieldX,
		         card.y + 690,
		         22,
		         RED);
	}
}

void forgot_password_screen(void) {
	int cardH = 680;

	Rectangle card = {CENTER_X(AUTH_CARD_W), CENTER_Y(cardH), AUTH_CARD_W, cardH};

	int fieldX = AUTH_FIELD_X(card.x);

	Rectangle usernameBox = {fieldX, card.y + 150, AUTH_FIELD_W, AUTH_FIELD_H};
	Rectangle answerBox   = {fieldX, card.y + 300, AUTH_FIELD_W, AUTH_FIELD_H};
	Rectangle passwordBox = {fieldX, card.y + 385, AUTH_FIELD_W, AUTH_FIELD_H};

	Rectangle resetButton = {fieldX, card.y + 470, AUTH_FIELD_W, 55};
	Rectangle backButton  = {fieldX, card.y + 540, AUTH_FIELD_W, 45};

	DrawRectangleRounded(card, 0.08f, 10, DARKBLUE);
	DrawRectangleRoundedLines(card, 0.08f, 10, 3, SKYBLUE);

	DrawText("FORGOT PASSWORD",
	         SCREEN_W/2 -
	         MeasureText("FORGOT PASSWORD",40)/2,
	         card.y + 50,
	         40,
	         WHITE);

	DrawText("Username", fieldX, usernameBox.y - 25, 18, WHITE);
	TextInputBox(usernameBox,
	             forgotUsername,
	             MAX_LEN,
	             &forgotUsernameCount,
	             1,
	             false);

	char question[MAX_LEN] = "";

	if(forgotUsernameCount > 0) {
		if(!GetSecurityQuestion(forgotUsername, question)) {
			strcpy(question, "No account found ");
		}
	}

	const char *questionText = forgotUsernameCount > 0 ?
	         TextFormat("Q: %s", question) :
	         "Q: (enter username above)";

	DrawText(questionText,
	         fieldX,
	         usernameBox.y + 75,
	         QUESTION_TEXT_SIZE,
	         SKYBLUE);

	DrawText("Security Answer", fieldX, answerBox.y - 25, 18, WHITE);
	TextInputBox(answerBox,
	             forgotAnswer,
	             MAX_LEN,
	             &forgotAnswerCount,
	             2,
	             false);

	DrawText("New Password", fieldX, passwordBox.y - 25, 18, WHITE);
	TextInputBox(passwordBox,
	             forgotNewPassword,
	             MAX_LEN,
	             &forgotPasswordCount,
	             3,
	             true);

	if(HoverButton(resetButton,
	               "RESET PASSWORD",
	               BLUE,
	               GREEN,
	               WHITE)) {
		if(ForgotPassword(forgotUsername,
		                  forgotAnswer,
		                  forgotNewPassword)) {
			forgotSuccess = true;
			forgotError = false;

			memset(forgotUsername,0,sizeof(forgotUsername));
			memset(forgotAnswer,0,sizeof(forgotAnswer));
			memset(forgotNewPassword,0,sizeof(forgotNewPassword));

			forgotUsernameCount = 0;
			forgotAnswerCount = 0;
			forgotPasswordCount = 0;

			// Hand off to the login screen: it shows the success
			// message and lets the user log straight back in.
			currentScreen = LOGIN_SCREEN;
		} else {
			forgotError = true;
			forgotSuccess = false;
		}
	}

	if(HoverButton(backButton,
	               "BACK",
	               GRAY,
	               RED,
	               WHITE)) {
		forgotError = false;
		forgotSuccess = false;

		currentScreen = LOGIN_SCREEN;
	}

	if(forgotError) {
		DrawText("Incorrect Username or Security Answer!",
		         fieldX,
		         card.y + 600,
		         22,
		         RED);
	}
}

// Admin gets a wider "Account Settings" panel: a scrollable list of
// every registered account on the left, and an editor on the right
// that changes the username/password of whichever account is
// selected (defaults to the admin's own account).
static void admin_account_settings_screen(void) {
	static User userList[MAX_USERS];

	int userCount = GetAllUsers(userList, MAX_USERS);

	const char *targetUsername =
	    (editingUsername[0] != '\0') ? editingUsername : currentUser.username;

	Rectangle card = {
		CENTER_X(ADMIN_SETTINGS_W),
		CENTER_Y(ADMIN_SETTINGS_H),
		ADMIN_SETTINGS_W,
		ADMIN_SETTINGS_H
	};

	DrawRectangleRounded(card, 0.05f, 10, DARKBLUE);
	DrawRectangleRoundedLines(card, 0.05f, 10, 3, SKYBLUE);

	DrawText("ACCOUNT SETTINGS",
	         SCREEN_W/2 - MeasureText("ACCOUNT SETTINGS",40)/2,
	         card.y + 35,
	         40,
	         WHITE);

	DrawText("All Accounts (Admin)",
	         SCREEN_W/2 - MeasureText("All Accounts (Admin)",20)/2,
	         card.y + 85,
	         20,
	         SKYBLUE);

	// Left: scrollable list of every account

	Rectangle listPanel = {
		card.x + 40,
		card.y + 130,
		ADMIN_LIST_W,
		card.height - 130 - 40
	};

	DrawRectangleRounded(listPanel, 0.05f, 10, Fade(BLUE, 0.15f));
	DrawRectangleRoundedLines(listPanel, 0.05f, 10, 2, SKYBLUE);

	BeginScissorMode(listPanel.x, listPanel.y, listPanel.width, listPanel.height);

	Vector2 mouse = GetMousePosition();

	if(CheckCollisionPointRec(mouse, listPanel)) {
		accountListScroll += (int)GetMouseWheelMove() * 30;
	}

	int contentHeight = userCount * ADMIN_LIST_ROW_H;

	int minListScroll = listPanel.height - contentHeight;

	if(minListScroll > 0)
		minListScroll = 0;

	if(accountListScroll > 0)
		accountListScroll = 0;

	if(accountListScroll < minListScroll)
		accountListScroll = minListScroll;

	int rowY = listPanel.y + accountListScroll;

	for(int i = 0; i < userCount; i++) {
		Rectangle row = {listPanel.x + 8, rowY, listPanel.width - 16, ADMIN_LIST_ROW_H - 8};

		if(rowY + ADMIN_LIST_ROW_H >= listPanel.y &&
		        rowY <= listPanel.y + listPanel.height) {
			bool isSelected = strcmp(userList[i].username, targetUsername) == 0;
			bool isHover = CheckCollisionPointRec(mouse, row) &&
			               CheckCollisionPointRec(mouse, listPanel);

			DrawRectangleRounded(row, 0.2f, 8,
			                     isSelected ? SKYBLUE : (isHover ? Fade(SKYBLUE,0.35f) : Fade(DARKBLUE,0.6f)));

			DrawText(TextSubtext(userList[i].username, 0, 20),
			         row.x + 12,
			         row.y + 8,
			         20,
			         isSelected ? DARKBLUE : WHITE);

			if(userList[i].isAdmin) {
				DrawText("ADMIN",
				         row.x + row.width - MeasureText("ADMIN",16) - 10,
				         row.y + 10,
				         16,
				         isSelected ? MAROON : RED);
			}

			if(isHover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				strcpy(editingUsername, userList[i].username);

				settingsSuccess = false;
				settingsError = false;

				newUsernameCount = 0;
				newPasswordCount = 0;
				newUsername[0] = '\0';
				newPassword[0] = '\0';
			}
		}

		rowY += ADMIN_LIST_ROW_H;
	}

	EndScissorMode();

	// Right: editor for whichever account is selected

	int editorX = listPanel.x + listPanel.width + 50;
	int editorW = card.x + card.width - 40 - editorX;

	DrawText(TextFormat("Editing: %s%s",
	                    targetUsername,
	                    (strcmp(targetUsername, currentUser.username) == 0) ?
	                    " (you)" : ""),
	         editorX,
	         card.y + 130,
	         26,
	         WHITE);

	Rectangle usernameBox = {editorX, card.y + 190, editorW, AUTH_FIELD_H};
	Rectangle passwordBox = {editorX, card.y + 280, editorW, AUTH_FIELD_H};

	Rectangle usernameBtn = {editorX, card.y + 360, editorW, 50};
	Rectangle passwordBtn = {editorX, card.y + 430, editorW, 50};

	Rectangle selfBtn     = {editorX, card.y + 510, editorW, 45};

	Rectangle logoutBtn   = {editorX, card.y + card.height - 130 - 40, editorW, 50};
	Rectangle backBtn     = {editorX, card.y + card.height - 130 + 20, editorW, 45};

	DrawText("New Username", editorX, usernameBox.y - 25, 18, WHITE);
	TextInputBox(usernameBox, newUsername, MAX_LEN, &newUsernameCount, 1, false);

	DrawText("New Password", editorX, passwordBox.y - 25, 18, WHITE);
	TextInputBox(passwordBox, newPassword, MAX_LEN, &newPasswordCount, 2, true);

	// Change Username (of the SELECTED account)

	if(HoverButton(usernameBtn, "CHANGE USERNAME", BLUE, GREEN, WHITE)) {
		if(ChangeUsername((char *)targetUsername, newUsername)) {
			if(strcmp(targetUsername, currentUser.username) == 0)
				strcpy(currentUser.username, newUsername);

			strcpy(editingUsername, newUsername);

			settingsSuccess = true;
			settingsError = false;

			memset(newUsername,0,sizeof(newUsername));
			newUsernameCount = 0;
		} else {
			settingsError = true;
			settingsSuccess = false;
		}
	}

	// Change Password (of the SELECTED account)

	if(HoverButton(passwordBtn, "CHANGE PASSWORD", BLUE, GREEN, WHITE)) {
		if(ChangePassword((char *)targetUsername, newPassword)) {
			settingsSuccess = true;
			settingsError = false;

			memset(newPassword,0,sizeof(newPassword));
			newPasswordCount = 0;
		} else {
			settingsError = true;
			settingsSuccess = false;
		}
	}

	// Jump back to editing your own account

	if(HoverButton(selfBtn, "EDIT MY OWN ACCOUNT", GRAY, RED, WHITE)) {
		editingUsername[0] = '\0';

		settingsSuccess = false;
		settingsError = false;

		newUsernameCount = 0;
		newPasswordCount = 0;
		newUsername[0] = '\0';
		newPassword[0] = '\0';
	}

	// Logout

	if(HoverButton(logoutBtn, "LOGOUT", GRAY, RED, WHITE)) {
		loggedIn = 0;

		memset(&currentUser,0,sizeof(User));

		editingUsername[0] = '\0';
		accountListScroll = 0;

		currentScreen = LOGIN_SCREEN;
	}

	// Back

	if(HoverButton(backBtn, "BACK", GRAY, RED, WHITE)) {
		settingsSuccess = false;
		settingsError = false;

		editingUsername[0] = '\0';
		accountListScroll = 0;

		currentScreen = ADMIN_MENU;
	}

	if(settingsSuccess) {
		DrawText("Changes Saved Successfully!",
		         editorX,
		         card.y + 565,
		         22,
		         GREEN);
	}

	if(settingsError) {
		DrawText("Operation Failed!",
		         editorX,
		         card.y + 565,
		         22,
		         RED);
	}
}

void settings_screen(void) {
	if(currentUser.isAdmin) {
		admin_account_settings_screen();
		return;
	}

	int cardH = 640;

	Rectangle card = {CENTER_X(AUTH_CARD_W), CENTER_Y(cardH), AUTH_CARD_W, cardH};

	int fieldX = AUTH_FIELD_X(card.x);

	Rectangle usernameBox = {fieldX, card.y + 160, AUTH_FIELD_W, AUTH_FIELD_H};
	Rectangle passwordBox = {fieldX, card.y + 250, AUTH_FIELD_W, AUTH_FIELD_H};

	Rectangle usernameBtn = {fieldX, card.y + 350, AUTH_FIELD_W, 50};
	Rectangle passwordBtn = {fieldX, card.y + 420, AUTH_FIELD_W, 50};

	Rectangle logoutBtn   = {fieldX, card.y + 510, AUTH_FIELD_W, 50};
	Rectangle backBtn     = {fieldX, card.y + 580, AUTH_FIELD_W, 45};

	DrawRectangleRounded(card, 0.08f, 10, DARKBLUE);
	DrawRectangleRoundedLines(card, 0.08f, 10, 3, SKYBLUE);

	DrawText("ACCOUNT SETTINGS",
	         SCREEN_W/2 -
	         MeasureText("ACCOUNT SETTINGS",40)/2,
	         card.y + 50,
	         40,
	         WHITE);

	DrawText("New Username", fieldX, usernameBox.y - 25, 20, WHITE);

	TextInputBox(usernameBox,
	             newUsername,
	             MAX_LEN,
	             &newUsernameCount,
	             1,
	             false);

	DrawText("New Password", fieldX, passwordBox.y - 25, 20, WHITE);

	TextInputBox(passwordBox,
	             newPassword,
	             MAX_LEN,
	             &newPasswordCount,
	             2,
	             true);

	// Change Username

	if(HoverButton(usernameBtn,
	               "CHANGE USERNAME",
	               BLUE,
	               GREEN,
	               WHITE)) {
		if(ChangeUsername(currentUser.username,
		                  newUsername)) {
			strcpy(currentUser.username,newUsername);

			settingsSuccess = true;
			settingsError = false;

			memset(newUsername,0,sizeof(newUsername));
			newUsernameCount = 0;
		} else {
			settingsError = true;
			settingsSuccess = false;
		}
	}

	// Change Password

	if(HoverButton(passwordBtn,
	               "CHANGE PASSWORD",
	               BLUE,
	               GREEN,
	               WHITE)) {
		if(ChangePassword(currentUser.username,
		                  newPassword)) {
			settingsSuccess = true;
			settingsError = false;

			memset(newPassword,0,sizeof(newPassword));
			newPasswordCount = 0;
		} else {
			settingsError = true;
			settingsSuccess = false;
		}
	}

	// Logout

	if(HoverButton(logoutBtn,
	               "LOGOUT",
	               GRAY,
	               RED,
	               WHITE)) {
		loggedIn = 0;

		memset(&currentUser,0,sizeof(User));

		currentScreen = LOGIN_SCREEN;
	}

	// Back

	if(HoverButton(backBtn,
	               "BACK",
	               GRAY,
	               RED,
	               WHITE)) {
		settingsSuccess = false;
		settingsError = false;

		currentScreen = USER_MENU;
	}

	if(settingsSuccess) {
		DrawText("Changes Saved Successfully!",
		         fieldX,
		         card.y + 600,
		         22,
		         GREEN);
	}

	if(settingsError) {
		DrawText("Operation Failed!",
		         fieldX,
		         card.y + 600,
		         22,
		         RED);
	}
}

void admin_panel(void) {
	updateTime();

	Vector2 mouse = GetMousePosition();

	Rectangle btnNumLogs  = {BTN_X, BTN1_Y, BTN_W, BTN_H};
	Rectangle btnBitLogs  = {BTN_X, BTN2_Y, BTN_W, BTN_H};
	Rectangle btnSettings = {BTN_X, BTN3_Y, BTN_W, BTN_H};
	Rectangle btnLogout   = {BTN_X, BTN4_Y, BTN_W, BTN_H};

	DrawText("NUMBER CONVERSION SYSTEM",
	         (SCREEN_W - MeasureText("NUMBER CONVERSION SYSTEM", TITLE_SIZE)) / 2,
	         TITLE_Y, TITLE_SIZE, GREEN);

	DrawText("ADMIN PANEL",
	         (SCREEN_W - MeasureText("ADMIN PANEL", TITLE_SIZE)) / 2,
	         TITLE_Y + 65, TITLE_SIZE, GREEN);

	DrawText(currentTime,
	         (SCREEN_W - MeasureText(currentTime, SUBTITLE_SIZE)) / 2,
	         TITLE_Y + 125, SUBTITLE_SIZE, GRAY);

	DrawRectangleRec(btnNumLogs,
	                 CheckCollisionPointRec(mouse, btnNumLogs) ? SKYBLUE : DARKBLUE);

	DrawRectangleRec(btnBitLogs,
	                 CheckCollisionPointRec(mouse, btnBitLogs) ? SKYBLUE : DARKBLUE);

	DrawRectangleRec(btnSettings,
	                 CheckCollisionPointRec(mouse, btnSettings) ? SKYBLUE : DARKBLUE);

	DrawRectangleRec(btnLogout,
	                 CheckCollisionPointRec(mouse, btnLogout) ? RED : MAROON);

	DrawText("Number Logs",
	         BTN_X + (BTN_W - MeasureText("Number Logs", BUTTON_TEXT_SIZE)) / 2,
	         BTN1_Y + 20, BUTTON_TEXT_SIZE, WHITE);

	DrawText("Bitwise Logs",
	         BTN_X + (BTN_W - MeasureText("Bitwise Logs", BUTTON_TEXT_SIZE)) / 2,
	         BTN2_Y + 20, BUTTON_TEXT_SIZE, WHITE);

	DrawText("Account Settings",
	         BTN_X + (BTN_W - MeasureText("Account Settings", BUTTON_TEXT_SIZE)) / 2,
	         BTN3_Y + 20, BUTTON_TEXT_SIZE, WHITE);

	DrawText("Logout",
	         BTN_X + (BTN_W - MeasureText("Logout", BUTTON_TEXT_SIZE)) / 2,
	         BTN4_Y + 20, BUTTON_TEXT_SIZE, WHITE);

	DrawText("CONTRIBUTORS: @sulavmhx, @saurav112-dot",
	         BACK_X + (BACK_W - MeasureText("Back", BUTTON_TEXT_SIZE)) / 2,
	         BACK_Y + 20, BUTTON_TEXT_SIZE, WHITE);

	DrawAccountBadge();

	// Number Conversion Logs
	// (Admin can only VIEW logs -- no access to the
	// number conversion or bitwise tools themselves)

	if(CheckCollisionPointRec(mouse, btnNumLogs) &&
	        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		currentScreen = ADMIN_NUM_LOGS;
	}

	// Bitwise Operation Logs

	if(CheckCollisionPointRec(mouse, btnBitLogs) &&
	        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		currentScreen = ADMIN_BIT_LOGS;
	}

	// Account Settings

	if(CheckCollisionPointRec(mouse, btnSettings) &&
	        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		currentScreen = SETTINGS_SCREEN;
	}

	// Logout
	if(CheckCollisionPointRec(mouse, btnLogout) &&
	        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		loggedIn = 0;

		memset(&currentUser,
		       0,
		       sizeof(User));

		loginUsername[0] = '\0';
		loginPassword[0] = '\0';

		loginUsernameCount = 0;
		loginPasswordCount = 0;

		loginError = false;

		currentScreen = LOGIN_SCREEN;
	}
}