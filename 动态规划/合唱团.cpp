#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m = 12,a[9][12] = {{276,263,300,287,315,278,281,300,276,275,301,253},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{253,301,275,276,300,281,278,315,287,300,263,276}};
	/*
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		 cin >> a[0][i];
		 a[3][m-1-i] = a[0][i];
	}
	*/
	
	

	a[1][0] = 1; a[2][0] = 0;
	for (int i = 1; i < m; i++)
	{
		a[1][i] = 1;
		int maxj1 = 1;
		for (int j = 0; j <= i-1; j++)
		{
			if (a[0][j] <= a[0][i])
				if (a[1][j] >= maxj1)
				{
					maxj1 = a[1][j] + 1;
					a[1][i] = a[1][j] + 1;
					a[2][i] = j+1;
				}
		}
	} 

	a[4][0] = 1; a[5][0] = 0;
	for (int i = 1; i < m; i++)
	{
		a[4][i] = 1;
		int maxj2 = 1;
		for (int j = 0; j <= i-1; j++)
		{
			if (a[3][j] <= a[3][i])
				if (a[4][j] >= maxj2)
				{
					maxj2 = a[4][j] + 1;
					a[4][i] = a[4][j] + 1;
					a[5][i] = j+1;
				}
		}
	} 
	
	
	for (int i = 0; i < m; i++)
	{
		a[8][i] = a[1][i] + a[4][m-1-i];
		a[6][i] = a[4][m-1-i];
		a[7][i] = a[5][m-1-i];
	} 

	
	for (int i = 0; i < m; i++)
	{
		//cout << i+1 <<" "<< a[0][i]<<" " <<a[8][i] <<" "<< endl;
	} 
	
	

	
	int maxans = 0,maxpoi;
	for (int i = 0; i < m; i++)
	{
		if (a[8][i] > maxans) maxans = a[8][i]; maxpoi = i;
	} 
	cout << maxans;
	/*
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
	*/
	

}





