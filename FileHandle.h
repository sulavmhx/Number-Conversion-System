#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include <time.h>

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

void Num_logs_input(void);
void Num_logs_output(void);
void Bit_logs_input(void);
void Bit_logs_output(void);

#endif