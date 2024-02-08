#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string input;
    ifstream inputFile("s5.6.in");
    int N, M;

    getline(inputFile, input);
    N = stoi(input);

    int* firstList = new int[N];
    for (size_t i = 0; i < N; i++)
    {
        getline(inputFile, input);
        firstList[i] = stoi(input);
    }

    getline(inputFile, input);
    M = stoi(input);

    vector<int> secondList;
    for (size_t i = 0; i < M; i++)
    {
        getline(inputFile, input);
        secondList.push_back(stoi(input));
    }
    //above lines take input


}

