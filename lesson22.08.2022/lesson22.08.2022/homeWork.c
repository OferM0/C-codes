#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)



int charsSum()
{
	FILE* f;
	int cnt = 0;

	f = fopen("C:\\Users\\oferm\\source\\repos\\C learning\\lesson22.08.2022\\file1.txt", "r");
	if (f == NULL)
	{
		// problem
		// error message
	}
	else
	{
		char ch = fgetc(f);
		while (ch != EOF)
		{
			cnt++;
			ch = fgetc(f);
		}
		printf("%d\n", cnt);
		fclose(f);
	}
}

int charStars()
{
	FILE* f;
	int cnt = 0;

	f = fopen("C:\\Users\\oferm\\source\\repos\\C learning\\lesson22.08.2022\\file1.txt", "r");
	if (f == NULL)
	{
		// problem
		// error message
	}
	else
	{
		char ch = fgetc(f);
		while (ch != EOF)
		{
			cnt= (ch == '*') ? cnt+1 : cnt;
			ch = fgetc(f);
		}
		printf("%d\n", cnt);
		fclose(f);
	}
}

int linesSum()
{
	FILE* f;
	int cnt = 1;

	f = fopen("C:\\Users\\oferm\\source\\repos\\C learning\\lesson22.08.2022\\file2.txt", "r");
	if (f == NULL)
	{
		// problem
		// error message
	}
	else
	{
		char ch = fgetc(f);
		while (ch != EOF)
		{
			cnt = (ch == '\n') ? cnt + 1 : cnt;
			ch = fgetc(f);
		}
		printf("%d\n", cnt);
		fclose(f);
	}
}


int allocMemoryByText()
{
	FILE* f;
	int num;
	char ch;
	int* numbers=0;
	char* characters='0';
	int cnt = 0;

	f = fopen("C:\\Users\\oferm\\source\\repos\\C learning\\lesson22.08.2022\\file3.txt", "r");
	if (f == NULL)
	{
		printf("Error");
	}
	else
	{
		ch = fgetc(f);
		num=(int)(ch - '0');
		while (ch != EOF)
		{
			ch = fgetc(f);
			if (ch == 'c')
			{
				cnt++;
				characters = malloc(sizeof(char) * num);
				if (characters == NULL)
				{
					printf("Error! memory not allocated.");
				}
				else
				{
					char* originalChar = characters;
					printf("Memory allocation number %d in size of %d bytes and char type (%dc)\n", cnt, num, num);
					printf("Address of memory: %x\n", characters);
					printf("\n");
					printf("Please put %d char values to the alucated memory\n", num);
					for (int i = 1; i <= num; i++)
					{
						printf("Please enter value number %d\n", i);
						scanf(" %c", characters);
						characters++;
					}
					printf("\n");
					printf("********************************************\n");
					free(originalChar);
				}
			}
			else if (ch == 'i')
			{
				cnt++;
				numbers = malloc(sizeof(int) * num);
				if (numbers == NULL)
				{
					printf("Error! memory not allocated.");
				}
				else
				{
					int* originalNum = numbers;
					printf("Memory allocation number %d in size of %d bytes and integer type (%di)\n", cnt, 4 * num, num);
					printf("Address of memory: %x\n", numbers);
					printf("\n");
					printf("Please put %d integers values to the alucated memory\n", num);
					for (int j = 1; j <= num; j++)
					{
						printf("Please enter value number %d\n", j);
						scanf("%d", numbers);
						numbers++;
					}
					printf("\n");
					printf("********************************************\n");
					free(originalNum);
				}
			}
			else
			{
				num = (int)(ch - '0');
			}
		}
		fclose(f);
	}
	return 0;
}

int main()
{
	//charsSum();
	//charStars();
	//linesSum();
	allocMemoryByText();

	return 0;
}