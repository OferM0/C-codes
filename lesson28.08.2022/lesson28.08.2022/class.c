#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main1()
{
	short num;
	FILE* f;

	f = fopen("file1.bin", "w");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
	    printf("Pleas enter short number\n");
	    scanf("%hi", &num);
		fwrite(&num, sizeof(short), 1, f);
		fclose(f);
	}

	return 0;
}

int main2()
{
	int num;
	FILE* f;

	f = fopen("file1.bin", "r");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
		fread(&num, sizeof(short), 1, f);
		printf("The doubled number is: %hi\n", (num * num));
		fclose(f);
	}

	return 0;
}

int main3()
{
	int num;
	FILE* f;

	f = fopen("file2.bin", "w");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			printf("Pleas enter number\n");
			scanf("%d", &num);
			fwrite(&num, sizeof(int), 1, f);
		}
		fclose(f);
	}

	return 0;
}

int main4()
{
	int num, sum=0;
	FILE* f;

	f = fopen("C:\\Users\\oferm\\Downloads\\amir.bin", "r");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			fread(&num, sizeof(int), 1, f);
			sum += num;
		}
		fclose(f);
		printf("The sum is: %d\n", sum);
	}

	return 0;
}

int main5()
{
	struct Items 
	{
		int barcode;
		int price;
		char name[100];
		char color[100];
	};

	struct Items item1;
	FILE* f;

	f = fopen("task5.bin", "w");

	item1.barcode = 23006;
	item1.price = 10;
	strcpy(item1.name, "cola");
	strcpy(item1.color, "black");


	if (f == NULL) {
		printf("Error");
	}
	else
	{
		fwrite(&item1, sizeof(struct Items), 1, f);
	}

	return 0;
}

int main6()
{
	struct Items
	{
		int barcode;
		int price;
		char name[100];
		char color[100];
	};

	struct Items item1;
	FILE* f;

	f = fopen("struct.bin", "r");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
		fread(&item1, sizeof(struct Items), 1, f);
		printf("%d", item1.barcode);
		printf("%d", item1.price);
		printf("%s", item1.name);
		printf("%s", item1.color);
	}

	return 0;
}