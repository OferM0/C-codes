#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

struct Item {
	int val;
	struct Item* next;
	struct Item* prev;
};

struct Item* head = NULL;
struct Item* tail = NULL;

void addItem(int newItem);
struct Item* findHigher(int val);
void locateAfterTail(struct Item* item);
void locateBeforeHead(struct Item* item);
void locateBeforeItem(struct Item* newItem, struct Item* itemInList);

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

void addItem(int newItem)
{
	struct Item* curr;
	curr = (struct Item*)malloc(sizeof(struct Item));
	curr->val = newItem;

	if (head == NULL)
	{
		head = curr;
		tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else
	{
		tail->next = curr;
		curr->prev = tail;
		curr->next = NULL;
		tail = curr;
	}
}

struct Item* search(int val)
{
	struct Item* ret = NULL;
	struct Item* curr = head;

	while (curr != NULL)
	{
		if (curr->val == val)
		{
			ret = curr;
			return ret;
		}
		curr = curr->next;
	}
	return ret;
}

void Replace(struct Item* item)
{
	struct Item* replaceItem;
	replaceItem = (struct Item*)malloc(sizeof(struct Item));
	replaceItem = item;
	item= item->next;
	item->next = replaceItem;
}


void bubleSort() {

}



int main()
{
	int val;

	for (int i = 0; i < 10; i++)
	{
		printf("Please enter value\n");
		scanf("%d", &val);
		addItem(val);
	}
	printf("Unsorted list\n");
	printList();
	bubleSort();
	printf("Buble sorted list\n");
	printList();

	return 0;
}