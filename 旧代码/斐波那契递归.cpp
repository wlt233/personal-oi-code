#include <bits/stdc++.h>
using namespace std;
long long fb(int n)
{
	if (n == 1 || n == 2) return 1;
	else return fb(n-1) + fb(n-2);
}
int main()
{
	int n;
	cin>>n;
	cout<<fb(n);
}
