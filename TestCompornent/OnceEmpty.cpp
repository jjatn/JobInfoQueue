#include <windows.h>

#include "../TestCompornent/TestSet.h"

#include "../FeatureFunc.h"

static void Test_OnceEmptyMain();
static void Test_OnceEmptySub();

#define TESTSET test_02_OnceEmpty
JOIN_TEST(test_02_OnceEmpty, Test_OnceEmptyMain, Test_OnceEmptySub);

bool GoFlag = false;

static void Test_OnceEmptyMain(){
	int nJobID;
	nJobID = JobInfoQueue_Create(1,  STR_1);
	ASSERT_INT(0, nJobID);
	nJobID = JobInfoQueue_Create(4,  STR_2);
	ASSERT_INT(1, nJobID);

	StartThread();

	while(! GoFlag) Sleep(10);

	nJobID = JobInfoQueue_Create(5,  STR_3);
	ASSERT_INT(0, nJobID);
	nJobID = JobInfoQueue_Create(10, STR_4);
	ASSERT_INT(1, nJobID);

	WaitThread();
}

static void Test_OnceEmptySub()
{
	INFO *pInfo;
	int nType;
	char cPath[30];

	pInfo = JobInfoQueue_Start(&nType, cPath);
	ASSERT_INT(1, nType);
	ASSERT_STR(STR_1, cPath);

	pInfo = JobInfoQueue_Start(&nType, cPath);
	ASSERT_INT(4, nType);
	ASSERT_STR(STR_2, cPath);

	GoFlag = true;

	pInfo = JobInfoQueue_Start(&nType, cPath);
	ASSERT_INT(5, nType);
	ASSERT_STR(STR_3, cPath);

	pInfo = JobInfoQueue_Start(&nType, cPath);
	ASSERT_INT(10, nType);
	ASSERT_STR(STR_4, cPath);
}

