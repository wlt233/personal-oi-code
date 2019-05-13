#include<bits/stdc++.h>
using namespace std;

int move[6] = {-2,-1,1,2,3,-3};
int price[6] = {1,1,1,1,2,2};
int head = 0, tail = 1;


struct node{
	int a[8];
	int pnt,dep,sp,cost;
}data[1000],now,temp;


bool repeat()
{
	for (int i = 1; i < tail; i++)
	{
		int f = 0;
		for (int j = 1; j <=7; j++)
			if (data[i].a[j] != temp.a[j]) f = 1;
		if (f == 0) return true;
	}
	return false;
} 


bool succ()
{
	int n = 0;
	for (int j = 1; j <=7; j++)
		if (temp.a[j] == 2) n++;
		else if (temp.a[j] == 1) break;
	if (n == 3) return true;
	return false;
}


void out(int no)
{
	cout << setw(3) << 1 << " : ";
	for (int j = 1; j <=7; j++) 
		if (data[1].a[j] == 1) cout << 'B' << ' ';
		else if (data[1].a[j] == 2) cout << 'K' << ' ';
		else cout << "  ";
	cout << endl;
	int dep = data[no].dep,pnt = tail;
	int ans[dep];
	ans[0] = no;
	for (int i = 1;i < dep;i++)
	{
		pnt = data[pnt].pnt;
		ans[i] = pnt;
	}
	for (int i = dep-1;i >= 0;i--) 
	{
		cout << setw(3) << ans[i] << " : ";
		for (int j = 1; j <=7; j++) 
			if (data[ans[i]].a[j] == 1) cout << 'B' << ' ';
			else if (data[ans[i]].a[j] == 2) cout << 'K' << ' ';
			else cout << "  ";
		cout << endl;
	}
	cout << "cost = " << data[no].cost << endl;
}


int bfs()
{
	do{
		head++;
		now = data[head];
		for (int r = 1; r <= 6; r++)
			if (move[r]+now.sp <= 7 && move[r]+now.sp >= 0)
			{
				temp = now;
				temp.a[temp.sp] = temp.a[move[r]+temp.sp];
				temp.a[move[r]+temp.sp] = 0;
				temp.pnt = head;
				temp.dep++;
				temp.sp = move[r]+temp.sp;
				temp.cost += price[r];
				
				tail++;
				data[tail] = temp;
				if (repeat()) tail--;
				else if (succ()) out(tail);
			}
	} while (head < tail);
	return 0;
}


int main()
{
	int init[8] = {0,1,2,1,1,0,2,2};
	for (int j = 0; j <=7; j++)
			data[1].a[j] = init[j];
	data[1].dep = 0; data[1].sp = 5; data[1].cost = 0;
	
	bfs();
	//if (bfs() == 1)
	//{
	//	out(tail);
	//}
	//else cout << "No solution!"<<endl; 
}

