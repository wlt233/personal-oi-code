#include <iostream>
using namespace std;

bool a[1024][1024];

int main()
{
    int n;
    cin >> n;

    a[0][1] = 1;
    for (int i = 1; i < (1 << n); i++)
        cout << ' ';
    cout << "/\\" << endl;
    for (int l = 1; l < (1 << n); l++)
    {
        for (int j = 1; j < l + 2; j++)
            a[l][j] = a[l - 1][j - 1] ^ a[l - 1][j];
        for (int i = 1; i < ((1 << n) - l); i++)
            cout << ' ';
        if (l % 2 == 1)
            for (int j = 1; j < l + 2; j++)
                if (a[l][j] == 1) 
                {
                    cout << "/__\\";
                    j++;
                }
                else cout << "  ";
        else 
            for (int j = 1; j < l + 2; j++)
                if (a[l][j] == 1) cout << "/\\";
                else cout << "  ";
        cout << endl;
    }
}