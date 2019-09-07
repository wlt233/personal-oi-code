#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define ll long long


ll a, b;
ll pa = 0, pb = 0, m = 0x7fffffff;

ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b); }
ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }

int main()
{
    //freopen("exercise.in","r",stdin);
	//freopen("exercise.out","w",stdout);

    cin >> a >> b;
    
    if (a - 1 == b)
    {
        pa = b - 1; pb = b; m = 1;
    }
    else if (a != b)
    {
        ll t = lcm(a, b) / b;
        for (int i = 1; i < t; i++)
        {
            ll l = b * i;
            if ((l % a) < m)
            {
                m = l % a;
                pa = l / a;
                pb = i;
                
            }
        }
    }
    else
    {
        pa = 0; pb = 1; m = a;
    }
    

    
    cout << m << endl << pa << ' ' << pb;
    //fclose(stdin);
    //fclose(stdout);


}

