#include<bits/stdc++.h>
using namespace std;
int n=4,m=5,total=0;
int a[5][6];
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};

void out()
{
	total++;
	cout<<total<<':'<<endl;
	for (int x=1;x<=n;x++)
	{
		for (int y=1;y<=m;y++)
			cout<<setw(2)<<a[x][y]<<' ';
		cout<<endl;
	}
}
	
 

void knight(int i,int x,int y)
{
	int j;
	for (j=0;j<=7;j++)
		if (x+dx[j]<=n&&x+dx[j]>=1&&
			y+dy[j]<=m&&y+dy[j]>=1&&
			!a[x+dx[j]][y+dy[j]])
		{
			x+=dx[j];
			y+=dy[j];
			a[x][y]=i;
			if (i==n*m) out();
			else knight(i+1,x,y);
			a[x][y]=0;
			x-=dx[j];
			y-=dy[j];
		}
}

int main()
{	
	a[1][1]=1; //第一步 
	knight(2,1,1); //从第二步开始 
	cout<<total;
}
