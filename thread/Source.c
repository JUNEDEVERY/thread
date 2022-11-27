
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>

#define _CRT_SECURE_NO_WARNINGS
DWORD WINAPI ThreadFactorial(DWORD n);
DWORD WINAPI ThreadFib(DWORD n);
VOID Function(VOID);

int main() {
	system("chcp 1251 > nul");
	Function();
	return 0;
}


VOID Function(VOID) {

	while (1) {
		DWORD n;
		printf("Введите n =>");
		scanf_s("%d", &n);
		HANDLE hF[2];
		hF[0] = CreateThread(NULL, 0, ThreadFactorial, n, 0, 0);
		hF[1] = CreateThread(NULL, 0, ThreadFib, n, 0, 0);
		WaitForMultipleObjects(2, hF, TRUE, INFINITE); // завершение потока перед завершением программы
	}
}


DWORD WINAPI ThreadFactorial(DWORD n) {

	int f = 1;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0 || i == 1) { // условие остановки рекурсии
			f = 1;
		}
		else {
			f *= i;
		}
		printf("Факториал %d равен %d \n", i, f);
	}
	ExitThread(0);
}
DWORD WINAPI ThreadFib(DWORD n) {

	int f1 = 0, f2 = 1, f3 = 1;
	for (int i = 0; i <= n; i++)
	{
		printf("%d элемент фибоначи равен %d\n", i, f1);
		f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
	}
	ExitThread(0);
}