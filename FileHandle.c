#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "FileHandle.h"
#include "Utility.h"
#include "Global.h"

#define NUM_LOG_FILE "NumConvLog.txt"
#define BIT_LOG_FILE "BitwiseLog.txt"

typedef struct
{
    int input_base;
    int output_base;

    char input_number[64];
    char output_number[64];

    time_t used_time;

} NumLog;

typedef struct
{
    int operation;

    unsigned int first_number;
    unsigned int second_number;

    unsigned int result;

    time_t used_time;

} BitLog;

void Num_logs_input()
{
    FILE *fp;
    NumLog log;

    fp = fopen(NUM_LOG_FILE, "ab");

    if(fp == NULL)
    {
        printf("Error Opening File!\n");
        return;
    }

    log.input_base = input_choice;
    log.output_base = output_choice;

    strcpy(log.input_number, number);

    switch(output_choice)
{
    case 1:
        strcpy(log.output_number, result_bin);
    break;

    case 2:
        sprintf(log.output_number, "%ld", result_dec);
    break;

    case 3:
        sprintf(log.output_number, "%lo", result_oct);
    break;

    case 4:
        sprintf(log.output_number, "%lX", result_hexa);
    break;

    default:
        strcpy(log.output_number, "UNKNOWN");
    break;
}

    log.used_time = time(NULL);

    fwrite(&log, sizeof(NumLog), 1, fp);

    fclose(fp);
}

void Num_logs_output()
{
    FILE *fp;
    NumLog log;

    fp = fopen(NUM_LOG_FILE, "rb");

    if(fp == NULL)
    {
        printf("No Number Conversion Logs Found!\n");
        system("pause");
        return;
    }

    clear_screen();

    printf("=====================================\n");
    printf("     NUMBER CONVERSION LOGS\n");
    printf("=====================================\n\n");

    while(fread(&log, sizeof(NumLog), 1, fp) == 1)
    {
        printf("Input Base   : ");

        switch(log.input_base)
        {
            case 1:
                printf("Binary\n");
                break;
            case 2:
                printf("Decimal\n");
                break;
            case 3:
                printf("Octal\n");
                break;
            case 4:
                printf("Hexa-Decimal\n");
                break;
            default:
                printf("Unknown\n");
                break;
        }

        printf("Output Base  : ");

        switch(log.output_base)
        {
            case 1:
                printf("Binary\n");
                break;
            case 2:
                printf("Decimal\n");
                break;
            case 3:
                printf("Octal\n");
                break;
            case 4:
                printf("Hexa-Decimal\n");
                break;
            default:
                printf("Unknown\n");
                break;
        }

        printf("Input Value  : %s\n",
               log.input_number);

        printf("Output Value : %s\n",
               log.output_number);

        printf("Time         : %s",
               ctime(&log.used_time));

        printf("-------------------------------------\n");
    }

    fclose(fp);

    system("pause");
}

void Bit_logs_input()
{
    FILE *fp;
    BitLog log;

    fp = fopen(BIT_LOG_FILE, "ab");

    if(fp == NULL)
    {
        printf("Error Opening File!\n");
        return;
    }

    log.operation = choice1;

    log.first_number = num1;

    log.second_number = num2;

    log.result = result;

    log.used_time = time(NULL);

    fwrite(&log, sizeof(BitLog), 1, fp);

    fclose(fp);
}

void Bit_logs_output()
{
    FILE *fp;
    BitLog log;

    fp = fopen(BIT_LOG_FILE, "rb");

    if(fp == NULL)
    {
        printf("No Bitwise Logs Found!\n");
        system("pause");
        return;
    }

    clear_screen();

    printf("=====================================\n");
    printf("          BITWISE LOGS\n");
    printf("=====================================\n\n");

    while(fread(&log, sizeof(BitLog), 1, fp) == 1)
    {
	printf("Operation : ");
	
	        switch(log.operation)
	        {
	            case 1:
	                printf("AND\n");
	                break;
	            case 2:
	                printf("OR\n");
	                break;
	            case 3:
	                printf("NOT\n");
	                break;
	            case 4:
	                printf("XOR\n");
	                break;
	            case 5:
	                printf("XNOR\n");
	                break;
	            case 6:
	                printf("NAND\n");
	                break;
	            case 7:
	                printf("LEFT SHIFT\n");
	                break;
	            case 8:
	                printf("RIGHT SHIFT\n");
	                break;
	            case 9:
	                printf("COUNT SET BITS\n");
	                break;
	            default:
	                printf("UNKNOWN\n");
	                break;
	        }

        printf("Number 1  : %u\n",
               log.first_number);

        printf("Number 2  : %u\n",
               log.second_number);

        printf("Result    : %u\n",
               log.result);

        printf("Time      : %s",
               ctime(&log.used_time));

        printf("-------------------------------------\n");
    }

    fclose(fp);

    system("pause");
}