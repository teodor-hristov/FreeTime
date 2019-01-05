#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
string toBinary(int n) {

	string r;
	while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	return r;
}

int main()
{
	int num;
	int sum = 0;
	cin >> num;
	string b = toBinary(num);

	for (int j = 1; j <= num; j++) {
		for (int i = 0; i < toBinary(j).length(); i++)
		{
			if (toBinary(j)[i] == '1')
			{
				sum++;
			}

		}
	}
	cout << sum;
}

