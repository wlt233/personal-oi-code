#include<bits/stdc++.h>
using namespace std;
int like[6][6]={{0},{0,0,0,1,1,0},{0,1,1,0,0,1},{0,0,1,1,0,0},{0,0,0,0,1,0},{0,1,1,0,0,1}};
int book[6],flag[6]; 
int n=5;

void write()
{
	for (int k=1;k<=n;k++)cout<<book[k]<<' ';
	cout<<endl;	
}

void dfs(int i)
{
	int j;
	for (j=1;j<=n;j++)
		if (like[i][j]&&!flag[j])
		{
			book[i]=j;
			flag[j]=1;
			if (i==n) write();
			else dfs(i+1);
			flag[j]=0;
		}
}

int main()
{
	dfs(1);	
}
