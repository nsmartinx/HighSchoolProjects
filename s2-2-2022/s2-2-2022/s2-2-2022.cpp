
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Person
{
	string gname1, gname2;
	vector<string> with;
	vector<string> notWith;
};


int main()
{
	string sx, sy, sg, name1, name2, name3;
	int x, y, g;
	map<string, Person> people;
	vector<string> names;

	getline(cin, sx);
	x = stoi(sx);

	for (size_t i = 0; i < x; i++)
	{
		getline(cin, name1, ' ');
		getline(cin, name2);
		people[name1].with.push_back(name2);
	}

	getline(cin, sy);
	y = stoi(sy);

	for (size_t i = 0; i < y; i++)
	{
		getline(cin, name1, ' ');
		getline(cin, name2);
		people[name1].notWith.push_back(name2);
	}

	getline(cin, sg);
	g = stoi(sg);

	for (size_t i = 0; i < g; i++)
	{
		getline(cin, name1, ' ');
		getline(cin, name2, ' ');
		getline(cin, name3);
		people[name1].gname1 = name2;
		people[name1].gname2 = name3;

		people[name2].gname1 = name1;
		people[name2].gname2 = name3;

		people[name3].gname1 = name2;
		people[name3].gname2 = name1;

		names.push_back(name1);
		names.push_back(name2);
		names.push_back(name3);
	}
	
	//READING IN DONE

	int violated = 0;

	for (string name : names)
	{
		for (string with : people[name].with)
		{
			if (with != people[name].gname1 && with != people[name].gname2)
				violated++;
		}
		for (string notWith : people[name].notWith)
		{
			if (notWith == people[name].gname1 || notWith == people[name].gname2)
				violated++;
		}
	}

	cout << violated;
}