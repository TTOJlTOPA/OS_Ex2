#include <iostream>
#include <fstream>
#include "order.h"
using namespace std;

void printInput(char* pathInput)
{
	ifstream fin(pathInput, ios::binary);
	Order orderCur;
	int num;
	fin.seekg(0, ios::beg);
	fin.read((char*)&num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		fin.read((char*)&orderCur, sizeof(Order));
		printf("%s %d\n\r", "��� ������:", orderCur.n);
		printf("%s %s\n\r", "��� ������:", orderCur.name);
		printf("%s %lf\n\r", "��������� ������:", orderCur.price);
		printf("%s %d\n\r", "���������� �������������� ������:", orderCur.amountSold);
		printf("%s %d\n\r", "���������� ���������������� ������:", orderCur.amountUnsold);
	}
	fin.close();
}