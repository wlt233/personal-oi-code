#include<bits/stdc++.h>
using namespace std;

int mhd(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}


int n, m;
int xhx[100000], xhy[100000];
int jzx[100000], jzy[100000], jzz[100000]; 


int main()
{
	cin >> n >> m;
    int minans = 10000000;
    for (int i = 0; i < n; i++)
        cin >> xhx[i] >>xhy[i];
    for (int i = 0; i < m; i++)
        cin >> jzx[i] >>jzy[i] >> jzz[i];

    for (int jz = 0; jz < m; jz++)
    {
        int mhdmax = 0;
        for (int xh = 0; xh < n; xh++)
        {
            int mhdd = mhd(xhx[xh], xhy[xh], jzx[jz], jzy[jz]);
            //cout<<mhdd<<endl;1
            if (mhdd > mhdmax) mhdmax = mhdd;
        }
        int pri = mhdmax * jzz[jz];
        //cout<<mhdmax<<' '<<jzz[jz]<<endl;
        if  (pri < minans) minans = pri;
    }
    cout << minans;

	return 0;
} 
/*
3 2
1 5
2 3
6 1
3 3 7
3 2 9
 */