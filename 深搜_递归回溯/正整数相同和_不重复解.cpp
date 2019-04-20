#include<bits/stdc++.h>
using namespace std;
int s = 0;
int a[20],f[20],sum[20];
int m,n,t=0,tt;

void write(int k)
{
	for (int i=1;i<=k;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	t = 0;
	tt = 0;
}

void sz(int i)
{
	int j;
	for (j=1;j<=n;j++)
		if (s+sum[j]<=m&&!f[j]&&j>t)
		{
			a[i] = sum[j];
			f[j] = 1;
			tt = t;
			t = j;
			s += sum[j];
			if (s==m) write(i);
			else sz(i+1);
			a[i] = 0;
			f[j] = 0;
			s -= sum[j];
			t = tt;
		}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>sum[i];
	sz(1);
}
