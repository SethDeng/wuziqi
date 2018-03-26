#include "Chess.h"



void Chess::Map()
{
	system("cls");
	int t=0;
	while (t<MapX)
		cout << setw(2) << t++;
	cout << endl;
	int j, i = j = 0;
	//y��
	for (; i <= MapY; i++)
	{
		j = 0;  //x��
		for (; j <= MapX; j++)
		{
			if (map[i][j] == 0) {
				if (i == 0 && j == 0)
					cout << "��";
				else if (j == 0 && i == MapY)
					cout << "��";
				else if (j == MapX && i == 0)
					cout << "��";

				else if (j == MapX && i == MapY)
					cout << "��";

				else if (i == 0 && j != 0)
					cout << "��";
				else if (i != 0 && j == 0)
					cout << "��";
				else if (i == MapY&&j !=0)
					cout << "��";
				else if (i != 0 && j == MapX)
					cout << "��";
				else
				{
					cout << "��";
				}
			}
			else if (map[i][j] == 1)
			{
				cout<<"��";
			}
			else if (map[i][j] == 2)
			{
				cout<<"��";
			}
		}
		cout << "\n";
	}
}

int Chess::SetPoint()
{
	int  j;
	int i;
	cout << "���������ӵ�x���y�ᣨ�Կո����������99�˳���\n";
	cout << "������" << (IsBlack ? _T("����:") : _T("����:"));
	cin.clear();
	cin >> i;
	cin >> j;
	if (i == 99)
		return 0;
	if (i < 0 || j < 0 || i > MapX || j > MapY)
	{
		printf("���벻�����̷�Χ��, ����������!\n");
		//cout << unitbuf;
		while ((i = getchar()) != EOF && i != '\n');
		cin.sync();
		SetPoint();
	}
	else if (map[j][i] != 0)
	{
		printf("����λ����������, ����������!\n");
		SetPoint();
	}
	else
	{//���� Ϊtrue 1
		if (IsBlack)
		{
			map[j][i] = 1;
			Num++;
		}
		else
		{
			map[j][i] = 2;
		}
		IsBlack = !IsBlack;
	}
	return 1;
}

int Chess::Win()
{
	int p;//��¼ ��ʱ ���ӵ��Ǻڻ��ǰ�
	p=IsBlack == true ? 2 : 1;
	int x;//10��
	int y;//20��
	int count = 0;
	//y��  y=j ע�� �� ��20�� 
	for (int j = 0; j < MapY; j++)
	{//X��  x=i ��10��
		for (int i = 0; i < MapX; i++)
		{
			if (map[j][i] != p)
			   continue;

			//���ŷ��� y�� ����
			    x = i, y = j,count = 0;
			while (--y >= 0 && map[y][x] == p)
				count++;
			y = j;
			while (++y < MapY && map[y][x] == p)
				count++;
			if (count+1 >= 5)
				return p;

			//�᷽�� x�� ����
		    	x = i, y = j,count = 0;
			while (--x >= 0 && map[y][x] == p)
				count++;
			x = i;
			while (++x < MapX&&map[y][x] == p)
				count++;
			if (count + 1 >= 5)
				return p;

			//��б�ҷ���
		    x = i, y = j, count = 0;
			while ((--y >=0&&--x>=0) && map[y][x] == p)
				count++;
			x = i, y = j;
			while ((++y < MapY&&++x<MapX) && map[y][x] == p)
				count++;
			if (count + 1 >= 5)
				return p;

			//��б����
			x = i, y = j, count = 0;
			while ((++y < MapY && --x >= 0) && map[y][x] == p)
				count++;
			x = i, y = j;
			while ((--y>=0 &&++x<MapX) && map[y][x] == p)
				count++;
			if (count + 1 >= 5)
				return p;
			count = 0;
		}
	}
	return 0;
}

int Chess::start()
{
	int i=0;
	int winer = 0;
	char T = 'y';
	while (T=='y'||T=='Y')
	{
		Map();
		i= SetPoint();
		if (i==0)
			return 0;
		winer = Win();
		if (winer == 1)
		{
			cout << "���ӻ�ʤ\n";
			cout << "�����Ƿ���Ҫ���¿�ʼ����y/n��" << endl;
			cin >> T;
		}
		if (winer == 2)
		{
			cout << "���ӻ�ʤ";
			Sleep(1000);
			cout << "�����Ƿ���Ҫ���¿�ʼ����y/n��" << endl;
			cin >> T;
		}

	}
	return 0;
}
Chess::Chess()
{
	Num = 0;
}


Chess::~Chess()
{
}
