#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

//void sort(queue<int> qList, int* x)
//{
//    int i = 0;
//    int b = 0;
//    int a = qList.size();
//
//    do
//    {
//        b = qList.front();
//        x[b-1]++;
//        qList.pop();
//    } while (!qList.empty());
//
//    for (int i = 0; i < a; i++)
//    {
//        cout << x[i];
//    }
//
//}

int main()
{
    //ifstream input("input.txt");
    //queue<int> qList;
    //int a = 0;
    //int highestNum = 10;
    //do
    //{
    //    input >> a;
    //    qList.push(a);
    //    if (a > highestNum)
    //    {
    //        highestNum = a;
    //    }
    //    //cout << a << endl;
    //} while (!input.eof());

    //cout << qList.size() << endl;
    int* x = new int[10];
    for (size_t i = 0; i < 10; i++)
    {
        x[i] = 0;
    }
    cout << x[0] << "test"<< endl;
    //sort(qList, x);

}