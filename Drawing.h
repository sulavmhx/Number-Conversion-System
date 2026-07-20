#ifndef DRAWING_H
#define DRAWING_H

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

#define POPUP_X (SCREEN_W / 2 - 250)
#define POPUP_Y (SCREEN_H / 2 - 220)

// Generic centering helpers, used so every floating window (login,
// register, forgot password, settings, popups...) is centered on the
// SAME design resolution (SCREEN_W x SCREEN_H) that the rest of the
// UI is built on. Using GetScreenWidth()/GetScreenHeight() instead
// would desync from everything else the moment the game runs in
// fullscreen on a monitor that isn't exactly 1920x1080, which is
// what was causing the cards/boxes to look off-center.

#define CENTER_X(w)     ((SCREEN_W - (w)) / 2)
#define CENTER_Y(h)     ((SCREEN_H - (h)) / 2)

// Shared sizing for the auth-style cards (login / register / forgot /
// settings) so every field lines up the same way inside its card.
#define AUTH_CARD_W     520
#define AUTH_FIELD_W    400
#define AUTH_FIELD_H    50
#define AUTH_FIELD_X(cardX)  ((cardX) + (AUTH_CARD_W - AUTH_FIELD_W) / 2)

#define QUESTION_TEXT_SIZE 26

// Admin "Account Settings" panel (bigger: account list + editor)
#define ADMIN_SETTINGS_W    1300
#define ADMIN_SETTINGS_H    820
#define ADMIN_LIST_W        420
#define ADMIN_LIST_ROW_H    56

#define LOGIN_SCREEN     0
#define ADMIN_MENU       1
#define USER_MENU        2
#define SIGNUP_SCREEN    3
#define FORGOT_SCREEN    4
#define SETTINGS_SCREEN  5
#define ADMIN_NUM_LOGS   6
#define ADMIN_BIT_LOGS   7
        
void menu(void);

void DrawMenuBackdrop(void);

void number_conv_inputbase(void);
void number_conv_outputbase(void);
void number_conv_inputscreen(void);
void number_conv_outputscreen(void);
void number_logs_screen(void);

void bitwise_ope_interface(void);
void bitwise_ope_inputscreen(void);
void bitwise_ope_outputscreen(void);
void bitwise_logs_screen(void);

void login_screen(void);
void signup_screen(void);
void forgot_password_screen(void);
void settings_screen(void);
void admin_panel(void);

void TextInputBox(Rectangle box,char text[],int maxLength,int *letterCount,int id,bool isPassword);

bool HoverButton(Rectangle button,const char text[],Color normal,Color hover,Color textColor);

void Popup(const char title[],const char message[],Color color);

void DrawAccountBadge(void);

#endif