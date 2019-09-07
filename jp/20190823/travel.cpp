#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;
#define ll long long
#define INF 0x7f

int m, n;
int line[105][505];
int go[1005][1005]; //go[from][to]
int dij[3][1005]; // dij[0][blue or white]  dij[1][mindis]  dij[2][from]
int exist[505][100];

void read(int i)
{
    char c;
    int num = 0, station = 0;
    while ((c = getchar()) != '\n')
    {
        if (c != ' ') 
        {
            num = num * 10 + c - '0';
            line[i][station + 1] = num;
        }
        else
        {
            station++;
            line[i][station] = num;
            num = 0;
        }
        line[i][0] = station + 1;
    }
}



int main()
{
    //freopen("shirt.in","r",stdin);
	//freopen("shirt.out","w",stdout);
    memset(go, INF, sizeof(go));
    cin >> m >> n;
    int real_n = n;
    getchar();
    for (int i = 1; i <= m; i++)
    {
        read(i);
        for (int j = 1; j <= line[i][0]; j++)
        {
            if (exist[line[i][j]][0])
            {
                real_n++;
                //cout << "create " << real_n << endl;
                exist[line[i][j]][0]++;
                exist[line[i][j]][exist[line[i][j]][0]] = real_n;
                for (int p = 1; p < exist[line[i][j]][0]; p++)
                {
                    int sta_t = exist[line[i][j]][p];
                    go[sta_t][real_n] = 1;
                    go[real_n][sta_t] = 1;
                }
                line[i][j] = real_n;
            }
            else
            {
                exist[line[i][j]][0] = 1;
                exist[line[i][j]][1] = line[i][j];
            }
            if (j != 1)
                go[line[i][j - 1]][line[i][j]] = 0;
        }
        //for (int p = 0; p <= 10; p++) cout << line[i][p] << ' ';
        //cout << endl;
    }

    //dijkstra
    memset(dij[1], INF, sizeof(dij[1]));
    dij[1][1] = 0;
    for (int i = 1; i <= real_n; i++)
    {
        int min_dis = INF, min_dis_p; 
        for (int j = 1; j <= real_n; j++)
        {
            if (!dij[0][j] && dij[1][j] < min_dis)
            {
                min_dis = dij[1][j];
                min_dis_p = j;
            }
        }
        //cout << "t " << min_dis << ' ' << min_dis_p << endl;
        dij[0][min_dis_p] = 1;
        for (int j = 1; j <= real_n; j++)
        {
            if (!dij[0][j] && min_dis + go[min_dis_p][j] < dij[1][j])
            {
                dij[1][j] = min_dis + go[min_dis_p][j];
                dij[2][j] = min_dis_p;
            }
        }
    }
    if (dij[1][n] < INF)
        cout << dij[1][n] << endl;
    else 
        cout << "NO";


    /*
    int now = n;
    for (int i = 20; i>=0; i--)
    {
        cout << now <<  ' ';
        now = dij[2][now];
    }
    */
    
    /*
    for (int j = 1; j <= n; j++)
    {
        for (int k = 1; k <= n; k++) cout << go[j][k] << ' ';
        cout << endl;
    }
    */
    //fclose(stdin);
    //fclose(stdout);


}

/*
3 7
6 7
4 7 3 6
2 1 3 5 


*/