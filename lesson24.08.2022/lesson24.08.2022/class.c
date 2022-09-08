#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1()
{
    FILE* f = fopen("file1.txt", "w");
    

    if (f != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            fputc('*', f);
            fputc('\n', f);

        }
    }
    else
	{
		// error
	}
	fclose(f);

    return 0;
}

int main_2()
{
    FILE* f = fopen("file2.txt", "w");

    if (f != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            
            for (int i = 0; i < 10; i++)
            {
                fputc('A', f);
            }
            fputc('\n', f);
        }
    }
    else
    {
        // error
    }
    fclose(f);

    return 0;
}

int main_3()
{
    FILE* f = fopen("file3.txt", "w");
    int x;

    printf("Please enter number of rows\n");
    scanf("%d", &x);

    if (f != NULL)
    {
        for (int i = 0; i < x; i++)
        {

            for (int i = 0; i < 50; i++)
            {
                fputc('*', f);
            }
            fputc('\n', f);
        }
    }
    else
    {
        // error
    }
    fclose(f);

    return 0;
}

int main_4()
{
    FILE* f = fopen("file4.txt", "w");
    int row;
    char str[10];

    printf("Please enter string\n");
    gets(str);

    printf("Please enter number of rows\n");
    scanf("%d", &row);

    if (f != NULL)
    {
        for (int i = 0; i < row; i++)
        {
            for (int i = 0; i < strlen(str); i++)
            {
                fputc(str[i], f);
            }
            fputc(' ', f);
        }
    }
    else
    {
        // error
    }
    fclose(f);

    return 0;
}

int main_5()
{
    
    char fileName[50];
    char copyfilename[50]="copy";
    char add[50] = "NOT ORIGINAL0";
    char ch;
    int i = 0;

    printf("Please enter file name\n");
    gets(fileName);
    
    strcat(copyfilename, fileName);

    FILE* f = fopen(copyfilename, "w");
    FILE* f2 = fopen(fileName, "r");

    if (f != NULL || f2!=NULL)
    {
        ch = fgetc(f2);
        while(ch!=EOF)
        {
            fputc(ch, f);
            ch = fgetc(f2);
        }
        while (add[i] != '0')
        {
            fputc(add[i], f);          
            i++;
        }

    }
    else
    {
        // error
    }
    fclose(f);
    fclose(f2);

    return 0;
}

//**********STRUCTERS**********

int main_6()
{


    struct Item
    {
        int barcode;
        int price;
        char name[100];
        char color[100];
    };

    struct Item kuku;

    struct Item item2;

    kuku.price = 12;
    strcpy(kuku.name, "Cola");
    strcpy(kuku.color, "Black");


    item2.price = 9;
    strcpy(item2.name, "Pepsi");
    strcpy(item2.color, "Black");
    //printf("Item:%s Price:%d", kuku.name, kuku.price);


    struct Item itemList[10];

    for (int i = 0; i < 3; i++)
    {

        scanf("%d %s %s %d", &itemList[i].barcode, itemList[i].name, itemList[i].color, &itemList[i].price);


        //itemList[i].color = 
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%s %s %d\n", itemList[i].name, itemList[i].color, itemList[i].price);
        //itemList[i].color = 
    }


}

int main_7()
{
    struct Worker
    {
        char name[50];
        int id;
        int age;
    };

    struct Worker workerlist[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Please enter name id and age\n");
        scanf("%s %d %d", workerlist[i].name, &workerlist[i].id, &workerlist[i].age);
    }

    return 0;
}