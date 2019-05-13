#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define N 20
#define L 3.0
int main(){
	int s[N],a=0;
	for(int i=0;i<=L;i++){
		cin>>s[i];
		a+=s[i];
	}
	float avg=a/(L+1); 
	cout<<avg<<endl;
	for(int i=0;i<=L;i++){
		if(s[i]>=avg)cout<<s[i]<<endl;
	}
	return 0;
}

