#include<bits/stdc++.h>
using namespace std;

int head = 0, tail = 1;
struct node{
	int a[8];
	int pnt,dep,sp;
}data[1000],now,temp;

int change[8][8] = 
{
	{0,1,1,1,1,0,0,0},
	{1,0,1,1,1,0,0,0},
	{1,1,0,1,0,1,1,0},
	{1,1,1,0,0,0,1,1},
	{1,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,1,0},
	{0,0,1,1,0,1,0,1},
	{0,0,0,1,0,0,1,0}
};
int fromto[8][8] = 
{
	{0,1,1,1,3,0,0,0},
	{3,0,3,3,1,0,0,0},
	{5,5,0,5,0,2,2,0},
	{7,7,7,0,0,0,2,2},
	{6,6,0,0,0,0,0,0},
	{0,0,4,0,0,0,4,0},
	{0,0,7,5,0,7,0,5},
	{0,0,0,8,0,0,8,0}
};
/*
int to[8][8] =
{
	{0,3,5,7,6,0,0,0},
	{1,0,5,7,6,0,0,0},
	{1,3,0,7,0,4,0,0},
	{1,3,5,0,0,0,0,8},
	{3,1,0,0,0,0,0,0},
	{0,0,2,0,0,0,7,0},
	{0,0,0,0,0,4,0,8},
	{0,0,0,2,0,0,5,0}
};
*/


bool repeat()
{
	for (int i = 1; i < tail; i++)
	{
		int f = 0;
		for (int j = 0; j <=7; j++)
			if (data[i].a[j] != temp.a[j]) f = 1;
		if (f == 0) return true;
	}
	return false;
} 


bool succ()
{
	if (temp.a[3] == 1 && temp.a[4] == 2 && temp.a[5] == 3 && temp.a[6] == 4 && temp.a[7] == 5) return 1;
	return 0;
}


void out(int n)
{
	cout << "  " << data[n].a[0] << ' ' << data[n].a[1] << ' ' << data[n].a[2] << endl;
	cout << data[n].a[3] << ' ' << data[n].a[4] << ' ' << data[n].a[5] << ' ' << data[n].a[6] << ' ' << data[n].a[7] << endl;
	cout << endl;
}


int bfs()
{
	do{
		head++;
		now = data[head];
		for (int r = 0; r <= 7; r++)
			if (change[now.sp][r])
			{
				temp = now;
				temp.dep++; temp.pnt = head;
				int t = temp.a[fromto[now.sp][r]-1];
				temp.a[fromto[now.sp][r]-1] = temp.a[fromto[r][now.sp]-1];
				temp.a[fromto[r][now.sp]-1] = t;
				temp.sp = r;
				tail++;
				data[tail] = temp;
				if (repeat()) tail--;
				else if (succ()) return 1;
			}
	} while (head < tail);
	return 0;
}


int main()
{
	int init[5] = {4,5,3,1,2};
	for (int j = 0; j < 5; j++)
			data[1].a[j+3] = init[j];
	data[1].dep = 0; data[1].sp = 4; 
	
	out (1);
	
	if (bfs() == 1)
	{
		int dep = data[tail].dep,pnt = tail;
	int ans[dep];
	ans[0] = tail;
	for (int i = 1;i < dep;i++)
	{
		pnt = data[pnt].pnt;
		ans[i] = pnt;
	}
	for (int i = dep-1;i >= 0;i--) out(ans[i]);	
	}
	else cout << "No solution!"<<endl; 

}
