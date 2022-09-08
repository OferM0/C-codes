#include <stdio.h>
#pragma warning(disable : 4996)
/*
new learning= switch(input)

int input=12

switch(input)
{
 case 9:

 case 10:
     printf("10");
     break;

 case 11:
     printf("11");
     break;

 case 12:
     printf("12");
     break;

 case 13:
     printf("13");
     break;

 deafult:
     printf("Not Found");
     break;
}
*/
int main1()
{

    for (int i = 1; i <= 10; i++)
    {
        (i != 7) ? printf("%d\n", i) : printf("\n");
    }
    return 0;
}

int main2()
{
    for (int i = 1; i <= 100; i++)
    {
        (i % 7 == 0 && i % 3 == 0) ? printf("%d ", i) : printf("");
    }
    return 0;
}


int main3()
{
    int input;
    int sum = 1;
    printf("Pleas enter a number\n");
    scanf("%d", &input);

    for (int i = 1; i <= input; i++)
    {
        sum = sum * i;
    }
    printf("%d\n", sum);
    return 0;
}

int main4()
{
    int num1, num2;
    int sum = 1;
    printf("Pleas enter 2 number\n");
    scanf("%d %d", &num1, &num2);
    for (int i = 1; i <= num2; i++)
    {

        sum = sum * num1;
    }
    printf("%d\n", sum);
    return 0;
}