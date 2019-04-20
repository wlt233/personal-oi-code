#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
	cout<<*a<<*b<<endl;
}

int main()
{
	int a,b;
	cin>>a>>b;
	swap(&a,&b);
	cout<<a<<b;
	return 0;
}
