#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sn, sm, sk;
    long n = 0, m = 0, k = 0;

    getline(cin, sn, ' ');
    getline(cin, sm, ' ');
    getline(cin, sk);
    n = atol(sn.c_str());
    m = atol(sm.c_str());
    k = atol(sk.c_str());
    
    bool valid = true;
    long long maxk = 0;
    for (long i = 1; i <= n; i++)
    {
        maxk += i;  
    }
    if (k > maxk || k < n)
    {
        cout << -1;
        valid = false;
    }

    if (valid)
    {
        long* notes = new long[n];
        long num = 1;
        for (long i = 0; i < n; i++)
        {
            notes[i] = num;
            num++;
            if (num > m)
                num = 1;
        }
        
        long long lessk = maxk - k;
        long num1 = 1;
        while (lessk > 0)
        {
            if (n - lessk <= num1)
            {
                notes[num1] = 1;
                num1++;
                lessk -= n - (num1 - 1);
            }
            else
            {
                notes[n - lessk] = 1;
                lessk = 0;
            }
        }


        for (long i = 0; i < n; i++)
        {
            cout << notes[i] << " ";
        }
    }
    
    cout << endl;
}
