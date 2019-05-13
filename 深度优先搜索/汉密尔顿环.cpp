#include<bits/stdc++.h>
using namespace std;
int n,m,total=0;
int a[20][20];
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
	
 

int knight(int i,int x,int y)
{
	int j;
	for (j=0;j<=7;j++)
		if (x+dx[j]<=n&&x+dx[j]>=1&&
			y+dy[j]<=m&&y+dy[j]>=1&&
			!a[x+dx[j]][y+dy[j]]||
			a[x+dx[j]][y+dy[j]]==1&&i==(n*m+1))//最后一步的判断 
		{
			x+=dx[j];
			y+=dy[j];
			a[x][y]=i;
			if (i==(n*m+1)) 
			{
				cout<<n<<' '<<m<<endl;
				//out();
				return 1;
			}
			else knight(i+1,x,y);
			a[x][y]=0;
			a[1][1]=1; 
			x-=dx[j];
			y-=dy[j];
		}
	return 0;
}

int main()
{	for(n=1;n<=6;n++)
		for(m=n;m<=6;m++)
		{
			
			a[1][1]=1; //第一步 
			if(knight(2,1,1)==1) break; //从第二步开始 
		}

}
