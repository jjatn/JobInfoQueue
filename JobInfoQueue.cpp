// JobInfoQueue.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

#include <stdio.h>

void StartThread();
void WaitThread();

int JobInfoQueue_Add(int ntype, char* cPath);
int JobInfoQueue_Pop(int *pnType, char* cPath);
void JobInfoQueue_SetPrintStatus();
void JobInfoQueue_GetPrintStatus();

void ObjectFunction(int nType, char* cPath){
	printf("%d %s\n", nType, cPath);
}

void ThreadFunction(){
	int nJobID;
	int nType;
	char cPath[30];

	nJobID = JobInfoQueue_Pop(&nType, cPath);
	 ObjectFunction(nType, cPath);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nJobID;
	StartThread();

	nJobID = JobInfoQueue_Add(1, "ListPath");

	WaitThread();
	getchar();
	return 0;
}
