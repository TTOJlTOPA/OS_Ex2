#include <iostream>
#include <fstream>
#include <Windows.h>
#include "order.h"
using namespace std;

int main(int args, char* argv[])
{
	setlocale(LC_ALL, "rus");

	ifstream fin(argv[1], ios::binary);
	ofstream fout(argv[2]);
	Order orderCur;
	int num;

	switch (atoi(argv[3])) 
	{
	case 1:
		fout << "����� �� ������������� �������. ���� " << argv[1] << endl;
		break;
	case 2:
		fout << "����� �� ��������������� �������. ���� " << argv[1] << endl;
		break;
	default:
		printf("%s", "�������� ��� ������.");
		fin.close();
		fout.close();
		return -1;
	}
	fin.seekg(0, ios::beg);
	fin.read((char*)&num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		fin.read((char*)&orderCur, sizeof(Order));
		fout << "��� ������: " << orderCur.n << endl;
		fout << "�������� ������: " << orderCur.name << endl;
		switch (atoi(argv[3])) {
		case 1:
			fout << "����������: " << orderCur.amountSold << endl << "���������: " << orderCur.price * orderCur.amountSold << endl;
			break;
		case 2:
			fout << "����������: " << orderCur.amountUnsold << endl << "���������: " << orderCur.price * orderCur.amountUnsold << endl;
			break;
		default:
			fin.close();
			fout.close();
			return -1;
		}
	}

	fin.close();
	fout.close();

	return 1;
}