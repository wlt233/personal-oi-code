#include <iostream>
using namespace std;

bool p[100000];

int main()
{
    int n, m;
    cin >> n >> m;
    for (; m > 0; m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            for (int i = a; i <= b; i++) p[i] = !p[i];
        }
        else
        {
            int a;
            cin >> a;
            cout << (int)p[a] << endl;
        }
        
    }
}
