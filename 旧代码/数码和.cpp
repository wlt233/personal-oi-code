#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main(){
	int n,i=0,s=0;
	cin>>n;
	while(n%10!=0)
	{
		s=s+n%10;
		n=n/10;
		i++;
	}
	cout<<s<<endl;
	return 0;
}

