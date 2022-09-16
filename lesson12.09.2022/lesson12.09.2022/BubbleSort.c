#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

typedef struct ItemNum
{
	int num;
	struct ItemNum* next;
	struct ItemNum* prev;

} t_ItemNum;
t_ItemNum* Head;
t_ItemNum* Tail;

void Log(char message[100])
{
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);

	char str[100];
	FILE* f = fopen("my5.log", "a");

	sprintf(str, "%d.%d.%d %d:%d:%d - %s\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
	fputs(str, f);
	fclose(f);
}

void LogEvent(char message[100])
{
	char str[100];
	sprintf(str, "%s %s", "Event – ", message);
	Log(str);
}

void LogError(char message[100])
{
	char str[100];
	sprintf(str, "%s %s", "Error - ", message);
	Log(str);
}

void LogEventVal(char message[100], int val)
{
	char str[100];
	sprintf(str, "Item val %d : %s", val, message);
	Log(str);
}

void printList()
{
	t_ItemNum* currentItem = Head;
	printf("Head");
	while (currentItem != NULL)
	{
		printf("->(%d)", currentItem->num);
		currentItem = currentItem->next;
	}
	printf("->Null\n");
}

void freeList()
{
	t_ItemNum* currentItem = Head;
	t_ItemNum* releaseItem = Head;
	while (currentItem != NULL)
	{
		releaseItem = currentItem;
		currentItem = currentItem->next;
		free(releaseItem);
	}
}

void resetList()
{
	if (Head != NULL)
	{
		freeList();
		Head = NULL;
		Tail = NULL;
	}
}

void ReplaceItem(t_ItemNum* item)
{
	if (item == NULL)
	{
		LogEventVal("No need to swap. No Items in list", item->num);

	}
	else if (item->next == NULL)
	{
		LogEventVal("No need to swap", item->num);

	}
	else if (item == Head && item->next == Tail)
	{
		item->next = NULL;
		item->prev = Tail;
		Tail->prev = NULL;
		Tail->next = item;
		Tail = item;
		Head = item->prev;
	}
	else if (item == Head && item->next != NULL)
	{
		item->next = item->next->next;
		item->next->prev->next = item;
		item->next->prev->prev = NULL;
		item->prev = item->next->prev;
		item->next->prev = item;
		Head = item->prev;
	}
	else if (item->next == Tail)
	{
		item->prev->next = item->next;
		item->next->prev = item->prev;
		item->next->next = item;
		item->prev = item->next;
		item->next = NULL;
		Tail = item;
	}
	else {
		// regular swap
		item->prev->next = item->next;
		item->next->prev = item->prev;
		item->next->next->prev = item;
		item->prev = item->next;
		item->next = item->next->next;
		item->prev->next = item;
	}
}

void AddItemVal(int val)
{
	t_ItemNum* newItem = malloc(sizeof(t_ItemNum));
	LogEventVal("Create new Item", val);

	newItem->num = val;
	newItem->next = NULL;

	if (Head == NULL) {
		LogEventVal("List is started now ", val);

		Head = newItem;
		Tail = newItem;
		newItem->prev = NULL;
	}
	else
	{
		LogEventVal("Val is Added  ", val);
		Tail->next = newItem;
		newItem->prev = Tail;
		Tail = newItem;
	}
}

void Sort()
{
	LogEvent("Start of Sorting the list");
	t_ItemNum* curr = Head;

	if (!curr) {
		LogEvent("The List is empty");
		return;
	}
	char change = 1;

	while (change != 0)
	{
		change = 0;
		while (curr != NULL)
		{
			if (curr->next != NULL && curr->num > curr->next->num)
			{
				ReplaceItem(curr);
				change++;
			}
			curr = curr->next;
		}
		curr = Head;
	}
	LogEvent("End of Sorting the list");
}

main()
{
	time_t start, end;

	LogEvent("System Is Starting");
	Head = NULL;
	Tail = NULL;
	time_t i = time(NULL);
	srand(i);

#ifdef DEBUG_REPLACE_FUNCTION
	AddItemVal(1);
	AddItemVal(2);
	//	ReplaceItem(Head);
	AddItemVal(3);
	//	ReplaceItem(Head);
	AddItemVal(4);
	//	ReplaceItem(Tail);
	ReplaceItem(Tail->prev->prev);
#endif

	LogEvent("Creating list of 1000 random items");
	for (int i = 0; i <= 100; i++)
	{
		AddItemVal(rand());
	}
	printf("****************************\n");
	printf("Unsorted List\n");
	printf("****************************\n\n");
	printList();
	LogEvent("Printing unsorted list");
	printf("\n****************************\n");
	printf("Sorted List\n");
	printf("****************************\n\n");

	start = time(NULL);
	Sort();
	end = time(NULL);

	printList();
	LogEvent("Printing sorted list");

	printf("\n run time of sort proccess is %d:", (end - start));
	LogEvent("End Of System");
}