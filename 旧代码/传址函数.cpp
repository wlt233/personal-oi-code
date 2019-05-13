#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b);
int main(){
	int c=1,d=2;
	swap(c,d);
	cout<<c<<" "<<d;
	
}
void swap(int &a,int &b){
	int t=b;
	b=a;
	a=t;
}
