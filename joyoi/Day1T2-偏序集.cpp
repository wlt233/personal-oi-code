#include<bits/stdc++.h>
using namespace std;
int x1[100000], yy1[100000], x2[100000], y2[100000], a[2][100000];
int main()
{
	int n, n1=0, n2=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 1)
		{
			x1[n1] = a;
			yy1[n1] = b;
			n1++;
		}
		if (c == 2)
		{
			x2[n2] = a;
			y2[n2] = b;
			n2++;
		}
	}
	
	for (int i = 0; i < n1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n1; j++)
		{
			if (x1[j] <= x1[min]) min = j;
		}
		int tx = x1[i];
		x1[i] = x1[min];
		x1[min] = tx;
		int ty = yy1[i];
		yy1[i] = yy1[min];
		yy1[min] = ty;
	}
	for (int i = 0; i < n2; i++)
	{
		int min = i;
		for (int j = i + 1; j < n2; j++)
		{
			if (x2[j] <= x2[min]) min = j;
		}
		int tx = x2[i];
		x2[i] = x2[min];
		x2[min] = tx;
		int ty = y2[i];
		y2[i] = y2[min];
		y2[min] = ty;
	}

	//cout << x1[n1 - 1] << x2[0] << endl;
	if (x1[n1 - 1] <= x2[0])
	{
		for (int i = 0; i < n1; i++) a[0][i] = yy1[i];
		for (int i = n1; i < n; i++) a[0][i] = y2[i - n1];

		a[1][n - 1] = 1; 
		for (int i = n - 2; i >= 0; i--)
		{
			a[1][i] = 1;
			int maxj = 1;
			for (int j = n; j >= i+1; j--)
			{
				if (a[0][j] >= a[0][i])
					if (a[1][j] >= maxj)
					{
						maxj = a[1][j] + 1;
						a[1][i] = a[1][j] + 1;
					}
			}
		} 
		int maxans = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[1][i] > maxans) maxans = a[1][i]; 
		} 
		cout << maxans << endl;
	}
	else 
	{
		int maxans = 0;

		for (int p = x2[0]; p <= x1[n1 - 1]; p++)
		{
			int na = 0;
			for (int i = 0; i < n1; i++)
			{
				if (x1[i] <= p)
				{
					a[0][na] = yy1[i];
					na++;
				}
			}
			for (int i = 0; i < n2; i++) 
			{
				if (x2[i] >= p)
				{
					a[0][na] = y2[i];
					na++;
				}
			}
			//for (int i = 0; i < na; i++) cout << a[0][i]<<' ';
    		//cout << endl;
			
			a[1][na - 1] = 1; 
			for (int i = na - 2; i >= 0; i--)
			{
				a[1][i] = 1;
				int maxj = 1;
				for (int j = na; j >= i+1; j--)
				{
					if (a[0][j] >= a[0][i])
						if (a[1][j] >= maxj)
						{
							maxj = a[1][j] + 1;
							a[1][i] = a[1][j] + 1;
						}
				}
			} 
			for (int i = 0; i < na; i++)
			{
				if (a[1][i] > maxans) maxans = a[1][i]; 
			} 
		}
		cout << maxans << endl;
	}

	return 0;
} 

/*
4
5 5 2
3 3 2
1 6 2
1 1 1

6
1 9 1
2 6 1
3 7 1
4 8 2
5 9 2
6 9 2
 */
