#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int as,ap,bs,bp,cs,cp,a,b,c,p;
	float n;
	cin>>n;
	cin>>as>>ap;
	cin>>bs>>bp;
	cin>>cs>>cp;
	a=ceil(n/as);
	b=ceil(n/bs);
	c=ceil(n/cs);
	p=a*ap;
	if (b*bp<=p) p=b*bp;
	if (c*cp<=p) p=c*cp;
	cout<<p;
	return 0;
}
