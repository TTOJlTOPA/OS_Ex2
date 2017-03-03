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
		printf("%s %d\n\r", "Код товара:", orderCur.n);
		printf("%s %s\n\r", "Имя товара:", orderCur.name);
		printf("%s %lf\n\r", "Стоимость товара:", orderCur.price);
		printf("%s %d\n\r", "Количество реализованного товара:", orderCur.amountSold);
		printf("%s %d\n\r", "Количество нереализованного товара:", orderCur.amountUnsold);
	}
	fin.close();
}