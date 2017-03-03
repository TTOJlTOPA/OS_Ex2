#ifndef ORDER_H
#define ORDER_H

struct Order
{
	int n;
	char name[10];
	double price;
	int amountSold;
	int amountUnsold;
};

#endif