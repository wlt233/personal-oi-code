#include<bits/stdc++.h>
using namespace std;
int n,total;
int a[20][20];
int dx[3]={0,1,0}; 
int dy[3]={0,0,1} ;

void out()
{
	total++;
	cout<<total<<':'<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
}
	
 

void cover(int i,int x,int y)
{
	for (int j=1;j<=2;j++)
		if (1<=x+dx[j]&&x+dx[j]<=n&&
			1<=y+dy[j]&&y+dy[j]<=n&&
			!a[x][y]&&!a[x+dx[j]][y+dy[j]])
		{
			//cout<<i<<' '<<x<<y<<x+dx[j]<<y+dy[j]<<endl;
			a[x][y]=i;
			a[x+dx[j]][y+dy[j]]=i;
			if (i==n*n/2) out();
			else 
			{
				int tx=x,ty=y;
				do{
					ty++;
					if (ty>n)
					{
						tx++;
						ty=1;
					}
				}while (a[tx][ty]);
				cover(i+1,tx,ty) ;
			}
			a[x][y]=0;
			a[x+dx[j]][y+dy[j]]=0;
		}
}

int main()
{	
	cin>>n;
	freopen("cover.txt","w",stdout);
	cover(1,1,1);
	fclose(stdout);
}
