#include<bits/stdc++.h>
using namespace std;
int k,n[10]={0},dx[5]={0,1,0,-1,0},dy[5]={0,0,1,0,-1};
int g[10][10]={0},f[12]={0},hb,lb,c;
void dfs(int range,int x,int y)
{
	int j;
	for(j=1;j<5;j++)
	if(x+dx[j]>-1&&y+dy[j]>-1&&x+dx[j]<range
	&&y+dy[j]<range&&g[x+dx[j]][y+dy[j]]==0)
	{
		x+=dx[j];y+=dy[j];g[x][y]=1;
		if(x==hb&&y==lb) f[c]=1;
		else dfs(range,x,y);
		g[x][y]=0;x-=dx[j];y-=dy[j];
	}
}
main()
{
	int x,y;
	int i,j,q;char ch;
	cin>>k;
	for(i=1;i<=k;i++)
	{	c=i;
		cin>>n[i];
		for(j=0;j<n[i];j++)
		{
			for(q=0;q<n[i];q++)
			{
				cin>>ch;
				if(ch=='.') g[j][q]=0;
				else if(ch=='#') g[j][q]=1;
			}
		}
		cin>>x>>y>>hb>>lb;
		dfs(n[i],x,y);
	}
	for(i=1;i<=k;i++)
	{
		if(f[i]==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
