1#include<bits/stdc++.h>
using namespace std;
int main()
{
	long a, b;
	long sum, diff, prod;

	cin >> a >> b;
	sum = a + b;
	diff = a - b;
	prod = a * b;
	cout << a << '+' << b << '=' << sum << endl;
	cout << a << '-' << b << '=' << diff << endl;
	cout << a << '*' << b << '=' << prod << endl;
	return 0;
} 
