#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

//-------------LinkedList------------------
/*
struct Item {
	int val;
	struct Item* next;
	//struct Item* prev;
};

struct Item* head = NULL;
//struct Item* tail = NULL;

void printList()
{
	struct Item* currentItem = head;
	printf("Head");
	while (currentItem != NULL)
	{
		printf("->(%d)", currentItem->val);
		currentItem = currentItem->next;
	}
	printf("->Null\n");
}

void freeLinkedList()
{
	struct Item* currentItem = head;
	struct Item* releaseItem = head;
	while (currentItem != NULL)
	{
		releaseItem = currentItem;
		currentItem = currentItem->next;
		free(releaseItem);
	}
}

void generateList()
{
	int ranNum;
	struct Item* currentItem;
	struct Item* prevItem = NULL;
	head = NULL;

	for (int i = 0; i < 10; i++)
	{
		ranNum = rand();
		currentItem = malloc(sizeof(struct Item));
		if (head == NULL)
		{
			head = currentItem;
		}
		else
		{
			prevItem->next = currentItem;
		}
		currentItem->val = ranNum;
		currentItem->next = NULL;
		prevItem = currentItem;
	}
	printList();
	//freeLinkedList();
}

void generateXList(int x)
{
	int ranNum;
	struct Item* currentItem2;
	struct Item* prevItem2 = NULL;
	head = NULL;

	for (int i = 0; i < x; i++)
	{
		ranNum = rand();
		currentItem2 = malloc(sizeof(struct Item));
		if (head == NULL)
		{
			head = currentItem2;
		}
		else
		{
			prevItem2->next = currentItem2;
		}
		currentItem2->val = ranNum;
		currentItem2->next = NULL;
		prevItem2 = currentItem2;
	}
	printList();
	freeLinkedList();
}



struct Item* findVal(int val)
{
	struct Item* currentItem = head;
	while (currentItem != NULL)
	{
		if (currentItem->val == val)
		{
			return currentItem;
		}
		currentItem = currentItem->next;
	}
}

struct Item* changeVal(int oldVal, int newVal)
{
	struct Item* currentItem = head;
	while (currentItem != NULL)
	{
		if (currentItem->val == oldVal)
		{
			currentItem->val = newVal;
			return currentItem;
		}
		currentItem = currentItem->next;
	}
}

/*
struct Item* insertNewItem(int val)
{

}


int main_0()
{
	int x;
	printf("Random 10 List\n");
	printf("***************************\n");
	generateList();
	printf("***************************\n\n");

	printf("find address of val=41\n");
	printf("***************************\n");
	printf("[%p]\n", findVal(421));
	printf("***************************\n\n");

	printf("find address of val=41 and change it to 56\n");
	printf("***************************\n");
	printf("[%p]\n",changeVal(41, 56));
	printf("***************************\n\n");

	freeLinkedList();

	printf("Random X List\n");
	printf("***************************\n");
	printf("Pleas enter number of random rolls\n");
	scanf("%d", &x);
	printf("***************************\n");
	generateXList(x);
	printf("***************************\n\n");

	printf("Print 100 random list\n");
	printf("***************************\n");
	generateXList(100);
	printf("***************************\n");



	return 0;
}*/