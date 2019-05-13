#include<bits/stdc++.h>
using namespace std;
int total=0;
int a[9],b[17],c[17],d[17];

void write()
{
	cout<<setw(2)<<++total<<" : ";
	for (int i=1;i<=8;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}

void EQ(int i)
{
	int j;
	for (j=1;j<=8;j++)
		if (!b[j]&&!c[i-j+8]&&!d[i+j])
		{
			a[i]=j;
			b[j]=1;
			c[i-j+8]=1;
			d[i+j]=1;
			if (i==8) write();
			else EQ(i+1);
			b[j]=0;
			c[i-j+8]=0;
			d[i+j]=0;	
		}
}

int main()
{
	EQ(1);
}
