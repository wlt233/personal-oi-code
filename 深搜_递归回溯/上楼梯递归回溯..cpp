#include<bits/stdc++.h>
using namespace std;
int s=0;
int n=10;
int a[20];
void write(int l)
{
	for (int k=1;k<=l;k++)cout<<a[k]<<' ';
	cout<<endl;	
}

void dfs(int i)
{
	int j;
	for (j=1;j<=2;j++)
		if (s<=n)
		{
			s+=j;
			a[i]=j;
			if (s==n) write(i);
			else dfs(i+1);
			s-=j;
		}
}

int main()
{
	dfs(1);	
}
