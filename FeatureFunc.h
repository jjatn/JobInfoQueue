
void StartThread();
void WaitThread();

void JobInfoQueue_Reset();
int JobInfoQueue_Create(int ntype, char* cPath);
int JobInfoQueue_Start(int *pnType, char* cPath);
void JobInfoQueue_SetPrintStatus();
void JobInfoQueue_GetPrintStatus();
