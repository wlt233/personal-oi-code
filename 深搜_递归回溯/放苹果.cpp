#include<bits/stdc++.h>
using namespace std;
int s;
int m,n,ans[21];
int pj,ppj,total=0;

void apple(int i)
{
	int j;
	for (j=m;j>=1;j--)
		if (s-j>=0&&i<=n&&j<=pj)
		{
			s-=j;
			ppj=pj; 
			pj=j;
			if (s==0&&i>=0) total++;
			else if (s<0) break; 
			else apple(i+1);
			s+=j;
			pj=ppj;
		}
}

int main()
{
	int t; 
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>m>>n;
		s=m;pj=m;
		apple(1);
		ans[i]=total;
	}
	for (int i=1;i<=t;i++)
		cout<<total;
}
