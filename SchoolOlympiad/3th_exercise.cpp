
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	string output = "";
	string currentEgn = "";
	getline(cin,input);
	for (int i = 8; i < input.length(); i+=10)
	{
		if (input[i] == '0' || input[i] == '2' || input[i] == '4' || input[i] == '6' || input[i] == '8') {
			for (int j = 0; j < 10; j++)
			{
				output += input[j+i-8];
			}
			output += "\n";
		}

	}
	cout << output << endl;
	
}

