#include "Global.h"
#include "Drawing.h"

// Number Converter

int input_choice = 0;
int output_choice = 0;
int choice = 0;
int choice1 = 0;

char number[100] = "";
char currentTime[64] = "";

long long result_dec = 0;
long long result_oct = 0;
long long result_hexa = 0;

int invalid = 0;

char result_bin[100] = "";
char clean[100] = "";

unsigned int result = 0;
unsigned int back = 0;
unsigned int num1 = 0;
unsigned int num2 = 0;

char number1[64] = "";
char number2[64] = "";
char shiftText[16] = "";

int letterCount1 = 0;
int letterCount2 = 0;
int letterCountShift = 0;
int letterCount = 0;

int key = 0;
int activeBox = 1;
int y = 0;
int scroll = 0;
int minScroll = 0;
int count = 0;
int shift = 0;

char temp[32] = "";

// Account System


User currentUser;
int currentScreen = LOGIN_SCREEN;

int loggedIn = 0;
int loginAttempts = 3;

char loginUsername[MAX_LEN] = "";
char loginPassword[MAX_LEN] = "";

int loginUsernameCount = 0;
int loginPasswordCount = 0;

bool showPassword = false;
bool loginError = false;


// Login Screen UI


Rectangle usernameBox = {760, 320, 400, 50};
Rectangle passwordBox = {760, 400, 400, 50};

Rectangle loginButton = {760, 500, 400, 55};
Rectangle signupButton = {760, 570, 190, 45};
Rectangle forgotButton = {970, 570, 190, 45};

User newUser;

char confirmPassword[MAX_LEN] = "";

int registerUsernameCount = 0;
int registerPasswordCount = 0;
int confirmPasswordCount = 0;
int questionCount = 0;
int answerCount = 0;

bool registerError = false;
bool registerSuccess = false;

char forgotUsername[MAX_LEN] = "";
char forgotAnswer[MAX_LEN] = "";
char forgotNewPassword[MAX_LEN] = "";

int forgotUsernameCount = 0;
int forgotAnswerCount = 0;
int forgotPasswordCount = 0;

bool forgotError = false;
bool forgotSuccess = false;

char newUsername[MAX_LEN] = "";
char newPassword[MAX_LEN] = "";

int newUsernameCount = 0;
int newPasswordCount = 0;

bool settingsSuccess = false;
bool settingsError = false;

// Admin - Account Settings (manage all accounts)


char editingUsername[MAX_LEN] = "";
int  accountListScroll = 0;