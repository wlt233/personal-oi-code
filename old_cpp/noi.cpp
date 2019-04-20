#include<bits/stdc++.h>
using namespace std;
int main(){
	char ta[200],tb[200],s[201];
	int a[200],b[200];
	gets(ta);
	int la=strlen(ta);
	for(int i=0;i<la;i++)a[i]=ta[la-i-1]-48;
	gets(tb);
	int lb=strlen(tb);
	for(int i=0;i<lb;i++)b[i]=tb[lb-i-1]-48;

	int m=la>lb?la:lb;
	s[0]=0;
	for(int i=0;i<m;i++){
		s[i]=a[i]+b[i]+s[i];
		cout<<"a"<<int(s[i])<<" ";
		if(s[i]>9){
			s[i+1]=0;
			s[i+1]+=s[i]/10;
			s[i]=s[i]%10;
			cout<<s[i]/10<<" ";
		}
		cout<<"b"<<int(s[i])<<" ";
	}
	int lf=strlen(s);
	cout<<lf<<endl;
	for (int i=lf;i>0;i--)cout<<int(s[i-1]);
	
	
	
	
	
	
}

