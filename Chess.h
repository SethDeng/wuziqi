#pragma once
#include <iostream>
#include<tchar.h>
#include <windows.h>
#include<iomanip>
#include<stdlib.h>
#define WIN32_LEAN_AND_MEAN		// �� Windows ͷ���ų�����ʹ�õ�����
using namespace std;
class Chess
{

public:
	enum {MapX=18,MapY=18};
	int map[MapY+1][MapX+1] = { 0 }; //����λ��

	void Map(); //��ʾ��ͼ
	int Num;//�ڼ�����
	bool IsBlack = true;//������
	int SetPoint();
	int start(); //��ʼ
	int Win();
	Chess();
	~Chess();
};

