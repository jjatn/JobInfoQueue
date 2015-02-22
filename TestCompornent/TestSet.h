#include <string>

class TestSet
{
private:
	void AddError(std::string Message, int nLine);

public:
	TestSet(std::string aTitle, void (*aMainFunc)(void), void (*aSubFunc)(void)) :
		Title(aTitle)
		, nErrorCount(0)
		, MainFunc(aMainFunc)
		, SubFunc(aSubFunc)
		, ErrorMessage("")
	{};
	~TestSet();

	void AssertInt(int i1, int i2, int nLine);
	void AssertStr(char* str1, char *str2, int nLine);

	inline void DoMainFunc() {MainFunc();};
	inline void DoSubFunc()  {SubFunc();};

	void PrintMessage();

private:
	TestSet();

	std::string Title;
	void (*MainFunc)(void);
	void (*SubFunc)(void);

	std::string ErrorMessage;
	int nErrorCount;
};

#define ASSERT_INT(INT1, INT2) TESTSET.AssertInt(INT1, INT2, __LINE__);
#define ASSERT_STR(STR1, STR2) TESTSET.AssertStr(STR1, STR2, __LINE__);
