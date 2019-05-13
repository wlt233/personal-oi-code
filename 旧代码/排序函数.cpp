#include<bits/stdc++.h>
using namespace std;
void b(int l[],int);
void swap(int &a,int &b){
	int t=b;
	b=a;
	a=t;
}
int main(){
	int l[3]={3,2,1};
	b(l,3);
	for(int g=0;g<3;g++)cout<<b[g]<<" ";
}
void b(int l[],int n){
	for (int j=0;j<n;j++){
		for (int k=j+1;k<n;k++){
			if(l[k]>l[k-1])swap(l[j],l[k]);
		}
	}
}
