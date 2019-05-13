#include <iostream>
#include <cstdio>
using namespace std;
const int n=7;
int a[n]={2,3,7,5,4,6,1};
int main(){
    for(int i=0;i<=n-1;i++){
    	for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1])swap(a[j],a[j+1]);
		}
	}
	for(int p=0;p<n;p++) cout<<a[p]<<" ";
	return 0;	
}
