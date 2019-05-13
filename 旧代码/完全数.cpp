#include<bits/stdc++.h>
using namespace std;

bool c(int n){
	int s=1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			s+=i;
			s+=n/i;
		}
	}
	if(sqrt(n)==floor(sqrt(n)))s-=sqrt(n);
	if(s==n)return true;
	else return false;
}
int main(){
	for(int j=1;j<20000;j++)if(c(j))cout<<j<<" ";
	
}

