#include <iostream>
#include <cstdio>
using namespace std;
const int n=6;
int a[n]={2,3,1,5,4,6};
int main(){
    for(int i=1;i<n;i++){
		for(int j=i-1;j<n;j++){
			if(a[j]>a[k])7k=j;
		}
		swap(a[i],a[k]);  
	}
	for(int p=0;p<n;p++) cout<<a[p]<<" ";
	return 0;	
}
