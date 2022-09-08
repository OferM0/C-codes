#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable : 4996)

#define FILE_NAME "Data.bin"
#define Version 1

typedef struct s_item{
	int key;
	int val;
	struct s_item* next;
	struct s_item* prev;
} t_item;

t_item* head=NULL;
t_item* tail=NULL;

/*creating instance of typedef vs struct
struct s_item s;
t_item s1;*/

typedef struct {
	int version;
	int serialNum;
	int itemsCount;
	char reserve[100];
} t_headerFile;

t_headerFile fileHeader;

//free list
void freeList()
{
	t_item* curr;
	curr = head;
	while (curr != NULL)
	{
		curr = curr->next;
		free(head);
		head = curr;
	}
	head = NULL;
	tail = NULL;
}

void printList()
{
	t_item* currentItem = head;
	printf("Head");
	while (currentItem != NULL)
	{
		printf("->(key: %d, val: %d)", currentItem->key, currentItem->val);
		currentItem = currentItem->next;
	}
	printf("->Null\n");
}

t_item* newItem(int key, int val)
{
	t_item* ret= (t_item*)malloc(sizeof(t_item));
	ret->key = key;
	ret->val = val;

	if (head == NULL)
	{
		head = ret;
		tail = ret;
		ret->next = NULL;
		ret->prev = NULL;
	}
	else
	{
		tail->next = ret;
		ret->prev = tail;
		ret->next = NULL;
		tail = ret;
	}
	return ret;
}

//save list and header in file
void saveListInFile(char fileName [20])
{
	int cnt=0;
	t_item* curr = head;
	FILE* f = fopen(fileName, "w");

	if (!f)
	{
		//error
		return 1;
	}
	fwrite(&fileHeader, sizeof(t_headerFile), 1, f);
	while (curr->next != NULL)
	{
		cnt++;
		fwrite(curr, sizeof(t_item), 1, f);
		curr = curr->next;
	}
	fileHeader.itemsCount = cnt;
	fclose(f);
}

//build the list by reading from file
void buildListByFile(char fileName[20])
{
	//read from file
	FILE* f = fopen(fileName, "r");
	if (!f)
	{
		//error
		return 1;
	}

	int read = fread(&fileHeader, sizeof(t_headerFile), 1, f);
	if (read == 0)
	{
		//error
		return 1;
	}

	//build the list
	head = NULL;
	tail = NULL;
	for (int i = 0; i < fileHeader.itemsCount; i++)
	{
		t_item* curr = (t_item*)malloc(sizeof(t_item));
		read = fread(curr, sizeof(t_item), 1, f);
		newItem(curr->key, curr->val);
	}
	fclose(f);

}

t_item* search(int key)
{
	t_item* ret = NULL;
	t_item* curr = head;
	int check = 0;

	while (curr != NULL)
	{
		if (curr->key == key)
		{
			ret = curr;
			return ret;
		}
		curr = curr->next;
	}
	return ret;
}

void removeOne(int key)
{
	t_item* curr;
	curr = search(key);

	if (curr)
	{
		if (curr == tail && curr != head)
		{
			tail = curr->prev;
			tail->next = NULL;
			free(curr);
		}
		else if (curr == head && curr != tail)
		{
			head = curr->next;
			head->prev = NULL;
			free(curr);
		}
		else if (curr != head && curr != tail && curr != NULL)
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr);
		}
		else if (curr == head && curr == tail)
		{
			free(curr);
			head = NULL;
			tail = NULL;
		}
	}
	else
	{
		printf("Not found in dictionary!\n");
	}
}

int main()
{	int  key, val, id;
	char userResponse;
	char fileName[20];
	t_item* show;

	t_headerFile fileHeader;
	fileHeader.version = 1;
	fileHeader.itemsCount = 0;
	fileHeader.serialNum = 12345;

	printf("Please choose what to do. A- for adding, P- for printing dictionary,F- for show value, U-for updating, D-for removing, S-for saving, L-for loading, E- for exit.\n");
	scanf(" %c", &userResponse);
	while (userResponse != 'E')
	{
		switch (userResponse)
		{
		case 'A':
			printf("Please enter key and value\n");
			scanf("%d %d", &key, &val);
			newItem(key, val);
			fileHeader.itemsCount++;
			break;

		case 'P':
			if (head != NULL && tail != NULL)
			{
				printList();
			}
			else
			{
				printf("NULL\n");
			}
			printf("***********\n");
			break;

		case 'D':
			printf("Please enter key for removing\n");
			scanf("%d", &id);
			removeOne(id);
			break;

		case 'F':
			printf("Please enter key to show value\n");
			scanf("%d", &id);
			show = search(id);
			(show) ? printf("The value is: %d\n", show->val) : printf("***\n");
			break;

		case 'U':
			printf("Please enter key to update his new value\n");
			scanf("%d", &id);
			show = search(id);
			if (show)
			{
				printf("Please enter new value\n");
				scanf("%d", &val);
				show->val = val;
			}
			else {
				printf("***\n");
			}
			break;

		case 'S':
			printf("Please enter name of file\n");
			scanf("%s", fileName);
			saveListInFile(fileName);
			break;

		case 'L':
			printf("Please enter name of file\n");
			scanf("%s", fileName);
			buildListByFile(fileName);
			
			break;

		default:
			printf("Wrong selection. Try be more sharp\n");
			break;
		}

		printf("Please choose what to do. A- for adding, P- for printing dictionary,F- for show value, U-for updating, D-for removing, S-for saving, L-for loading, E- for exit.\n");
		scanf(" %c", &userResponse);
	}
	printf("Thank you for use our Great service. See you next time. Drink only water\n");
	freeList();

	return 0;
}