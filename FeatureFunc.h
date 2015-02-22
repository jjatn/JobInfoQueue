typedef struct info INFO;

void StartThread();
void WaitThread();

void JobInfoQueue_Reset();
int JobInfoQueue_Create(int ntype, char* cPath);
INFO *JobInfoQueue_Start(int *pnType, char* cPath);
void JobInfoQueue_SetPrintStatus();
void JobInfoQueue_GetPrintStatus();

#define STR_1	"FirstPath"
#define STR_2	"SecondPath"
#define STR_3	"ThirdPath"
#define STR_4	"ForthPath"

