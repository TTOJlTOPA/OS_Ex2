#include <iostream>
#include <fstream>
#include <Windows.h>
#include "order.h"
using namespace std;

int main(int args, char* argv[])
{
	setlocale(LC_ALL, "rus");

	Order orderCur;
	int num = 0;
	ofstream fout(argv[1], ios::binary);

	printf("%s", "������� ���������� �������: ");
	scanf("%d", &num);
	fout.write((char*)&num, sizeof(int));
	for (int i = 0; i < num; i++) {
		printf("%s", "������� ��� ������: ");
		scanf("%d", &(orderCur.n));
		printf("%s", "������� ��� ������(�� ����� 10 ��������): ");
		scanf("%s", orderCur.name);
		printf("%s", "������� ���������: ");
		scanf("%lf", &(orderCur.price));
		printf("%s", "������� ���������� �������������� ������: ");
		scanf("%d", &(orderCur.amountSold));
		printf("%s", "������� ���������� ���������������� ������: ");
		scanf("%d", &(orderCur.amountUnsold));
		fout.write((char*)&orderCur, sizeof(Order));
	}

	fout.close();
	
	return 1;
}