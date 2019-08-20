#include <iostream>
#include <algorithm>
using namespace std;

int a[1001][1001], b[1001][1001], n;

int main()
{
    cin >> n; 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j <= i + 1; j++)
            b[i][j] = max(b[i + 1][j] + a[i + 1][j], b[i + 1][j + 1] + a[i + 1][j + 1]);
    cout << b[0][1] << endl;
}