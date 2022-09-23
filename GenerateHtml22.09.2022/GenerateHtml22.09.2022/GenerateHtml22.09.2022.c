#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

void createHtmlFile()
{
    FILE* f = fopen("file.txt", "w");
    
    if (f)
    {
            fputs("<html>", f);
            fputs("<head>", f);
            fputs("<title>", f);
            fputs("Hi", f);
            fputs("</title>", f);
            fputs("</head>", f);
            fputs("<body>", f);
            /*fputs("<table border = \"1\">", f);
            fputs("<tr>", f);
            fputs("< td>", f);
            fputs("1", f);
            fputs("< / td >", f);
            fputs("< td>", f);
            fputs("2", f);
            fputs("< / td >", f);
            fputs("< / tr>", f);
            fputs("< / table>", f);*/
            for (int i = 0; i < 20; i++)
            {
                fputs("<img src = \"32bit.bmp\"/>", f);
            }
           
            fputs("</body>", f);
            fputs("</html>", f);
            fclose(f);
    }
    else
    {
        // error
    }
}

void createHtmlFileByGetFromUser()
{
    char text [1000];
    char imgPath [100];
    printf("Please enter image path\n");
    scanf("%s", imgPath);
    FILE* f = fopen("file2.html", "w");

    if (f)
    {
        fputs("<html><head><title>Hi</title></head><body><div style = \"background-color: green\">", f);
        sprintf(text ,"%s%s%s", "<img src = \"", imgPath, "\"</div></body></html>");
        fputs(text, f);
        fclose(f);
    }
    else
    {
        // error
    }
}

void createHtmlFileByGetFromUser2()
{
    int div;
    FILE* f = fopen("file3.html", "w");

    if (f)
    {
        printf("Please enter number of div's\n");
        scanf("%d", &div);

        fputs("<html><head><title>Hi</title></head><body>", f);
        for(int i=0; i<div; i++)
        { 
        fputs("<div style=\"background-color: blueviolet; width: 100px; height: 100px; border: 1px solid black; \"></div>", f);
        }
        fputs("</body></html>", f);
        fclose(f);
    }
    else
    {
        // error
    }
}

void makeItDaynemic() {
    char arrHtml[1000];
    char* tokenDaynemic;
    char* tokenDaynemic2;
    char userName[100];
    int result;
    FILE* f2write = fopen("tryToGenerate4.html", "w");
    FILE* f = fopen("GenerateFromHere.txt", "r");
    if ((f == NULL) || (f2write == NULL)) {
        printf("ERROR");
    }
    else {
        while (fgets(arrHtml, sizeof(arrHtml), f))
        {
            tokenDaynemic = strtok(arrHtml, "[[[");
            tokenDaynemic2 = strtok(NULL, "]]]");
            tokenDaynemic2 = strtok(NULL, "]]]");
            result = strcmp(tokenDaynemic, "<td>");
            if (result == 0)
            {
                printf("Dear user - please enter your name:");
                scanf("%s",userName);
                sprintf(arrHtml, "%s %s %s\n", arrHtml, userName, tokenDaynemic2);

            }
            printf("%s", arrHtml);
            fputs(arrHtml, f2write);
        }
    }
    fclose(f2write);
    fclose(f);
}
/*
void makeItDaynemic() {
    char arrHtml[1000];
    char* tokenDaynemic;
    char userName[100];
    int result;
    FILE* f2write = fopen("tryToGenerate4.html", "w");
    FILE* f = fopen("GenerateFromHere.txt", "r");
    if ((f == NULL) || (f2write == NULL)) {
        printf("ERROR");
    }
    else {
        while (fgets(arrHtml, sizeof(arrHtml), f))
        {
            tokenDaynemic = strtok(arrHtml, "[");
            result = strcmp(tokenDaynemic, "<td>");
            if (result == 0)
            {
                printf("Dear user - please enter the number of divs you want:");
                gets(userName);
                sprintf(arrHtml, "<td> %s </td>\n", userName);

            }
            printf("%s", arrHtml);
            fputs(arrHtml, f2write);
        }
    }
}*/

int main()
{
    //createHtmlFile();
    //createHtmlFileByGetFromUser();
    //createHtmlFileByGetFromUser2();
    makeItDaynemic();
    return 0;
}