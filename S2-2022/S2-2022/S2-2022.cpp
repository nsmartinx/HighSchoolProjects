
#include <iostream>
#include <string>

using namespace std;

struct Pair
{
	string name1, name2;
};

struct Group
{
	string name1, name2, name3;
};

int main()
{
	string sx, sy, sg, name1, name2, name3, gname1, gname2, gname3;
	int x, y, g, violated = 0;

	getline(cin, sx);
	x = stoi(sx);

	Pair* allowedPairs = new Pair[x];

	for (size_t i = 0; i < x; i++)
	{
		getline(cin, name1, ' ');
		getline(cin, name2);
		allowedPairs[i].name1 = name1;
		allowedPairs[i].name2 = name2;
	}

	getline(cin, sy);
	y = stoi(sy);

	Pair* notAllowedPairs = new Pair[y];

	for (size_t i = 0; i < y; i++)
	{
		getline(cin, name1, ' ');
		getline(cin, name2);
		notAllowedPairs[i].name1 = name1;
		notAllowedPairs[i].name2 = name2;
	}
	
	getline(cin, sg);
	g = stoi(sg);

	Group* groups = new Group[g];

	for (size_t i = 0; i < g; i++)
	{
		getline(cin, name1, ' ');
		getline(cin, name2, ' ');
		getline(cin, name3);
		groups[i].name1 = name1;
		groups[i].name2 = name2;
		groups[i].name3 = name3;
	}

	//READING IN DONE

	for (size_t i = 0; i < x; i++)
	{
		name1 = allowedPairs[i].name1;
		name2 = allowedPairs[i].name2;
		bool together = false;

		for (size_t p = 0; p < g; p++)
		{
			gname1 = groups[p].name1;
			gname2 = groups[p].name2;
			gname3 = groups[p].name3;

			if ((name1 == gname1 && name2 == gname2) || (name1 == gname2 && name2 == gname3) || (name1 == gname1 && name2 == gname3) || (name2 == gname1 && name1 == gname2) || (name2 == gname2 && name1 == gname3) || (name2 == gname1 && name1 == gname3))
			{
				together = true;
				break;
			}
		}
		if (!together)
			violated++;
	}

	for (size_t i = 0; i < y; i++)
	{
		name1 = notAllowedPairs[i].name1;
		name2 = notAllowedPairs[i].name2;

		for (size_t p = 0; p < g; p++)
		{
			gname1 = groups[p].name1;
			gname2 = groups[p].name2;
			gname3 = groups[p].name3;

			if ((name1 == gname1 && name2 == gname2) || (name1 == gname2 && name2 == gname3) || (name1 == gname1 && name2 == gname3) || (name2 == gname1 && name1 == gname2) || (name2 == gname2 && name1 == gname3) || (name2 == gname1 && name1 == gname3))
			{
				violated++;
				break;
			}
		}
	}

	cout << violated;
}