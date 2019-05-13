#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define h 15
int main(){
	int a[h][h];
	for(int i=0;i<h;i++){
		a[i][0]=1;
		for(int j=1;j<i;j++){
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
		a[i][i]=1;
	}
	float w=5;
	int m=(w+1)*h-1;
	int s=(m+1)/2;
	int q=ceil(w/2);
	for(int i=0;i<h;i++){
		for(int p=0;p<s-q*(i+1);p++) cout<<' ';
		for(int j=0;j<=i;j++){
			cout<<left<<setw(w)<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;	
}
