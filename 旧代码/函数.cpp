#include<bits/stdc++.h>
using namespace std;
int jc(int);
int main(){
	int s=0;
	
	for(int i=1;i<=10;i++){
		s+=jc(i);
	}
	cout<<s;
	
}
int jc(int i){
	int k=1;
	for(int j=2;j<=i;j++){
		k*=j;
	}
	return k;
}
