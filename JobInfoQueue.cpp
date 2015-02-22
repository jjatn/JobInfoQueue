// JobInfoQueue.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include <stdio.h>

#include "TestCompornent\TestSet.h"

#include "FeatureFunc.h"

int FuncIndex = 0;

extern TestSet test_01_DataAddPop;

static TestSet *ptestFunc[] = {
	&test_01_DataAddPop
};

void ThreadFunction(){
	ptestFunc[FuncIndex]->DoSubFunc();
}

int _tmain(int argc, _TCHAR* argv[])
{

	for(FuncIndex = 0; FuncIndex < sizeof(ptestFunc)/sizeof(ptestFunc[0]); FuncIndex++){
		JobInfoQueue_Reset();
		ptestFunc[FuncIndex]->DoMainFunc();
	}
	for(int i = 0; i < sizeof(ptestFunc)/sizeof(ptestFunc[0]); i++){
		ptestFunc[i]->PrintMessage();
	}

	getchar();
	return 0;
}


