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

	printf("%s", "¬ведите количество записей: ");
	scanf("%d", &num);
	fout.write((char*)&num, sizeof(int));
	for (int i = 0; i < num; i++) {
		printf("%s", "¬ведите код товара: ");
		scanf("%d", &(orderCur.n));
		printf("%s", "¬ведите им€ товара(не более 10 символов): ");
		scanf("%s", orderCur.name);
		printf("%s", "¬ведите стоимость: ");
		scanf("%lf", &(orderCur.price));
		printf("%s", "¬ведите количество реализованного товара: ");
		scanf("%d", &(orderCur.amountSold));
		printf("%s", "¬ведите количество нереализованного товара: ");
		scanf("%d", &(orderCur.amountUnsold));
		fout.write((char*)&orderCur, sizeof(Order));
	}

	fout.close();
	
	return 1;
}