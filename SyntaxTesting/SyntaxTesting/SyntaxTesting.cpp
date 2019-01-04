#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	stringstream ss;
	string str;
	getline(cin, str);
	replace(str.begin(), str.end(), ',', ' ');
	ss << str;

	int x = 0;
	while (ss >> x)
	{
		cout << x << endl;
	}

}
