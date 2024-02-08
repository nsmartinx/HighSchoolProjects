#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string input;
    int count, total = 0;
    stack<int> sequence;
    //ifstream inputFile("s1.5.in");
    getline(cin, input);
    count = stoi(input);

    for (size_t i = 0; i < count; i++)
    {
        getline(cin, input);
        if (input != "0")
            sequence.push(stoi(input));
        else
            sequence.pop();
    }

    count = sequence.size();
    for (size_t i = 0; i < count; i++)
    {
        total += sequence.top();
        sequence.pop();
    }

    cout << total;
}