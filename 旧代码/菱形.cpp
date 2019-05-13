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
		for(int j=1;j<=abs(n-i);j++){
			cout<<" ";
		}	
		for(int j=1;j<=1+2*(n-1-abs(n-i));j++){
			cout<<"*";
		}
	cout<<endl;
	}
	return  0;
}

