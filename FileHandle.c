#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "FileHandle.h"
#include "Utility.h"
#include "Global.h"
#include "raylib.h"

void Num_logs_input()
{
    FILE *fp;
    NumLog log;
	
	TraceLog(LOG_INFO, "Saving log...");
    fp = fopen(NUM_LOG_FILE, "ab");

    if(fp == NULL)
    {
        printf("Error Opening File!\n");
        return;
    }

    log.input_base = input_choice;
    log.output_base = output_choice;

    strcpy(log.input_number, number);
    strcpy(log.username, currentUser.username);

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

    strcpy(log.username, currentUser.username);

    log.used_time = time(NULL);

    fwrite(&log, sizeof(BitLog), 1, fp);

    fclose(fp);
}