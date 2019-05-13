#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define N 20
#define L 6
int main(){
	int s[N]={1,2,3,4,5,6,7,0};
	int n,l;
	cin>>n>>l;
	for(int i=L+1;i>=l;i--){
		s[i]=s[i-1];
	}
	s[l-1]=n;
	for(int i=0;i<=L+1;i++){
		cout<<s[i]<<" ";
	}
	
}

