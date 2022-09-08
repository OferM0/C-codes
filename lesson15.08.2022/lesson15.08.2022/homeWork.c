#include <stdio.h>
#pragma warning(disable : 4996)

int main_1()
{
	int num, digit;
	printf("Please enter a number\n");
	scanf("%d", &num);
	digit = num % 10;
	printf("The last digit is: %d", digit);

	return 0;
}

int main_2()
{
	int num, digit;
	printf("Please enter a number\n");
	scanf("%d", &num);
	if (num >= 10)
	{
		digit = (num % 100 - num % 10) / 10;
		printf("The pre-last digit is: %d", digit);
	}
	else
	{
		printf("You entered a number lower than 10");
	}

	return 0;
}
/*
int main_3()
{
	int num, check=1;
	printf("Please enter a number\n");
	scanf("%d", &num);
	if (num == 0 || num==1)
	{
		check = 0;
	}
	else if(num>1)
	{
		for (int i = 2; i < num; i++)
		{
			if(num%i==0)
			{
				check = 0;
			}
		}
	}
	if (check == 1)
	{
		printf("Rishoni number");
	}
	else
	{
		printf("Not Rishoni number");
	}
	return check;
}
*/



int main_4()
{
	for (int i = 1; i < 100000; i++)
	{
		if (checkIfRishoni(i) == 1)
		{
			printf("%d ", i);
		}
	}


	return 0;
}

int checkIfRishoni(int num)
{
	int check = 1;
	if (num == 0 || num == 1)
	{
		check = 0;
	}
	else if (num > 1)
	{
		switch (0)
		{
		default: check = check;
			for (int i = 2; i < num; i++)
			{
				if (num % i == 0)
				{
					check = 0;
					break;
				}
			}
		}
	}

	return check;
}

int main()
{
	int num;
	printf("Please enter a number\n");
	scanf("%d", &num);
	(isPolindrom(num) == 1) ? printf("polindrom") : printf("not polindrom");
	return 0;

}

int isPolindrom(int num)
{
	int arr[1000];
	int length = 0, i = 0, check = 1;
	while (num > 0)
	{
		arr[i] = num % 10;
		i++;
		num = num / 10;
		length++;
	}

	for (int i = 0; i < length; i++)
	{
		if (arr[i] != arr[length - 1])
		{
			check = 0;
		}
		length--;
	}
	return check;
}