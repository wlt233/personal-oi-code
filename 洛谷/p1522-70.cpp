#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int n, m;
//其实这里完全可以用数组的，我只是想练习一下vector...
vector<double> posi[3]; 
//0,1分别为x,y坐标 2为该点能到的最远距离
vector< vector<double> > conn(n + 1);


double rawdis(int a, int b)
{
    return sqrt(pow(posi[0][a] - posi[0][b], 2) + pow(posi[1][a] - posi[1][b], 2));
}

double dis(int a, int b)
{
    if (conn[a][b] == 1)
    {
        double dist = rawdis(a, b);
        conn[a][b] = dist;
        return dist;
    }
    else if (conn[a][b] != 0) return conn[a][b];
    else return 0x42;
}


int main()
{
    cin >> n;
    posi[0].push_back(0);posi[1].push_back(0);posi[2].push_back(0);
    conn.resize(n + 1);
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        posi[0].push_back(x);posi[1].push_back(y);
    }
    string str;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        conn[i].push_back(0);
        for (int j = 0; j < n; j++)
        {
            conn[i].push_back(str[j] - '0');
        } 
    }

    //并没有用的初始化
    //for (int i = 1; i <= n; i++)
    //    for (int j = 1; j <= n; j++)
    //       dis(i, j);

    //floyed
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (dis(i, j) > dis(i, k) + dis(k, j) && i != j)
                    conn[i][j] = dis(i, k) + dis(k, j);
            }
    
    //找出每个点能到的最大距离
    double maxdist = 0;
    for (int i = 1; i <= n; i++)
    {
        double maxdis = 0;
        for (int j = 1; j <= n; j++)
            if (conn[i][j] > maxdis) maxdis = conn[i][j];
        if (maxdis > maxdist) maxdist = maxdis;
        posi[2].push_back(maxdis);
    }

    double minans = 1e20;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i != j && conn[i][j] == 0)
            {
                double distemp = posi[2][i] + posi[2][j] + rawdis(i, j);
                cout << distemp << ' ' << rawdis(i, j) << endl;
                if (distemp < minans) minans = distemp;
            }
        }
    if (maxdist > minans) minans = maxdist;
    cout << fixed << setprecision(6) << minans << endl;
        
    //调试数据用
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
               cout<<conn[i][j]<<' ';
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << posi[2][i] << endl;
    }
    */
}