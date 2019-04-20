#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,s,t,*pa,*pb;
	pa = &a; pb = &b;
	cin>>a>>b;
	s = *pa + *pb;
	t = *pa * *pb;
	cout<<"a="<<a<<' '<<"b="<<b<<endl;
	cout<<"s="<<s<<' '<<"t="<<t<<endl;
}
