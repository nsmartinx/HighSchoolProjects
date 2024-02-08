#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	int count = 0;
	for (int i = 10000; i < 100000; i++)
	{
		count++;
		int num0 = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
		int place1 = i % 10;
		int place2 = (i / 10) % 10;
		int place3 = (i / 100) % 10;
		int place4 = (i / 1000) % 10;
		int place5 = (i / 10000) % 10;
		int place6 = 7;

		int test = place1;
		if (test == 0)
			num0++;
		else if (test == 1)
			num1++;
		else if (test == 2)
			num2++;
		else if (test == 3)
			num3++;
		else if (test == 4)
			num4++;
		else if (test == 5)
			num5++;

		test = place2;
		if (test == 0)
			num0++;
		else if (test == 1)
			num1++;
		else if (test == 2)
			num2++;
		else if (test == 3)
			num3++;
		else if (test == 4)
			num4++;
		else if (test == 5)
			num5++;

		test = place3;
		if (test == 0)
			num0++;
		else if (test == 1)
			num1++;
		else if (test == 2)
			num2++;
		else if (test == 3)
			num3++;
		else if (test == 4)
			num4++;
		else if (test == 5)
			num5++;

		test = place4;
		if (test == 0)
			num0++;
		else if (test == 1)
			num1++;
		else if (test == 2)
			num2++;
		else if (test == 3)
			num3++;
		else if (test == 4)
			num4++;
		else if (test == 5)
			num5++;

		test = place5;
		if (test == 0)
			num0++;
		else if (test == 1)
			num1++;
		else if (test == 2)
			num2++;
		else if (test == 3)
			num3++;
		else if (test == 4)
			num4++;
		else if (test == 5)
			num5++;

		test = place6;
		if (test == 0)
			num0++;
		else if (test == 1)
			num1++;
		else if (test == 2)
			num2++;
		else if (test == 3)
			num3++;
		else if (test == 4)
			num4++;
		else if (test == 5)
			num5++;

		if (num0 < 1 && num1 < 2 && num2 < 3 && num3 < 4 && num4 < 5 && num5 < 6)
			num++;

	}

	cout << num << endl;
	cout << count;
}
