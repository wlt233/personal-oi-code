#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;
#define ll long long
#define INF 0x7f

int n;
int t[101][101];
int k[27];
int e[27];

/*
check1:
\ 1 2 3
1 A
2 A A 
3 A A A 
4 A A
5 A
start_i = 3; start_j = 1; l = 3;
p = -1: up / 1: down 
*/
int check1(int start_i, int start_j, int l, int p)
{
    int c = t[start_i][start_j];
    for (int i = 1; i < l; i++)
    {
        int line = start_i + i * p;
        if (line <= 0 || line > n) return 0;
        for (int j = 0; j < l - i; j++)
        {
            int row = start_j + j; 
            if (t[line][row] != c) return 0;
        }
    }
    return 1;
}

/*
check2:
\ 1 2 3
1     A
2   A A
3 A A A 
4   A A
5     A
start_i = 3; start_j = 1; l = 3;
p = -1: up / 1: down 
*/
int check2(int start_i, int start_j, int l, int p)
{
    int c = t[start_i][start_j];
    for (int i = 1; i < l; i++)
    {
        int line = start_i + i * p;
        if (line <= 0 || line > n) return 0;
        for (int j = 0; j < l - i; j++)
        {
            int row = start_j + l - 1 - j; 
            if (t[line][row] != c) return 0;
        }
    }
    return 1;
}






int main()
{
    freopen("TRIANGL7.in","r",stdin);
	freopen("TRIANGL.STD","w",stdout);
    cin >> n;
    getchar();
    char c;
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while ((c = getchar()) != '\n')
        {
            t[i][j] = c - 'A' + 1;
            e[c - 'A' + 1] = 1;
            j++;
        }
        
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int samec = 1, p = j, c = t[i][j];
            while ((p + 1) <= n && t[i][p + 1] == c)
            {
                samec++;
                p++;
                if (check1(i, j, samec, 1)) k[c]++;
                if (check1(i, j, samec, -1)) k[c]++;
                if (check2(i, j, samec, 1)) k[c]++;
                if (check2(i, j, samec, -1)) k[c]++;
                
                if (check1(i, j, samec, 1)) 
                    if (check1(i, j, samec, -1)) k[c]++;
                if (check2(i, j, samec, 1))
                    if (check2(i, j, samec, -1)) k[c]++;
                //cout << i <<' ' <<"samec = " << samec << ' ' << p  << ' ' << c <<endl;
                if (samec % 2 == 1)
                {
                    //cout << "samec = " << samec <<endl;
                    int half = (samec + 1) / 2;
                    if (check2(i, j, half, 1) && check1(i, j + half - 1, half, 1)) k[c]++;
                    if (check2(i, j, half, -1) && check1(i, j + half - 1, half, -1)) k[c]++;
                }
    
            }
        }
    }









    int ans = 0;

    for (int i = 1; i <= 26; i++) ans += k[i];

    cout << ans << endl;
    for (int i = 1; i <= 26; i++)
        if (e[i] == 1)
            cout << (char)(i - 1 + 'A') << ' ' << k[i] << endl;








    fclose(stdin);
    fclose(stdout);


}

/*
3
AAB
ABB
BBC

4
AABB
ABBB
BBBB
BBBB



*/
