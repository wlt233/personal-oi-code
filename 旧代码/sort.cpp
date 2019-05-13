#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 int a[20]={2,4,1,23,5,76,0,43,24,65,234,546,7,6,54,7,43,234,5,3},i;
 for(i=0;i<20;i++)cout<<a[i]<<' ';
 sort(a,a+20);
 for(i=0;i<20;i++)cout<<a[i]<<endl;
 return 0;
}

