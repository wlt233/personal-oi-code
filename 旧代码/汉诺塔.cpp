#include<bits/stdc++.h>
using namespace std;
void hana(int n,char f,char t,char h){
	if (n==1) cout<<f<<" to "<<t<<endl;
	else{
		hana(n-1,f,h,t);
		cout<<f<<" to "<<t<<endl;
		hana(n-1,h,t,f);	
	}
}                                                                                      
int main(){
	int x;
	cin>>x;
	hana(x,'a','c','b');
}

