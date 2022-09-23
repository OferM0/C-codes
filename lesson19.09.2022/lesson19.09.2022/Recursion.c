#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#include "ofer_Utilities.h"

int Add(int num)
{
	if (num == 101)
	{
		return 0;
	}
	printf("Num %d\n", num);
	return Add(num + 1) + 1;

}

int main_1()
{
	Log_Init("file.log");
	Log_Event("start");

	int a = Add(1);

	return 0;
}
