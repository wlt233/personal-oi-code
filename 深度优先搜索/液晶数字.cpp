#include<bits/stdc++.h>
using namespace std;
int total=0;
int a[20],u[10];
int trans[10][10]={{0,1,0,0,0,0,0,1,1,0},{1,0,0,1,1,0,0,1,1,1},{0,0,0,0,0,0,0,0,1,0},{0,1,0,0,0,0,0,1,1,1},{0,1,0,0,0,0,0,0,1,1},{0,0,0,0,0,0,1,0,1,1},{0,0,0,0,0,1,0,0,1,0},{1,1,0,1,0,0,0,0,1,1},{1,1,1,1,1,1,1,1,0,1},{0,1,0,1,1,1,0,1,1,0}};

void out()
{
	total++;
	cout<<setw(2)<<total<<" : ";
	for (int i=1;i<=10;i++)
		cout<<a[i]<<' ';
	cout<<endl;
} 

void num(int i)
{
	int j;
	for (j=0;j<=9;j++)
		if (trans[a[i-1]][j]&&!u[j])
		{
			a[i]=j;
			u[j]=1;
			if (i==10) out();
			else num(i+1);
			u[j]=0;
		}	
	
} 

int main()
{
	a[0]=8;
	num(1);
}
