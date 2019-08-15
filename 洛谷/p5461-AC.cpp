#include <iostream>
using namespace std;

bool a[1025][1025];

int main()
{
    int n;
    cin >> n;

    a[0][1 << n] = 1;
    for (int i = 1; i <= (1 << n); i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            if (a[i - 1][j] != a[i - 1][j + 1])
                a[i][j] = 1;
            cout << (int)a[i][j] << ' ';
        }
        cout << endl;
    }
}