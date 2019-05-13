#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=2*n-1;i++){
		for(int j=1;j<=abs(n-i);j++) cout<<" ";	
		int l=1+2*(n-1-abs(n-i)),m=(l+1)/2;
		for(int j=1;j<=l;j++) cout<<1+(m-1-abs(m-j));	
		cout<<endl;
	}
	return  0;
}

