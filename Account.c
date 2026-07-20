#include <stdio.h>
#include <string.h>

#include "Account.h"
#include "Global.h"

void InitializeAdmin(void)
{
    FILE *fp;

    User admin;

    fp = fopen(USER_FILE,"r");

    if(fp != NULL)
    {
        fclose(fp);
        return;
    }

    fp = fopen(USER_FILE,"w");

    strcpy(admin.username,"admin");
    strcpy(admin.password,"admin123");
    strcpy(admin.question,"Faculty");
    strcpy(admin.answer,"BIT");

    admin.isAdmin = 1;

    fprintf(fp, "%s %s %s %s %d\n", admin.username, admin.password, admin.question, admin.answer, admin.isAdmin);

    fclose(fp);
}

int UsernameExists(char username[])
{
    FILE *fp;

    User temp;

    fp = fopen(USER_FILE,"r");

    if(fp == NULL)
    {
        return 0;
    }

    while(fscanf(fp, "%s %s %s %s %d", temp.username, temp.password, temp.question, temp.answer, &temp.isAdmin) != EOF)
    {
        if(strcmp(username,temp.username) == 0)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

int GetSecurityQuestion(char username[], char outQuestion[])
{
    FILE *fp;

    User temp;

    fp = fopen(USER_FILE,"r");

    if(fp == NULL)
    {
        return 0;
    }

    while(fscanf(fp, "%s %s %s %s %d", temp.username, temp.password, temp.question, temp.answer, &temp.isAdmin) != EOF)
    {
        if(strcmp(username,temp.username) == 0)
        {
            strcpy(outQuestion,temp.question);

            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

int GetAllUsers(User users[], int maxUsers)
{
    FILE *fp;

    int count = 0;

    fp = fopen(USER_FILE,"r");

    if(fp == NULL)
    {
        return 0;
    }

    while(count < maxUsers && fscanf(fp, "%s %s %s %s %d", users[count].username, users[count].password, users[count].question, users[count].answer, &users[count].isAdmin) != EOF)
    {
        count++;
    }

    fclose(fp);

    return count;
}

int RegisterUser(User newUser)
{
    FILE *fp;

    if(UsernameExists(newUser.username))
    {
        return 0;
    }

    fp = fopen(USER_FILE,"a");

    if(fp == NULL)
    {
        return 0;
    }

    fprintf(fp, "%s %s %s %s %d\n", newUser.username, newUser.password, newUser.question, newUser.answer, newUser.isAdmin);

    fclose(fp);

    return 1;
}

int LoginUser(char username[], char password[])
{
    FILE *fp;
    User temp;

    fp = fopen(USER_FILE, "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fscanf(fp, "%s %s %s %s %d", temp.username, temp.password, temp.question, temp.answer, &temp.isAdmin) != EOF)
    {
        if (strcmp(username, temp.username) == 0 && strcmp(password, temp.password) == 0)
        {
            currentUser = temp;   // Save the logged-in user

            fclose(fp);

            return 1;
        }
    }

    fclose(fp);

    return 0;
}

int ChangePassword(char username[], char newPassword[])
{
    FILE *fp;
    FILE *tempFile;

    User temp;

    int found = 0;

    fp = fopen(USER_FILE, "r");

    if (fp == NULL)
    {
        return 0;
    }

    tempFile = fopen("temp.txt", "w");

    while (fscanf(fp, "%s %s %s %s %d", temp.username, temp.password, temp.question, temp.answer, &temp.isAdmin) != EOF)
    {
        // If this is the correct user
        if (strcmp(temp.username, username) == 0)
        {
            strcpy(temp.password, newPassword);

            found = 1;
        }

        // Write the user (updated or not) into temp.txt
        fprintf(tempFile, "%s %s %s %s %d\n", temp.username, temp.password, temp.question, temp.answer, temp.isAdmin);
    }

    fclose(fp);
    fclose(tempFile);

    remove(USER_FILE);

    rename("temp.txt", USER_FILE);

    return found;
}

int ChangeUsername(char oldUsername[], char newUsername[])
{
    FILE *fp;
    FILE *tempFile;

    User temp;

    int found = 0;

    // Check if the new username already exists
    if (UsernameExists(newUsername))
    {
        return 0;
    }

    fp = fopen(USER_FILE, "r");

    if (fp == NULL)
    {
        return 0;
    }

    tempFile = fopen("temp.txt", "w");

    while (fscanf(fp, "%s %s %s %s %d", temp.username, temp.password, temp.question, temp.answer, &temp.isAdmin) != EOF)
    {
        // Find the current user
        if (strcmp(temp.username, oldUsername) == 0)
        {
            strcpy(temp.username, newUsername);

            found = 1;
        }

        fprintf(tempFile, "%s %s %s %s %d\n", temp.username, temp.password, temp.question, temp.answer, temp.isAdmin);
    }

    fclose(fp);
    fclose(tempFile);

    remove(USER_FILE);

    rename("temp.txt", USER_FILE);

    // Update the current user in memory
    if (found)
    {
        strcpy(currentUser.username, newUsername);
    }

    return found;
}

int DeleteAccount(char username[])
{
    FILE *fp;
    FILE *tempFile;

    User temp;

    int found = 0;

    fp = fopen(USER_FILE, "r");

    if (fp == NULL)
    {
        return 0;
    }

    tempFile = fopen("temp.txt", "w");

    while (fscanf(fp, "%s %s %s %s %d", temp.username, temp.password, temp.question, temp.answer, &temp.isAdmin) != EOF)
    {
        // Skip writing this user -- that's the "delete"
        if (strcmp(temp.username, username) == 0)
        {
            found = 1;
            continue;
        }

        fprintf(tempFile, "%s %s %s %s %d\n", temp.username, temp.password, temp.question, temp.answer, temp.isAdmin);
    }

    fclose(fp);
    fclose(tempFile);

    remove(USER_FILE);

    rename("temp.txt", USER_FILE);

    return found;
}

int ForgotPassword(char username[],char answer[],char newPassword[])
{
    FILE *fp;
    FILE *tempFile;

    User temp;

    int found = 0;

    fp = fopen(USER_FILE, "r");

    if(fp == NULL)
    {
        return 0;
    }

    tempFile = fopen("temp.txt", "w");

    while(fscanf(fp, "%s %s %s %s %d", temp.username, temp.password, temp.question, temp.answer, &temp.isAdmin) != EOF)
    {
        // Check username and security answer
        if(strcmp(temp.username, username) == 0 && strcmp(temp.answer, answer) == 0)
        {
            strcpy(temp.password, newPassword);

            found = 1;
        }

        fprintf(tempFile, "%s %s %s %s %d\n", temp.username, temp.password, temp.question, temp.answer, temp.isAdmin);
    }

    fclose(fp);
    fclose(tempFile);

    remove(USER_FILE);

    rename("temp.txt", USER_FILE);

    return found;
}