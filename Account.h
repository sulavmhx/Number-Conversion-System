#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <stdio.h>
#define MAX_LEN 50
#define USER_FILE "users.dat"
#define MAX_USERS 200
typedef struct
{
    char username[MAX_LEN];
    char password[MAX_LEN];
    char question[MAX_LEN];
    char answer[MAX_LEN];
    int isAdmin;
} User;
void InitializeAdmin(void);
int RegisterUser(User user);
int LoginUser(char username[], char password[]);
int ForgotPassword(char username[],char answer[],char newPassword[]);
int ChangePassword(char username[],char newPassword[]);
int ChangeUsername(char oldUsername[],char newUsername[]);
int DeleteAccount(char username[]);
int UsernameExists(char username[]);
int GetSecurityQuestion(char username[], char outQuestion[]);
int GetAllUsers(User users[], int maxUsers);
#endif