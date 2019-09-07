#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define ll long long


ll n, m, p = 0;
ll task[3][505];


int main()
{
    freopen("exercise.in","r",stdin);
	freopen("exercise.out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        string name;
        cin >> name >> task[0][i] >> task[1][i] >> task[2][i];
    }
    task[0][0] = 0; task[1][0] = 0; task[2][0] = 0;
    task[0][m + 1] = 1441; task[1][m + 1] = 1440; task[2][m + 1] = 0;
    int f = 0;
    p = n;
    for (int i = 1; i <= m + 1; i++)
    {
        if (f == 0)
        {
            p += task[0][i] - task[1][i - 1] - 1;
            if (p - (task[1][i] - task[0][i] + 1) * (task[2][i] - 1) <= 0) 
            {
                f = 1;
                cout << "Runtime Error\n" << task[0][i] + p / (task[2][i] - 1) ;
            }
            else 
            {
                p -= (task[1][i] - task[0][i] + 1) * (task[2][i] - 1);
            }
            //cout << p << endl;
        }
    }
    if (f == 0) cout << "Accepted\n" << p;

   
    fclose(stdin);
    fclose(stdout);


}

