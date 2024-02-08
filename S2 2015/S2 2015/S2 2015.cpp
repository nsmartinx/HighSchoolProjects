#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line, size;
    //ifstream inputFile("s2.1.in");
    getline(cin, line);
    int J = stoi(line);
    getline(cin, line);
    int A = stoi(line);
	
    string* jerseys = new string[J];
    for (size_t i = 0; i < J; i++)
    {
        getline(cin, line);
        jerseys[i] = line;
    }
    
    int matches = 0;
    for (size_t i = 0; i < A; i++)
    {
        getline(cin, size, ' ');
        getline(cin, line);
        int number = stoi(line);
        if (jerseys[number - 1] == size || (size == "S" && jerseys[number - 1] != "T") || (jerseys[number - 1] == "L" && size == "M"))
        {
            matches++;
            jerseys[number - 1] = "T";
        }
    }

    cout << matches;
}
