#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)


int returnSum(char str[100])
{
	int sum = 0;
	char* token = strtok(str, ",");

	while (token != NULL)
	{
		sum = sum + atoi(token);
		token = strtok(NULL, ",");
	}
	return sum;
}

void returnSeperateName()
{
	char str1[100];

	printf("Please enter your first and last name seperate by space\n");
	gets(str1);

	char* token = strtok(str1, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
}

void returnSeperateName2()
{
char str1[100];
int cnt = 1;
printf("Please enter your first and last name seperate by space\n");
gets(str1);

char* token = strtok(str1, " ");
while (token != NULL)
{
	if (cnt == 1)
	{
		printf("%s\n", token);
	}
	else
	{
		printf("%s ", token);
	}
	token = strtok(NULL, " ");
	cnt++;
}
printf("\n");
}

void oskarWinners()
{
	char movie[100], name[100], year[100] ,str[100];
	FILE* f = fopen("f.txt", "r");

	if (f)
	{
		fgets(str,sizeof(str), f);
		while (str[0]!=NULL)
		{
			char* token = strtok(str, ",");
			while (token != NULL)
			{
				token = strtok(NULL, ",");
				strcpy(year, token);
				token = strtok(NULL, ",");
				token = strtok(NULL, ",");
				strcpy(name, token);
				token = strtok(NULL, ",");
				strcpy(movie, token);
				token = strtok(NULL, ",");
			}
			printf("The Oskar Goes to: %s at year: %s for movie: %s\n", name, year, movie);
			str[0] = NULL;
			fgets(str, sizeof(str), f);
		}
		fclose(f);
	}
	else
	{
	// error
	return;
	}
	
}

int main_1() {
	
	char str[100] = "123,456,789,1,2,3,4,5,6,7,2000";
	printf("%d\n", returnSum(str));
	returnSeperateName();
	returnSeperateName2();
	oskarWinners();


	return 0;
}
