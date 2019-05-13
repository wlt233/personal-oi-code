#include<bits/stdc++.h>
using namespace std;
int n=4;
int a[17];

void out()
{
	for (int i=0;i<=3;i++)
	{
		for (int j=1;j<=4;j++)
			cout<<a[i*n+j]<<' ';
		cout<<endl;
		
	}
	cout<<endl;
}
	
 

void cover(int i,int k)
{
	for (int j=0;j<=1;j++)
	{
		if (j==0&&((k+1)%n!=1)&&((k+1)<=n*n)&&(!a[k])&&(!a[k+1]))
		{
			a[k]=i;
			a[k+1]=i;
			k+=2;
			if (i==n*n/2)out();
			else cover(i+1,k+2);
			k-=2;
			a[k+1]=0;
			a[k]=0;
		}
		if (j==1&&((k+n)<=n*n)&&(!a[k])&&(!a[k+n]))
		{
			a[k]=i;
			a[k+n]=i;
			if (i==n*n/2)out();
			else cover(i+1,k+1);
			a[k+n]=0;
			a[k]=0;
		}
		if(j==1&&a[k])
		{
			do{
				k++;
			}while (!a[k]);
		}
	}


		
}

int main()
{	
	//freopen("F:\1.txt","w",stdout);
	cover(1,1);
	//fclose(stdout);
}
