#include<bits/stdc++.h>
using namespace std;

bool c(int n,int i){
	int f=0;
	while(n){
		if(n%10==i) {
			return true;
			f=1;
		}
		n/=10;
	}
	if(f=0)return false;
}
int main(){
	cout<<c(12345,6);
}

