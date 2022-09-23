#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4496)

typedef struct
{
	int age;
} DetailsT;

struct Leaf 
{	
	// Managment or MetaData
	int level;
	struct Leaf* Left;
	struct Leaf* Right;
	struct Leaf* Parent;

	// Data (Real Data) 
	DetailsT Details;
};

struct Leaf* Root=NULL;

typedef struct QueueItem {
	struct Leaf* leaf;
	struct QueueItem* Next;
	struct QueueItem* Prev;
} TQueueItem;

TQueueItem* Head;
TQueueItem* Tail;

void Queue_Push(TQueueItem* item)
{
	if (Head == NULL)
	{
		Head = item;
		Tail = item;
		item->Next = NULL;
		item->Prev = NULL;
	}
	else
	{
		item->Next = Head;
		Head->Prev = item;
		Head = item;
	}
}

TQueueItem* Queue_Pop()
{
	TQueueItem* curr;
	curr = Tail;

	if (Tail == NULL)
	{
		return NULL;
	}
	if (Tail->Prev != NULL)
	{
		Tail = Tail->Prev;
		Tail->Next = NULL;
	}
	return curr;
}

void Queue_Status()
{
	TQueueItem* currentItem = Head;
	printf("Head");
	while (currentItem != NULL)
	{
		printf("->(leaf age:%d, leaf level:%d)", currentItem->leaf->Details.age, currentItem->leaf->level);
		currentItem = currentItem->Next;
	}
	printf("->Null\n");
}

void Queue_Clear() 
{
	TQueueItem* currentItem = Head;
	TQueueItem* releaseItem = Head;

	while (currentItem != NULL)
	{
		releaseItem = currentItem;
		currentItem = currentItem->Next;
		free(releaseItem);
	}

	Head = NULL;
	Tail = NULL;
}

void addItem(DetailsT item)
{
	struct Leaf* leafPtr = (struct Leaf*)malloc(sizeof(struct Leaf));
	leafPtr->Details = item;

	if (!Root)
	{
		leafPtr->level = 0;
		leafPtr->Left = NULL;
		leafPtr->Right = NULL;
		leafPtr->Parent = NULL;
		Root = leafPtr;
	}
	else if (!Root->Right)
	{
		leafPtr->level = 1;
		leafPtr->Left = NULL;
		leafPtr->Right = NULL;
		leafPtr->Parent = Root;
		Root->Right = leafPtr;
	}
	else if (!Root->Left)
	{
		leafPtr->level = 1;
		leafPtr->Left = NULL;
		leafPtr->Right = NULL;
		leafPtr->Parent = Root;
		Root->Left = leafPtr;
	}
}

int main()
{
	DetailsT item1, item2, item3, item4, item5;
	item1.age = 11;
	item2.age = 22;
	item3.age = 33;
	item4.age = 44;
	item5.age = 55;

	addItem(item1);
	addItem(item2);
	addItem(item3);

	TQueueItem* t1 = (TQueueItem * )malloc(sizeof(TQueueItem));
	TQueueItem* t2 = (TQueueItem*)malloc(sizeof(TQueueItem));
	TQueueItem* t3 = (TQueueItem*)malloc(sizeof(TQueueItem));
	TQueueItem* t4 = (TQueueItem*)malloc(sizeof(TQueueItem));
	TQueueItem* t5 = (TQueueItem*)malloc(sizeof(TQueueItem));

	struct Leaf* leafPtr1 = (struct Leaf*)malloc(sizeof(struct Leaf));
	struct Leaf* leafPtr2 = (struct Leaf*)malloc(sizeof(struct Leaf));
	struct Leaf* leafPtr3 = (struct Leaf*)malloc(sizeof(struct Leaf));
	struct Leaf* leafPtr4 = (struct Leaf*)malloc(sizeof(struct Leaf));
	struct Leaf* leafPtr5 = (struct Leaf*)malloc(sizeof(struct Leaf));

	leafPtr1->Details = item1;
	t1->leaf = leafPtr1;

	leafPtr2->Details = item2;
	t2->leaf = leafPtr2;

	leafPtr3->Details = item3;
	t3->leaf = leafPtr3;

	leafPtr4->Details = item4;
	t4->leaf = leafPtr4;

	leafPtr5->Details = item5;
	t5->leaf = leafPtr5;


	Queue_Push(t1);
	Queue_Push(t2);
	Queue_Push(t3);
	Queue_Push(t4);
	Queue_Push(t5);
	Queue_Status();

	Queue_Pop();
	Queue_Pop();
	Queue_Pop();

	Queue_Status();
	Queue_Clear();
	Queue_Status();


	return 0;
}