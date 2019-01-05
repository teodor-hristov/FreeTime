
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a > b)
	{
		swap(a, b);
	}
	if (c > d)
	{
		swap(c, d);
	}

	if (a < c) {
		if ((b - c) < 0)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << (b - c);
		}
	}
	else
	{
		if ((d - a) < 0)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << (d - a);
		}
	}
}

