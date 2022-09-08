#include <stdio.h>
#include <limits.h>
#include <string.h>
#pragma warning(disable : 4996)

int main1()
{
	/*lightBit(1);
	
	int bits[8] = { 0,0,0,0,0,0,0,0 };
	onOffBit(6, bits);
	onOffBit(6, bits);
	onOffBit(6, bits);
	onOffBit(8, bits);
	onOffBit(1, bits);
	onOffBit(4, bits);
	
	leftShifts(-844);
    */
	char A = 120;
	int B = A;
	printf("%d\n", B);
	B <<= 3;
	A = (char)B;
	printf("%d", A);


	return 0;
}
int lightBit(int num)
{
	int bits[8] = { 0,0,0,0,0,0,0,0 };
	bits[num-1] = 1;
	for(int i=7; i>=0; i--)
	{
		printf("%d ", bits[i]);
	}

	return 0;
}

int onOffBit(int num, int bits [])
{
	//int bits[8] = { 0,0,0,0,0,0,0,0 };

	if (bits[num - 1] == 1) 
	{
		bits[num - 1] = 0;
	}
	else
	{
		bits[num - 1] = 1;
	}

	for (int i = 7; i >= 0; i--)
	{
		printf("%d ", bits[i]);
	}
	printf("\n");

	return 0;
}

int leftShifts(int num)
{
	int cnt = 0;
	while (num != 0) {
		num <<=1;
		cnt++;
	}

	printf("%d", cnt);

	return 0;
}