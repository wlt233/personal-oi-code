#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main(){
	int a,b,r=0;
	cin>>a>>b;
	while(a%b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	cout<<b<<endl;
	return  0;
}


