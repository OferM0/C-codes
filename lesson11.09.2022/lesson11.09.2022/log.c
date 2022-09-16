#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)


void Log(char message[100])
{
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);

	char str[100];
	FILE* f = fopen("myFirst8.log", "a");

	sprintf(str, "%d.%d.%d %d:%d:%d - %s\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
	fputs(str, f);
	fclose(f);
}

void LogEvent(char message[100])
{
	char str[100];
	sprintf(str, "%s %s", "Event � ", message);
	Log(str);
}

void LogError(char message[100])
{
	char str[100];
	sprintf(str, "%s %s", "Error - ", message);
	Log(str);
}

int main_1()
{
	int num;	
	char message[100];
	FILE* f; 

	LogEvent("System Is Starting");
	printf("Please enter number\n");
	scanf("%d", &num);
	sprintf(message, "The user entered the number: %d", num);
	LogEvent(message);
	f = fopen("myFirst.txt", "w");
	if (f)
	{
		LogEvent("Open file succed");
		for (int i = 1; i <= num; i++)
		{
			sprintf(message, "%d\n", i);
			fputs(message, f);
		}
		fclose(f);
		LogEvent("Close the file");
	}
	else
	{
		LogError("File Not Opened");
	}
	
	LogEvent("End Of System");

	return 0;
	//dd
}
