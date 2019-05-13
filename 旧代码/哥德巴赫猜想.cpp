#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main(){
	int64_t num,even;
	cin>>even;
	for(num=2;num<=even;num++){
		int64_t i=2,f=0;
		while(i<=sqrt(num)&&f==0){
			if (num%i==0) f=1;
			i++;
		}
		if(f==0){
			int64_t num2=even-num,f2=0;
			while(i<=sqrt(num2)&&f2==0){
				if (num2%i==0) f2=1;
				i++;
			}
			if(f2==0){
				num<=num2?cout<<num<<" "<<num2<<endl:cout<<"";
			}
		}
	}
	return  0;
}

