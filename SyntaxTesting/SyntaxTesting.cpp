#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	struct testStructure
	{
		int testYears;
		string testName;
		testStructure(int tY, string tN)
		{
			testYears = tY;
			testName = tN;

		}
	};
	testStructure pesho(12, "Teodor");

	cout << pesho.testName << endl;
}
