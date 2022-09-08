#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)



//1
//Write a function that allocates 4 places of int and puts numbers in there after matching,
//the four numbers should be printed.
int mallocPrint4()
{
    int num;
    int* b;
    b = malloc(sizeof(int) * 4);
    int* original = b;
    for (int i = 0; i < 4; i++)
    {
        printf("Pleas enater number\n");
        scanf("%d", &num);
        *b = num;
        printf("%d\n", *b);
        b++;
    }

    free(original);

    return 0;
}

//2
int* alloc5Numbers(int n1, int n2, int n3, int n4, int n5)
{
    int* a;
    a = malloc(sizeof(int) * 5);
    int* adress = a;

    *a = n1;
    a++;
    *a = n2;
    a++;
    *a = n3;
    a++;
    *a = n4;
    a++;
    *a = n5;

    return adress;
}

int printNum(int* numberList)
{
    int sum = 0;
    int* adress = numberList;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *adress);
        sum = sum + *adress;
        adress++;
    }

    return sum;
}

//3
int sumScanNumbers(int x)
{

    int sum = 0;
    int* list = malloc(sizeof(int) * x);

    for (int i = 0; i < x; i++)
    {
        printf("Pleas enter number\n");
        scanf("%d", list);
        sum = sum + *list;
        list++;
    }

    free(list);
    return sum;
}
int file()
{
    FILE* f;
    int cnt = 0;

    f = fopen("C:\\Users\\oferm\\source\\repos\\C learning\\lesson22.08.2022\\file1.txt", "r");
    if (f == NULL)
    {
        // problem
        // error message
    }
    else
    {
        char ch = fgetc(f);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = fgetc(f);
        }
        fclose(f);
    }
    return 0;
}

int main_1()
{
    /*1
    mallocPrint4();

    2*/
    int* adress;
    int sum;

    adress = alloc5Numbers(10, 200, 65, 32, 7);
    sum = printNum(adress);
    printf("%d", sum);

    free(adress);

    /*3
    int x;
    printf("Pleas enter how many numbers you want to sum\n");
    scanf("%d", &x);
    printf("%d", sumScanNumbers(x));
    */
}