#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sn, sm, sk;
    long long n = 0, m = 0, k = 0;

    getline(cin, sn, ' ');
    getline(cin, sm, ' ');
    getline(cin, sk);
    n = atoll(sn.c_str());
    m = atoll(sm.c_str());
    k = atoll(sk.c_str());

    long long maxk = ((n * (n + 1)) / 2) - (((n - m) * ((n - m) + 1)) / 2);
    long long mink = n;
    bool valid = true;

    if (k < mink || k > maxk)
    {
        cout << -1;
        valid = false;
    }

    if (valid)
    {
        long long* notes = new long long[n];
        long long num = 1;
        for (long long i = 0; i < n; i++)
        {
            notes[i] = num;
            num++;
            if (num > m)
                num = 1;
        }

        long long lessk = maxk - k;
        long long x = n - 1;
        long long x1, x2;

        x1 = notes[x];
        notes[x] = (notes[x] + lessk) % (m);
        long long loopCount = (lessk + x1 - 1) / m;
        if (notes[x] == 0)
            notes[x] = m;
        if (x1 == m)
            loopCount--;
        cout << lessk << " " << loopCount << endl;
        for (long long i = 1; i <= loopCount; i++)
        {
            x1 = notes[x - i];
            notes[x - i] = notes[x];
            
            
        }
        


       


        for (long long i = 0; i < n; i++)
        {
            cout << notes[i] << " ";
        }
        cout << endl;
    }
}