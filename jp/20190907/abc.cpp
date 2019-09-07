#include <iostream>

using namespace std;

#define ll long long

int check(ll a, ll b) 
{
    if (a * a - a * b - b * b == 1 || a * a - a * b - b * b == -1) return 1;
    else return 0;
}





int main()
{
    ll k;
    cin >> k;
    int i = k, f = 0;
    while(i > 0 && f == 0)
    {
        int j = i - 1;
        while(j > 0 && f == 0)
        {
            if (check(i, j))
            {
                cout << i << endl << j;
                f = 1;
            }
            j--;
        }
        i--;
    }
            
}


/*

6 8



*/