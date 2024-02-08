#include <iostream>
#include <string>
#include <vector>

using namespace std;



bool isPrime(int n)
{
    if (n == 1) 
    {
        return false;
    }

    int i = 2;
    while (i * i <= n) 
    {
        if (n % i == 0) 
        {
            return false;
        }
        i += 1;
    }
    return true;
}

int main()
{
    cout << "yes";
    string input;
    int num, T;
    getline(cin, input);
    T = stoi(input);

    for (size_t n = 0; n < T; n++)
    {
        getline(cin, input);
        num = stoi(input);
        for (size_t i = 2; i < num; i++)
        {
            if (isPrime(i) && isPrime(2 * num - i))
            {
                cout << i << " " << 2 * num - i << endl;
                break;
            }
        }
    }
}