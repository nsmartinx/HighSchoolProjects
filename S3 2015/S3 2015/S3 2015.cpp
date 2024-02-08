#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //ifstream inputFile("s3.8.in");
    string input;
    int G, P, dockedPlanes = 0;
    getline(cin, input);
    G = stoi(input);
    getline(cin, input);
    P = stoi(input);

    bool* gatesTaken = new bool[G];
    for (size_t i = 0; i < G; i++)
    {
        gatesTaken[i] = false;
    }

    for (size_t i = 0; i < P; i++)
    {
        getline(cin, input);
        int gate = stoi(input);
        bool repeat = true, stop = false;
        while (repeat)
        {
            if (!gatesTaken[gate - 1])
            {
                dockedPlanes++;
                gatesTaken[gate - 1] = true;
                repeat = false;
            }
            else
            {
                gate--;
            }
            if (gate == -1)
            {
                repeat = false;
                stop = true;
            }
        }
        if (stop)
            break;
    }
    cout << dockedPlanes << endl;
}