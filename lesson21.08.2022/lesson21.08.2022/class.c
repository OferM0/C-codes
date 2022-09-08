#include <stdio.h>
#include <limits.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	//newNum(2, 1);
	//checkIf1(1);
	//unsigned char  num = 0b10001110;
	//printBits2(num);
	printBits(255);


	return 0;
}

int main_1()
{
	char num = 0b00000001;

	num <<= 2; //num = num << 2

	num = num << 1;
	num = num << 1;
	num = num << 1;

	num = -1;
	num = num >> 1;
	num = num >> 1;
	num = num >> 1;
	num = num >> 1;

	printf("%d", num);

	return 0;
}


int reset()
{
	//define a variable put a numerical value in it and try to reset(=0) it only by moving bits

	int a = INT_MAX;
	int cnt = 0;
	while (a != 0) {
		a = a / 2;
		cnt++;
	}
	a = INT_MAX;
	for (int i = 0; i < cnt; i++)
	{
		a >>= 1;
	}
	printf("%d %d", a, cnt);

	return 0;
}

int newNum(unsigned char num, unsigned char bits)
{
	unsigned char new = num << bits;

	printf("%d", new);

	return 0;
}

int checkIf1(unsigned char num)
{
	int mask = 0;
	mask = num ^ 0b00000001;

	(mask == 0) ? printf("1") : printf("The number not equal 1");

	return 0;
}

int printBits(int num)
{
	//way of %2
	int print[8]={0,0,0,0,0,0,0,0};

	for (int i = 7; i >= 0; i--)
	{
		if (num != 0)
		{
			print[i] = num % 2;
			num = num / 2;
		}
	}

	for (int i = 0; i <= 7; i++)
	{
		printf("%d", print[i]);
	}

	return 0;
}
//way of mask and bits move
int  printBits2(unsigned char num)
{
	// 4 - 00000100
	unsigned char proccedNum = num;
	//   111111100
	unsigned char mask = 0b00000001;
	for (int i = 0; i < 8; i++)
	{
		char oneBit = proccedNum && mask;
		proccedNum = proccedNum >> 1;
		printf("%d", oneBit);
	}
	return 0;
}