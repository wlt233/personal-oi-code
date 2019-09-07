#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define ll long long

int n;
ll a[50001], b[50001]; //虽然不是很懂但这里必须开ll不然会爆？
ll pfs1[50002], pfs2[50002];
ll sum1, sum2;


int find(int x)
{
    int l = 1, r = n, t = 0; //t千万别忘置0你个傻子
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if (b[mid] <= x)
        {
            l = mid + 1;
            t = mid;
        }
        else r = mid - 1;
    }
    return t;
}



int main()
{
    freopen("mat.in","r",stdin);
	freopen("mat.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; i++)
    {
        pfs1[i] = pfs1[i - 1] + b[i];
        pfs2[i] = pfs2[i - 1] + b[i] * b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int t = find(a[i]);
        //cout << "t = "<< t << endl;
        sum1 += t * a[i] * a[i] + pfs2[t] - 2 * a[i] * pfs1[t];
        sum2 += (n - t) * a[i] * a[i] + pfs2[n] - pfs2[t] - 2 * a[i] * (pfs1[n] - pfs1[t]);
    }
   
    cout << fixed << setprecision(1) << (double)(sum1 - sum2) / n << endl; 
   
    fclose(stdin);
    fclose(stdout);

    //for (int i = 1; i <= n; i++) cout << b[i] << ' ';
}

/*
2
3 7
5 1
*/
