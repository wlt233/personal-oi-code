#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int64_t main(){
	int64_t num,k,p=0;
	cin>>k;
	for(num=2;num<=k;num++){
		int64_t i=2,f=0;
		while(i<=sqrt(num)&&f==0){
			if (num%i==0) f=1;
			i++;
		}
		if(f==0){
			cout<<setw(3)<<num;
			p++;
			p%8==0?cout<<endl:cout<<" ";
		}
	}
	cout<<p<<endl;
	return  0;
}


