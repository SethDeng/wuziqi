#include<iostream>
#include"Chess.h"
//#include <stdio.h>
//#include <tchar.h>
//#include <stdlib.h>
#include <windows.h>

#define WIN32_LEAN_AND_MEAN		// �� Windows ͷ���ų�����ʹ�õ�����
using namespace std;
 
int main()
{
	system("color F0");
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "������");
	int winer = 0;

	Chess Temp;
	Temp.start();
	return 0;
}