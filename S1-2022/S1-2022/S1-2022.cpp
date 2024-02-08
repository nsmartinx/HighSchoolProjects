

#include <iostream>

using namespace std;

int main()
{
    int input, count = 0;

    cin >> input;

    int max5 = input / 5;
    
    for (int i = max5; i >= 0; i--)
    {
        max5 = i;
        if ((input - (max5 * 5)) % 4 == 0)
        {
            count++;
        }
    }
    cout << count;
}
