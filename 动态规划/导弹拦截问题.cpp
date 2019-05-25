#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m = 12,a[4][12] = {{276,263,300,287,315,278,281,300,276,275,301,253},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
	/*
	cin >> m;
	for (int i = 0; i < m; i++) cin >> a[0][i];
	*/
	
	
	//the first question
	a[1][0] = 1; a[2][0]=0;
	for (int i = 1; i < m; i++)
	{
		a[1][i] = 1;
		int maxj = 1;
		for (int j = 0; j <= i-1; j++)
		{
			if (a[0][j] >= a[0][i])
				if (a[1][j] >= maxj)
				{
					maxj = a[1][j];
					a[1][i] = a[1][j] + 1;
					a[2][i] = j;
				}
		}
	} 
	
	int maxans = 0,maxpoi;
	for (int i = 0; i < m; i++)
	{
		if (a[1][i] > maxans) maxans = a[1][i]; maxpoi = i;
	} 
	cout << maxans << endl;
	
	
	int anslist[maxans]; anslist[maxans-1] = maxpoi;
	int pnt = a[2][maxpoi];
	for (int k = maxans-2; k >= 0; k--)
	{
		anslist[k] = pnt;
		pnt = a[2][pnt];
	}
	for (int k = 0; k <= 5; k++)
	{
		cout<< a[0][anslist[k]] <<endl;
		
	}
	
	
	//the second question
	int s = 0;
	int sh[10];
	for (int i = 0; i < m; i++)
	{
		int f = 0;
		int smin = 10000;
		for(int j = 0; j <= s; j++)
		{
			if (sh[j] >= a[0][i]) 
				{
					if (sh[j] <= smin) 
					{
						a[3][i] = j;
						sh[j] = a[0][i];
						smin = sh[j];
						f = 1;
					}
				}
		}
		if (f == 0)
		{
			s++;
			sh[s] = a[0][i];
			a[3][i] = s;
		}
	}
	for (int k = 0; k <= 11; k++)
	{
		cout<< a[3][k] <<endl;
		
	}
}
