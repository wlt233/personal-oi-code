#include<iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int m = 1 + k, f = 0;
    while (f == 0)
    {   
        //cout<<m<<endl;
        int p = 1, j = 1, f2 = 0;
        while (f2 == 0)
        {
            int rm = m % (2 * k + 1 - j);
            p = (p + rm - 1) % (2 * k + 1 - j);
            if (p == 0)
                p = (2 * k + 1 - j);
            //cout<<"p="<<p<<endl;
            if (p <= k)
            {
                f2 = 0;
                break;
            }
            j++;
        }
        if (j == k + 1) f = 1;
        m++;
    }
    cout << m - 1;
}