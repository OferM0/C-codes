#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int ID_COUNTER = 0;

struct Item {
	int val;
	int val2;
	int id;
	struct Item* next;
	struct Item* prev;
};

struct Item* head = NULL;
struct Item* tail = NULL;

void push(int val, int val2);


void printList()
{
	struct Item* currentItem = head;
	printf("Head");
	while (currentItem != NULL)
	{
		printf("->(val1: %d, val2: %d, id: %d)", currentItem->val, currentItem->val2, currentItem->id);
		currentItem = currentItem->next;
	}
	printf("->Null\n");
}

void freeList()
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

void resetList()
{
	if (head != NULL)
	{
		freeList();
		head = NULL;
		tail = NULL;
	}
}

void push(int val, int val2)
{
	struct Item* curr;
	curr = (struct Item*)malloc(sizeof(struct Item));
	ID_COUNTER++;
	curr->val = val;
	curr->val2 = val2;
	curr->id = ID_COUNTER;

	if (head == NULL)
	{
		head = curr;
		tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else
	{
		curr->next = head;
		head->prev = curr;
		head = curr;
	}
}

struct Item* pop()
{
	struct Item* curr;
	curr = tail;
	
	if (tail->prev != NULL)
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	return curr;
}

int main()
{
	struct Item* item;
	int val1, val2;
	for (int i = 0; i < 10; i++)
	{
		printf("Please enter 2 values\n");
		scanf("%d %d", &val1, &val2);
		push(val1, val2);
	}
	printList();
	printf("***********\n");
	for (int i = 0; i < 9; i++)
	{
		item = pop();
		free(item);
	}
	printList();
	resetList();

	return 0;
}