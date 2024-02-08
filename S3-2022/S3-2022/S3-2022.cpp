
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sn, sm, sk;
	int n, m, k;
	getline(cin, sn, ' ');
	getline(cin, sm, ' ');
	getline(cin, sk);
	n = atoi(sn.c_str());
	m = atoi(sm.c_str());
	k = atoi(sk.c_str());

	if (k < n || k > (2 * n) - 1)
	{
		cout << -1;
	}
	else
	{
		k -= n;
		bool even;
		if (k % 2 == 0)
		{
			even = true;
		}
		else
		{
			even = false;
		}
		if (even)
		{
			cout << "1" << " ";
			for (size_t i = 0; i < n - 1; i++)
			{
				if (k > 0 && k % 2 == 0)
					cout << "2" << " ";
				else
					cout << "1" << " ";
				k--;
			}
		}
		else
		{
			for (size_t i = 0; i < n; i++)
			{
				if (k > 0 && k % 2 == 1)
					cout << "2" << " ";
				else
					cout << "1" << " ";
				k--;
			}
		}
		cout << endl;
	}
}
