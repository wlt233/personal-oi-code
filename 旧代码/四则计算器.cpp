#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
	int a,b;
	char op;
	cin>>a>>b>>op;
    switch (op)
	{
		case'+':cout<<a+b<<endl;break;
		case'-':cout<<a-b<<endl;break;
		case'*':cout<<a*b<<endl;break;
		case'/':b!=0?cout<<a/b<<endl:cout<<"Divided by zero!"<<endl;break;
		default:cout<<"Invalid operator!"<<endl;break;
		
	}
	return 0;
}
