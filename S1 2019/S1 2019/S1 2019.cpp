#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	getline(cin, input);
	int a = 1, b = 2, c = 3, d = 4, e;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == 'H')
		{
			e = a;
			a = c;
			c = e;
			e = b;
			b = d;
			d = e;
		}
		else if (input[i] == 'V')
		{
			e = a;
			a = b;
			b = e;
			e = c;
			c = d;
			d = e;
		}
	}
	cout << a << " " << b << "\n" << c << " " << d;
}