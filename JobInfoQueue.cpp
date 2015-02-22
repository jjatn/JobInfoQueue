// JobInfoQueue.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include <stdio.h>

void StartThread();
void WaitThread();


int _tmain(int argc, _TCHAR* argv[])
{
	StartThread();
	WaitThread();
	return 0;
}
