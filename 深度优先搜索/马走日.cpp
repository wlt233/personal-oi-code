#include<bits/stdc++.h>
using namespace std;
int n=5,m=9,total=0;
int ax[10],ay[10];
int dx[4]={1,2,-1,-2};
int dy[4]={2,1,2,1};

void out(int i)
{
	total++;
	cout<<"NO"<<setw(2)<<total<<':';
	cout<<'('<<ax[1]<<','<<ay[1]<<')';
	for (int k=2;k<=i;k++)
		cout<<"->("<<ax[k]<<','<<ay[k]<<')';
	cout<<endl;
	
}
	
 

void horse(int i,int x,int y)
{
	int j;
	for (j=0;j<=3;j++)
		if (x+dx[j]<=n&&x+dx[j]>=1&&
			y+dy[j]<=m&&y+dy[j]>=1)
		{
			x+=dx[j];
			y+=dy[j];
			ax[i]=x;
			ay[i]=y;
			if (x==n&&y==m) out(i);
			else horse(i+1,x,y);
			x-=dx[j];
			y-=dy[j];

		}
}

int main()
{	
	ax[1]=1;
	ay[1]=1; //第一步 
	horse(2,1,1); //从第二步开始 
	//cout<<total;
}
