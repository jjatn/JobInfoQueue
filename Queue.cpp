#include <stdio.h>
#include <string.h>

#define MAX_JOB 10

typedef struct info {
	int  nType;
	char cPath[30];
} INFO;

static INFO iInfo;

int JobInfoQueue_Add(int ntype, char* cPath){
	iInfo.nType = ntype;
	strncpy_s(iInfo.cPath, 30, cPath, 30);
	return 0;
}

int JobInfoQueue_Pop(int *pnType, char* cPath){
	*pnType = iInfo.nType;
	strncpy_s(cPath, 30, iInfo.cPath, 30);
	return 0;
}
void JobInfoQueue_SetPrintStatus();
void JobInfoQueue_GetPrintStatus();
