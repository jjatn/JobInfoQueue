#include <windows.h>
#include <stdio.h>
#include <process.h>

// スレッド管理用変数
HANDLE hThread;
unsigned threadID;

// スレッド関数
unsigned __stdcall SecondThreadFunc( void* pArguments )
{
    _endthreadex( 0 );
    return 0;
} 

// スレッド開始
void StartThread(){
    // Create the second thread.
    hThread = (HANDLE)_beginthreadex( NULL, 0, &SecondThreadFunc, NULL, 0, &threadID );
}

// スレッド終了待機
void WaitThread(){
	WaitForSingleObject( hThread, INFINITE );
	CloseHandle( hThread );
	getchar();
}
