
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;
#define ll long long
#define INF 0x7f

int n = 0;
int book[100]; //65-90
double p[1001][1001];

int main()
{
    char c;
    while ((c = getchar()) && c <= 'Z' && c >= 'A')
    {
        book[c]++;
        n++;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> p[i][j];


    int maxchar = INF;
    //for (int i = 65; i <= 90; i++)
    //   if (book[i] < maxchar) maxchar = book[i];
    int k = (n-1) * (n-1);
    cout << fixed << setprecision(1) << (float)k  ;

    
}



