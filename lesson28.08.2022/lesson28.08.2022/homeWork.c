#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1()
{
	int numbers[10];
	FILE* f;

	f = fopen("HW_file1.bin", "w");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			printf("Pleas enter number\n");
			scanf("%d", &numbers[i]);
		}
		fwrite(numbers, sizeof(int), 10, f);

		fclose(f);

		/*f = fopen("HW_file1.bin", "r");
		for (int i = 0; i < 10; i++)
		{
			fread(&num, sizeof(int), 1, f);
			printf("%d ", num);
		}
		fclose(f);*/
	}

	return 0;
}

int main_2()
{
	int numbers1[4];
	int numbers2[8];
	int sum1 = 0, sum2 = 0;
	FILE* f;

	for (int i = 0; i < 4; i++)
	{
		printf("Pleas enter number\n");
		scanf("%d", &numbers1[i]);
		sum1 += numbers1[i];
	}

	for (int i = 0; i < 8; i++)
	{
		printf("Pleas enter number\n");
		scanf("%d", &numbers2[i]);
		sum2 += numbers2[i];
	}


	f = fopen("HW_file2.bin", "w");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
		if (sum1 > sum2)
		{
			fwrite(numbers1, sizeof(int), 4, f);
		}
		else
		{
			fwrite(numbers2, sizeof(int), 8, f);
		}
		fclose(f);
	}

	return 0;
}

int main_3()
{
	struct Items
	{
		int val;
		char name[100];
		short answer;
	};

	struct Items item1, item2, item3;
	FILE* f;

	item1.val = 23006;
	strcpy(item1.name, "blue");
	item1.answer = (item1.val > 10 && strlen(item1.name) > 5) ? 1 : 0;

	item2.val = 230;
	strcpy(item2.name, "orange");
	item2.answer = (item2.val > 10 && strlen(item2.name) > 5) ? 1 : 0;

	item3.val = 5;
	strcpy(item3.name, "purple");
	item3.answer = (item3.val > 10 && strlen(item3.name) > 5) ? 1 : 0;

	f = fopen("HW_file3.bin", "w");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
		fwrite(&item1, sizeof(struct Items), 1, f);
		fwrite(&item2, sizeof(struct Items), 1, f);
		fwrite(&item3, sizeof(struct Items), 1, f);
		fclose(f);
	}

	return 0;
}

int main_4()
{
	int num, cnt=0, sum = 0;
	int arr[12] = { 23, 44, 56, 100, 1009, -23, 4, 6, 10, 19, 0, -53 };

	FILE* f = fopen("HW_file4.bin", "w");

	if (f == NULL)
	{
		printf("Error");
	}
	else
	{
		fwrite(arr, sizeof(int), 12, f);
		fclose(f);
	}

	return 0;
}

int main_5()
{
	int num, cnt = 0, sum = 0;
	FILE* f;

	f = fopen("Q4.bin", "r");

	if (f)
	{
		while (fread(&num, sizeof(int), 1, f))
		{
			cnt++;
			printf("%d ", num);
			sum += num;
		}
		printf("sum is: %d and %d numbers", sum, cnt);
		fclose(f);
	}
	else 
	{
		printf("Error");
	}

	return 0;
}

int main()
{
	//FILE* f;
	int size,getval, sumVal = 0;
	char getname[100];
	struct Items
	{
		int val;
		char name[100];
		short answer;
	};

	struct Items* list;
	struct Items* currentList;

	printf("Please enter number of allocations\n");
	scanf("%d", &size);

	currentList = malloc(sizeof(struct Items) * size);
	list = currentList;

	for (int i = 0; i < size; i++)
	{
		printf("Please enter val and name\n");
		scanf("%d %s",&getval, getname);
		currentList->val = getval;
		strcpy(currentList->name, getname);
		sumVal +=getval;
		currentList->answer = (currentList->val > 10 && strlen(currentList->name) > 5) ? 1 : 0;
		currentList++;
	}
	/*
	f = fopen("HW_file5.bin", "w");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
	    fwrite(list, sizeof(struct Items), size, f);
		fclose(f);
	}*/
	free(list);
	printf("sum is: %d", sumVal);

	return 0;
}