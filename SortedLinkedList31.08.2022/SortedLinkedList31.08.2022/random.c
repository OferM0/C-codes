#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

//-------------Random--------------------------

int main_1()
{
	int sum = 0;
	int a;
	time_t i = time();
	srand(i);

	for (int i = 0; i < 100000; i++)
	{
		a = rand();
		sum += a;
		printf("%d\n", a);
	}
	printf("%d", (sum / 100000));

	return 0;
}
