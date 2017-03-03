#include <iostream>
#include <Windows.h>
using namespace std;

void printInput(char* pathInput);
void printReport(char* pathReport);

int main()
{
	setlocale(LC_ALL, "rus");

	char pathCreator[] = "D:\\VS Projects\\Projects\\OS_Ex2\\Debug\\Creator.exe";
	char pathReporter[] = "D:\\VS Projects\\Projects\\OS_Ex2\\Debug\\Reporter.exe";
	char* lpszCommandLine = new char[1000];
	char* pathInput = new char[260];
	char* pathReport = new char[260];
	int reportCode;
	STARTUPINFO siCreator;
	STARTUPINFO siReporter;
	PROCESS_INFORMATION procInfoCreator;
	PROCESS_INFORMATION procInfoReporter;

	printf("%s", "¬ведите путь к входному файлу: ");
	gets(pathInput);
	sprintf(lpszCommandLine, "\"%s\" \"%s\"", pathCreator, pathInput);

	ZeroMemory(&siCreator, sizeof(STARTUPINFO));
	siCreator.cb = sizeof(STARTUPINFO);
	CreateProcess(NULL, lpszCommandLine, NULL, NULL, FALSE, NULL, NULL, NULL, &siCreator, &procInfoCreator);
	WaitForSingleObject(procInfoCreator.hProcess, INFINITE);
	CloseHandle(procInfoCreator.hThread);
	CloseHandle(procInfoCreator.hProcess);

	printInput(pathInput);

	printf("%s", "¬ведите путь к файлу отчЄта: ");
	gets(pathReport);
	printf("%s", "¬ведите код отчЄта: ");
	scanf("%d", &reportCode);
	sprintf(lpszCommandLine, "\"%s\" \"%s\" \"%s\" %d", pathReporter, pathInput, pathReport, reportCode);

	ZeroMemory(&siReporter, sizeof(STARTUPINFO));
	siReporter.cb = sizeof(STARTUPINFO);
	CreateProcess(NULL, lpszCommandLine, NULL, NULL, FALSE, NULL, NULL, NULL, &siReporter, &procInfoReporter);
	WaitForSingleObject(procInfoReporter.hProcess, INFINITE);
	CloseHandle(procInfoReporter.hThread);
	CloseHandle(procInfoReporter.hProcess);

	printReport(pathReport);

	return 1;
}