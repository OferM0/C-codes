#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

//-------------linkedlist------------------

struct Item {
	int val;
	struct Item* next;
};

struct Item* head = NULL;
void freeLinkedList();

int main()
{
	int userResponse;

	struct Item* currentItem;
	struct Item* prevItem = NULL;

	printf("Please enter number\n");
	scanf("%d", &userResponse);

	while (userResponse != 100)
	{
		currentItem = malloc(sizeof(struct Item));
		if (head == NULL)
		{
			head = currentItem;

		}
		else
		{
			prevItem->next = currentItem;
		}
		currentItem->next = NULL;
		prevItem = currentItem;

		printf("Please enter val\n");
		scanf("%d", &currentItem->val);

		printf("Please enter number\n");
		scanf("%d", &userResponse);
	}
	PrintList();
	Find44();
	printf("the id 34 is in %d place", FindId(34));
	freeLinkedList();



	return 0;
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

int PrintList()
{
	struct Item* currentItem = head;
	while (currentItem != NULL)
	{
		printf("%d\n", currentItem->val);
		currentItem = currentItem->next;
	}
	return 0;
}

int Find44()
{
	int cnt = 0;
	struct Item* currentItem = head;
	while (currentItem != NULL)
	{
		cnt = (currentItem->val == 44) ? cnt + 1 : cnt;
		currentItem = currentItem->next;
	}
	printf("There are %d times 44\n", cnt);

	return 0;
}

int FindId(int id)
{
	int cnt = 0;
	struct Item* currentItem = head;
	while (currentItem != NULL)
	{
		cnt++;
		if (currentItem->val == id)
		{
			return cnt;
		}
		currentItem = currentItem->next;
	}


}