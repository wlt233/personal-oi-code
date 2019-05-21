#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 5;
	//cin >> n;
	int tri[5][5]=
	{
		{5,0,0,0,0},
		{3,8,0,0,0},
		{6,0,1,0,0},
		{1,5,2,3,0},
		{4,6,1,2,5}
	};
	int tri2[5][5];
	for (int i = 0; i<=4; i++)
		for (int j = 0; j<=4; j++)	
			tri2[i][j] = tri[i][j];
	

	//max
	for (int i = n-2; i>=0; i--) 
		for (int j = 0; j <= i; j++) 
			tri[i][j] = (tri[i+1][j] > tri[i+1][j+1]) ? tri[i][j]+tri[i+1][j] : tri[i][j]+tri[i+1][j+1];
	
	//min
	for (int i = n-2; i>=0; i--)
		for (int j = 0; j <= i; j++)
			tri2[i][j] = (tri2[i+1][j] < tri2[i+1][j+1]) ? tri2[i][j]+tri2[i+1][j] : tri2[i][j]+tri2[i+1][j+1];
	
	cout << "max = " <<tri[0][0] << "  " << "min = " <<tri2[0][0] << endl;
	
	//max - out
	int lo = 0;
	for (int i = 0; i<=n-1; i++)
	{
		if (tri[i+1][lo] > tri[i+1][lo+1]) 
		{
			cout << tri[i][lo]-tri[i+1][lo] << endl;
		} 
		else
		{
			cout << tri[i][lo]-tri[i+1][lo+1] << endl;
			lo++;
		}
	}
	cout << endl;
	
	//min - out
	int lo2 = 0;
	for (int i = 0; i<=n-2; i++)
	{
		if (tri2[i+1][lo2] < tri2[i+1][lo2+1]) 
		{
			cout << tri2[i][lo2]-tri2[i+1][lo2] << endl;
		} 
		else
		{
			cout << tri2[i][lo2]-tri2[i+1][lo2+1] << endl;
			lo2++;
		}
		
	}

	(tri2[n-1][lo2] < tri2[n-1][lo2+1]) ? cout<<tri2[n-1][lo2] : cout<<tri2[n-1][lo2+1] ;
}
