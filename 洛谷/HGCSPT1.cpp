#include <iostream>
using namespace std;

int n; 
int s = 0;

int main()
{
    cin >> n;
    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        s += t;
    }
    if (s == n * n) cout << "YES";
    else cout << "NO";
}