#include <iostream>
#include <sstream>
#include <string.h>

#include "TestSet.h"

TestSet::TestSet()
{
}

TestSet::~TestSet()
{
}

void TestSet::AddError(std::string Message, int nLine){
	nErrorCount++;
	std::stringstream   messageStream;
	messageStream << ErrorMessage << "  L." << nLine << " || " << Message << std::endl;
	ErrorMessage = messageStream.str();
}

void TestSet::AssertInt(int i1, int i2, int nLine){
	if(i1 != i2){
		std::stringstream   messageStream;
		messageStream << "" << i1 << " != " << i2;
		AddError(messageStream.str(), nLine);
	}
}

void TestSet::AssertStr(char* str1, char *str2, int nLine){
	if(strcmp(str1, str2) != 0){
		std::stringstream   messageStream;
		messageStream << "\"" << str1 << "\" != \"" << str2 << "\"";
		AddError(messageStream.str(), nLine);
	}
}

void TestSet::PrintMessage(){
	std::cout << nErrorCount << " :: " << Title << "  ==================================" << std::endl;
	if (0 != nErrorCount){
		std::cout << ErrorMessage << std::endl;
	}
}
