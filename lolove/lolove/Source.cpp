#include<locale.h>
#include<stdio.h>
#include "windows.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	printf_s("Я тебя люблюблюблюблюблюблюблюблюблюблюблюблюблюблюблюблюблю");
	Sleep(125);
	printf_s("блюблюблюблюблюблюблюблюблюблюблюблюблюблю");
	Sleep(125);
	printf_s("блюблю- \nблюблюблю");
	Sleep(125);
	while (true)
	{
		printf_s("блюблюблюблюблюблюблюблюблюблюблюблюблюблюблюблю");
		Sleep(125);
		printf_s("блюблюблюблюблюблюблюблюблюблюблюблюблюблюблю");
		Sleep(125);
		printf_s("блюблю- \nблюблюблю");
		Sleep(125);
	}
	return 0;
}