#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int n, m;
double posi[3][151]; 
double conn[151][151];
#define maxint 1e12

double rawdis(int a, int b)
{
    return sqrt(pow(posi[0][a] - posi[0][b], 2) + pow(posi[1][a] - posi[1][b], 2));
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> posi[0][i] >> posi[1][i];
    }
    string str;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == '1') conn[i][j + 1] = rawdis(i, j + 1);
            else conn[i][j + 1] = maxint;
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
                if (i != j && i != k && j != k)
                    if (conn[i][k] < maxint - 1 && conn[k][j] < maxint - 1)
                        if (conn[i][j] > conn[i][k] + conn[k][j])
                            conn[i][j] = conn[i][k] + conn[k][j];
    
    //找出每个点能到的最大距离
    double maxdist = 0;
    for (int i = 1; i <= n; i++)
    {
        double maxdis = 0;
        for (int j = 1; j <= n; j++)
            if (conn[i][j] > maxdis && conn[i][j] < maxint - 1) maxdis = conn[i][j];
        if (maxdis > maxdist) maxdist = maxdis;
        posi[2][i] = maxdis;
    }

    double minans = 1e20;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i != j && conn[i][j] > maxint - 1)
            {
                double distemp = posi[2][i] + posi[2][j] + rawdis(i, j);
                //cout << distemp << ' ' << rawdis(i, j) << endl;
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