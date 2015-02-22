// JobInfoQueue.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include <stdio.h>

void StartThread();
void WaitThread();

int JobInfoQueue_Add(int ntype, char* cPath);
int JobInfoQueue_Pop();
void JobInfoQueue_SetPrintStatus();
void JobInfoQueue_GetPrintStatus();

void ThreadFunction(){
	int nJobID;
//	nJobID = JobInfoQueue_Pop();
}

void ObjectFunction(int nType, char* cPath){
	printf("%d %s\n", nType, cPath);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nJobID;
	StartThread();

	ObjectFunction(1, "ListPath");

	WaitThread();
	getchar();
	return 0;
}
