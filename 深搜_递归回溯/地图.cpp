#include<bits/stdc++.h>
using namespace std;
int total=0;
int a[13];
int ma[13][13]={
{0,1,1,1,1,1,0,0,0,0,0,0},
{1,0,1,0,0,1,1,0,0,0,1,0},
{1,1,0,1,0,0,1,1,0,0,0,0},
{1,0,1,0,1,0,0,1,1,0,0,0},
{1,0,0,1,0,1,0,0,1,1,0,0},
{1,1,0,0,1,0,0,0,0,1,1,0},
{0,1,1,0,0,0,0,1,0,0,1,1},
{0,0,1,1,0,0,1,0,1,0,0,1},
{0,0,0,1,1,0,0,1,0,1,0,1},
{0,0,0,0,1,1,0,0,1,0,1,1},
{0,1,0,0,0,1,1,0,0,1,0,1},
{0,0,0,0,0,0,1,1,1,1,1,0},
};

void out() 
{
	total++;
	cout<<"No"<<total<<':';
	for (int i=1;i<=12;i++)
		cout<<'('<<i<<':'<<a[i]<<')';
	cout<<endl;
} 

bool check(int p,int c)
{
	for (int i=1;i<p;i++)
		if (ma[p-1][i-1])
			if (a[i]==c)return false;
	return true;
}

void paint(int i)
{
	int j;
	for (j=1;j<=4;j++)
		if (check(i,j))
		{
			a[i]=j;
			if (i==12) out();
			else paint(i+1);
		}	
	
} 

int main()
{
	paint(1);
}
