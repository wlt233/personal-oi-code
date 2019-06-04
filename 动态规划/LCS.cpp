#include<bits/stdc++.h>
using namespace std;

int a[100] = {0,'A','B','C','A','B','D','F'},m,
	b[100] = {0,'B','A','D','E','F'},n;
int fij[100][100];

int f(int i, int j)
{
	if (i == 0 || j == 0) return 0;
	else if (a[i] == b[j])return fij[i-1][j-1]+1;
	else 
	{
		if (fij[i-1][j] > fij[i][j-1]) return fij[i-1][j];
		else return fij[i][j-1];
	} 
}


int main()
{
	m=7;n=5;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
		{
			fij[i][j] = f(i,j);	
		}
	for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
				cout << fij[i][j] <<' ';
			cout << endl;
		}
	cout << fij[m][n];
}
