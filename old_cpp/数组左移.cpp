#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define N 20
#define L 6
int main(){
	int s[N]={1,2,3,4,5,6,7};
	int f=s[0];
	for(int i=0;i<=L;i++){
		s[i]=s[i+1];
	}
	s[L]=f;
	for(int i=0;i<=L;i++){
		cout<<s[i]<<" ";
	}
	
}

