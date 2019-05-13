#include<bits/stdc++.h>
using namespace std;
int plist[21] = {0,1};
int used[21];
int total=0,num=20;
bool isprime(int n)
{
	if (n==0) return false;
	for (int i = 2;i <= sqrt(n);i++)
		if(n%i == 0)return false;
	return true;
}



void out()
{
	total++;
	for (int i=1;i<=num;i++)
		cout<<plist[i]<<' ';
	cout<<endl;
}

int dfs(int d)
{
	for (int i=1;i<=num;i++)
		if (!used[i]&&isprime(plist[d-1]+i))
		{
			plist[d] = i;
			used[i] = 1;
			if (d==num&&isprime(plist[num]+plist[1])) out();
			else dfs(d+1);
			plist[d] = 0;
			used[i] = 0; 
		}	
	
}

int main()
{
	used[1] = 1;
	dfs(2);
	cout<<total;
}
