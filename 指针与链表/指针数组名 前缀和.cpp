#include<bits/stdc++.h>
using namespace std;
int n,*a;
int main()
{
	scanf("%d",&n);
	a = new int[n+1];
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=2;i<=n;i++)
		a[i]+=a[i-1];
	for (int i=1;i<=n;i++)	
		printf("%d ",a[i]);	
	

}
