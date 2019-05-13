#include<bits/stdc++.h>
using namespace std;
int total=0,s=0;
int a[7],f[7];
int ma[6][6]={
{0,3,5,0,0,0},
{3,0,1,7,4,0},
{5,1,0,0,2,0},
{0,7,0,0,1,7},
{0,4,2,1,0,8},
{0,0,0,7,8,0},
};
int maxf=0,minf=100,maxp[7],minp[7];

void out(int i) 
{
	
	if (s<minf)
	{
		minf=s;
		minp[0]=i;
		for (int j=1;j<=i;j++)
			minp[j]=a[j];	
	}
	if (s>maxf)
	{
		maxf=s;
		maxp[0]=i;
		for (int j=1;j<=i;j++)
			maxp[j]=a[j];	
	}
} 

void fee(int i,int c)
{
	int j;
	for (j=1;j<=6;j++)
		if (!f[j]&&ma[c-1][j-1])
		{
			a[i]=j;
			f[j]=1;
			s+=ma[c-1][j-1];
			if (j==6) out(i);
			else fee(i+1,j);
			a[i]=0;
			f[j]=0;
			s-=ma[c-1][j-1];
		}	
	
} 

int main()
{
	a[1]=1;f[1]=1;
	fee(2,1);
	cout<<maxf<<':';
	for (int j=1;j<=maxp[0];j++)
		cout<<maxp[j]<<' ';
	cout<<endl;
	cout<<minf<<':';
	for (int j=1;j<=minp[0];j++)
		cout<<minp[j]<<' ';
	cout<<endl;
}
