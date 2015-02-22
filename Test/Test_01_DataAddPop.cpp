#include "../TestCompornent/TestSet.h"

#include "../FeatureFunc.h"

static void Test_DataPassMain();
static void Test_DataPassSub();

TestSet	test_01_DataAddPop("test_01_DataAddPop", Test_DataPassMain, Test_DataPassSub);

#define TESTSET test_01_DataAddPop

static void Test_DataPassMain()
{
	int nJobID;
	nJobID = JobInfoQueue_Create(1,  STR_1);
	ASSERT_INT(0, nJobID);
	nJobID = JobInfoQueue_Create(4,  STR_2);
	ASSERT_INT(1, nJobID);
	nJobID = JobInfoQueue_Create(5,  STR_3);
	ASSERT_INT(2, nJobID);
	nJobID = JobInfoQueue_Create(10, STR_4);
	ASSERT_INT(3, nJobID);

	StartThread();

	WaitThread();
}

static void Test_DataPassSub()
{
	int nJobID;
	int nType;
	char cPath[30];

	nJobID = JobInfoQueue_Start(&nType, cPath);
	ASSERT_INT(0, nJobID);
	ASSERT_INT(1, nType);
	ASSERT_STR(STR_1, cPath);

	nJobID = JobInfoQueue_Start(&nType, cPath);
	ASSERT_INT(1, nJobID);
	ASSERT_INT(4, nType);
	ASSERT_STR(STR_2, cPath);

	nJobID = JobInfoQueue_Start(&nType, cPath);
	ASSERT_INT(2, nJobID);
	ASSERT_INT(5, nType);
	ASSERT_STR(STR_3, cPath);

	nJobID = JobInfoQueue_Start(&nType, cPath);
	ASSERT_INT(3, nJobID);
	ASSERT_INT(10, nType);
	ASSERT_STR(STR_4, cPath);
}
