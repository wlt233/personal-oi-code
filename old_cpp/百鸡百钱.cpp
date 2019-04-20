
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main(){
	int p=0;
	for(int g=0;g<=100;g++){
		for(int x=0;3*x<=100-g;x++){
			int moy=5*g+x+(100-g-3*x)*3;
				if (moy==100) {
					cout<<g<<" "<<(100-g-3*x)<<" "<<x<<endl;
					p++;
				}
		}
	}
	cout<<p;
	return  0;
}

