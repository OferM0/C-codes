#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main1()
{
    FILE* f = fopen("homeworkfile1.txt", "w");

    if (f != NULL)
    {
        for (int i = 1; i <=5; i++)
        {
            for (int j = 1; j <=i; j++)
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

int main2()
{
    FILE* f = fopen("homeworkfile2.txt", "w");

    if (f != NULL)
    {
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                (i == 1) ? fputc('1', f) : (i == 2) ? fputc('2', f) : (i == 3) ? fputc('3', f) : (i == 4) ? fputc('4', f) : fputc('5', f);
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

int main3()
{
    char str1[20] = "exercise3file";
    char str2[20];
    int filenumber;
    int x = 1;

    printf("Please enter number of files\n");
    scanf("%d", &filenumber);
    
    for (int i = 1; i <= filenumber; i++)
    {
        sprintf(str2, "%s%d%s", str1, x, ".txt");
        FILE* f = fopen(str2, "w");
        if (f != NULL)
        {
            for (int j = 1; j <= x; j++)
            {
                fputc('*', f);
            }
            fclose(f);
            x++;
        }
        else
        {
            // error
            fclose(f);
        }
    }
    return 0;
}

int main4()
{
    struct Car
    {
        char name[100];
        char model[10];
        int roadage;
        int id;
    };

    struct Car car;

    strcpy(car.name, "tesla");
    strcpy(car.model, "Z-101");
    car.roadage = 12;
    car.id = 95495224;

    return 0;
}

int main5()
{
    struct Car
    {
        char name[100];
        char model[10];
        int roadage;
        int id;
    };

    struct Car car[10];
    
    for (int i = 0; i < 10; i++)
    {
        printf("Please enter name model roadage and id\n");
        scanf("%s %s %d %d", car[i].name, car[i].model, &car[i].roadage, &car[i].id);
    }

    return 0;
}

int main6()
{
    FILE* f = fopen("homeworkfile3.txt", "w");
    
    struct Item
    {
        char name[10];
        char symbol[10];
        char code[10];
    };

    struct Item item1;

    strcpy(item1.name, "tesla");
    strcpy(item1.symbol, "we");
    strcpy(item1.code, "101");

    if (f != NULL)
    {
        fputs(item1.name, f);
        fputs(item1.symbol, f);
        fputs(item1.code, f);
    }
    else
    {
        printf("Error");
    }
    fclose(f);

    return 0;
}

int main7()
{
    FILE* f = fopen("homeworkfile4.txt", "w");

    struct Item
    {
        char name[10];
        char symbol[10];
        char code[10];
    };

    struct Item item1[5];

    if (f != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            printf("Please enter name symbol and code\n");
            scanf("%s %s %s",item1[i].name, item1[i].symbol, item1[i].code);

            fputs(item1[i].name, f);
            fputc('\n', f);
            fputs(item1[i].symbol, f);
            fputc('\n', f);
            fputs(item1[i].code, f);
            fputc('\n', f);
        }
    }
    else
    {
        printf("Error");
    }
    fclose(f);

    return 0;
}

int main()
{
    FILE* f = fopen("homeworkfile4.txt", "r");
    char ch;
    char copy[10];
    int i = 0;
    int cnt = 1;

    struct Item
    {
        char name[10];
        char symbol[10];
        char code[10];
    };

    struct Item item2[5];

    if (f != NULL)
    {
        ch = fgetc(f);
        while (ch != EOF)
        {
            if (ch == '\n')
            {
                if (cnt == 1)
                {
                    strcpy(item2[i].name, copy);
                }
                if (cnt == 2)
                {
                    strcpy(item2[i].symbol, copy);
                }
                if (cnt == 3)
                {
                    strcpy(item2[i].code, copy);
                    cnt = 0;
                    i++;
                }
                cnt++;
                copy[0] = '\0';
                ch = fgetc(f);
            }
            else
            {
                sprintf(copy, "%s%c", copy, ch);
                ch = fgetc(f);
            }
        }
    }
    else
    {
        printf("Error");
    }
    fclose(f);

    return 0;
}