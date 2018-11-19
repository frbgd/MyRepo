#include<locale.h>
#include<stdio.h>
#include "windows.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	printf_s("п ђхсџ ыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыў");
	Sleep(125);
	printf_s("сыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыў");
	Sleep(125);
	printf_s("сыўсыў- \nсыўсыўсыў");
	Sleep(125);
	while (true)
	{
		printf_s("сыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыў");
		Sleep(125);
		printf_s("сыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыўсыў");
		Sleep(125);
		printf_s("сыўсыў- \nсыўсыўсыў");
		Sleep(125);
	}
	return 0;
}