#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include "ofer_Utilities.h"
#pragma warning(disable:4996)

char file_name[100];

void Log_Init(char filename[1000])
{
	strcpy(file_name,filename);
}

void Log(char message[100])
{
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);

	char str[100];
	FILE* f = fopen(file_name, "a");

	sprintf(str, "%d.%d.%d %d:%d:%d - %s\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
	fputs(str, f);
	fclose(f);
}

void Log_Error(char message[100])
{
	char str[100];
	sprintf(str, "%s %s", "Error - ", message);
	Log(str);
}

void Log_Event(char message[100])
{
	char str[100];
	sprintf(str, "%s %s", "Event - ", message);
	Log(str);
}

void Log_Warning(char message[100])
{
	char str[100];
	sprintf(str, "%s %s", "Warning - ", message);
	Log(str);
}