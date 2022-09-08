#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1()
{
	FILE* f;
	int size;

	struct Students
	{
		int age;
		int grade;
		int id;
	};

	struct Students* list;
	struct Students* currentList;

	printf("Please enter number of allocations\n");
	scanf("%d", &size);

	currentList = (struct Students*)malloc(sizeof(struct Students) * size);
	list = currentList;

	f = fopen("file1.bin", "w");

	for (int i = 0; i < size; i++)
	{
		printf("Please enter age grade and id\n");
		scanf("%d %d %d", &currentList->age, &currentList->grade , &currentList->id);
		currentList++;
	}
	fwrite(list, sizeof(struct Students), size, f);
	fclose(f);
	free(list);

	return 0;
}

int main_2()
{
	FILE* f;
	int id, sumId = 0;

	struct Students
	{
		int id;
		int grade;
		int age;
	};

	struct Students stu;

	f = fopen("file1.bin", "r");

	if (!f) {
		printf("Error");
		return;
	}

	while (fread(&stu, sizeof(struct Students), 1, f))
	{
		sumId += stu.id;
		printf("%d\n", stu.id);
	}
	printf("%d", sumId);

	fclose(f);

	return 0;
}