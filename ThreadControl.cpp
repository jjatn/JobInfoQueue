#include <windows.h>
#include <stdio.h>
#include <process.h>

// �X���b�h�Ǘ��p�ϐ�
HANDLE hThread;
unsigned threadID;

// �X���b�h�֐�
unsigned __stdcall SecondThreadFunc( void* pArguments )
{
    _endthreadex( 0 );
    return 0;
} 

// �X���b�h�J�n
void StartThread(){
    // Create the second thread.
    hThread = (HANDLE)_beginthreadex( NULL, 0, &SecondThreadFunc, NULL, 0, &threadID );
}

// �X���b�h�I���ҋ@
void WaitThread(){
	WaitForSingleObject( hThread, INFINITE );
	CloseHandle( hThread );
	getchar();
}
