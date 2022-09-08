#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

void testCopy(FILE* srcFile, FILE* desFile);

int main_1(int argc, char* argv[])
{
	testCopy(argv[1], argv[2]);
	return 0;
}

void testCopy(FILE* srcFile, FILE* desFile)
{
	char* f;
	FILE* src;
	FILE* des;
	char c;
	int bytes = 0;
	printf("start\n");
	src =fopen(srcFile, "r");
	c = fgetc(src);
	while (c!=EOF)
	{
		bytes++;
		c = fgetc(src);
	}
	fclose(src);

	f = (char*)malloc(sizeof(char)* bytes);
	src =fopen(srcFile, "r");
	fread(f, sizeof(char), bytes, src);
	fclose(src);
	des=fopen(desFile, "w");
	fwrite(f, sizeof(char), bytes, des);
	fclose(des);
	free(f);
	printf("end\n");
}