#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
	int y,m;
	cin>>y>>m;
	m!=2?(m==1||3||5||7||8||10||12?cout<<"31"<<endl:cout<<"30"<<endl):cout<<(y%4==0&&y%100!=0||y%400==0)+28<<endl;
	return 0;
}
