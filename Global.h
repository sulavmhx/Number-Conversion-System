#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdbool.h>
#include "raylib.h"
#include "Account.h"


// Number Converter


extern int input_choice;
extern int output_choice;
extern int choice;
extern int choice1;

extern char number[100];
extern char currentTime[64];

extern long long result_dec;
extern long long result_oct;
extern long long result_hexa;

extern int invalid;

extern char result_bin[100];
extern char clean[100];

extern unsigned int result;
extern unsigned int back;
extern unsigned int num1;
extern unsigned int num2;

extern char number1[64];
extern char number2[64];
extern char shiftText[16];

extern int letterCount1;
extern int letterCount2;
extern int letterCountShift;
extern int letterCount;

extern int key;
extern int activeBox;
extern int y;
extern int scroll;
extern int minScroll;
extern int count;
extern int shift;

extern char temp[32];


// Account System


extern User currentUser;

extern int currentScreen;

extern int loggedIn;
extern int loginAttempts;

extern char loginUsername[MAX_LEN];
extern char loginPassword[MAX_LEN];

extern int loginUsernameCount;
extern int loginPasswordCount;

extern bool showPassword;
extern bool loginError;

// Login Screen

extern Rectangle usernameBox;
extern Rectangle passwordBox;

extern Rectangle loginButton;
extern Rectangle signupButton;
extern Rectangle forgotButton;

extern User newUser;

extern char confirmPassword[MAX_LEN];

extern int registerUsernameCount;
extern int registerPasswordCount;
extern int confirmPasswordCount;
extern int questionCount;
extern int answerCount;

extern bool registerError;
extern bool registerSuccess;

extern char forgotUsername[MAX_LEN];
extern char forgotAnswer[MAX_LEN];
extern char forgotNewPassword[MAX_LEN];

extern int forgotUsernameCount;
extern int forgotAnswerCount;
extern int forgotPasswordCount;

extern bool forgotError;
extern bool forgotSuccess;

extern char newUsername[MAX_LEN];
extern char newPassword[MAX_LEN];

extern int newUsernameCount;
extern int newPasswordCount;

extern bool settingsSuccess;
extern bool settingsError;

// Admin - Account Settings (manage all accounts)


extern char editingUsername[MAX_LEN];   // "" = admin is editing their own account
extern int  accountListScroll;

#endif