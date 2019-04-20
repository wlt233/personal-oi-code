#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main(){
	int k,a=1,b=1,i=1;
	cin>>k;
	while(i<=(k-1)/2){
		a=a+b;
		b=a+b;
		i++;
	}
	k%2==0?cout<<b<<endl:cout<<a<<endl;
	return  0;
}


