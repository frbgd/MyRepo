#include<locale.h>
#include<stdio.h>
#include "windows.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	printf_s("� ���� �����������������������������������������������������");
	Sleep(125);
	printf_s("������������������������������������������");
	Sleep(125);
	printf_s("������- \n���������");
	Sleep(125);
	while (true)
	{
		printf_s("������������������������������������������������");
		Sleep(125);
		printf_s("���������������������������������������������");
		Sleep(125);
		printf_s("������- \n���������");
		Sleep(125);
	}
	return 0;
}