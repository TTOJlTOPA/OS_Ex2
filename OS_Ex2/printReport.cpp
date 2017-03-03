#include <iostream>
#include <fstream>
using namespace std;

void printReport(char* pathReport)
{
	ifstream fin(pathReport);
	char buf[256];
	fin.seekg(0, ios::beg);
	while (!fin.eof()) {
		fin.getline(buf, 256);
		printf("%s\n\r", buf);
	}
	fin.close();
}