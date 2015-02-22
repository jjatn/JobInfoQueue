#include <stdio.h>
#include <string.h>

#define MAX_JOB 10

typedef struct info {
	int  nType;
	char cPath[30];
} INFO;

static INFO iInfo[MAX_JOB] = { 0 };

static int nHead = 0;
static int nTail = 0;

void JobInfoQueue_Reset()
{
	nHead = nTail = 0;
	for (int i = 0; i < MAX_JOB; i++){
		iInfo[i].nType = 0;
		iInfo[i].cPath[0] = '\0';
	}
}

int JobInfoQueue_Create(int ntype, char* cPath){
	int ret;
	iInfo[nHead].nType = ntype;
	strncpy_s(iInfo[nHead].cPath, 30, cPath, 30);
	ret = nHead;
	nHead++;

	return ret;
}

int JobInfoQueue_Start(int *pnType, char* cPath){
	int ret;
	*pnType = iInfo[nTail].nType;
	strncpy_s(cPath, 30, iInfo[nTail].cPath, 30);
	ret = nTail;
	nTail++;
	return ret;
}

int JobInfoQueue_Drop(int nJobID){
	return 0;
}



void JobInfoQueue_SetPrintStatus();
void JobInfoQueue_GetPrintStatus();
