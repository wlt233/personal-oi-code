#include <iostream>
using namespace std;

short a[2048][2048];
//0  1/ 2\ 3_ 

short pro(int x, int y)
{
    if (a[x - 1][y - 1] == 0 && a[x - 1][y + 1] == 1) return 1;
    if (a[x - 1][y - 1] == 0 && a[x - 1][y + 1] == 2) return 3;
    if (a[x - 1][y - 1] == 1 && a[x - 1][y + 1] == 0) return 3;
    if (a[x - 1][y - 1] == 2 && a[x - 1][y + 1] == 0) return 2;
    if (a[x - 1][y - 1] == 0 && a[x - 1][y + 1] == 3) return 2;
    if (a[x - 1][y - 1] == 1 && a[x - 1][y + 1] == 3) return 0;
    if (a[x - 1][y - 1] == 3 && a[x - 1][y + 1] == 2) return 0;
    if (a[x - 1][y - 1] == 3 && a[x - 1][y + 1] == 0) return 1; 
    if (a[x - 1][y - 1] == 3 && a[x - 1][y + 1] == 1) return 0;
    if (a[x - 1][y - 1] == 2 && a[x - 1][y + 1] == 3) return 0;
}

void out(int x)
{
    if (x == 1) cout << '/';
    else if (x == 2) cout << '\\';
    else if (x == 3) cout << '_';
    else cout << ' ';
}

int main()
{
    int n;
    cin >> n;

    a[0][1 << n] = 1; a[0][(1 << n) + 1] = 2;
    for (int i = 1; i < (1 << n); i++)
        for (int j = 0; j <= (1 << (n + 1)); j++)
            a[i][j] = pro(i, j);
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 1; j <= (1 << (n + 1)); j++)
            out(a[i][j]);
        cout << endl;
    }
}