#include<bits/stdc++.h> 
using namespace std;

int n,head = 0,tail = 1;
struct node{
	int front,pnt,dep;
}data[100],now,temp;
int turn[6] = {-5,-3,-1,1,3,5};


bool repeat()
{
	for (int i = 1;i < tail;i++)
		if (data[i].front == temp.front) return true;
	return false;
}


void print(int i)
{
	for (int j = 1;j <= i;j++)cout<<'O';
	for (int j = 1;j <= (n-i);j++)cout<<'@';
	cout<<endl;
}

int bfs()
{
	do {
		head++;
		now = data[head];
		for (int r = 0;r < 6;r++)
			if (now.front + turn[r] <= n && now.front + turn[r] >= 0 && now.front >= (5-r) && (n-now.front) >= r)
			{
				temp = now;
				temp.front += turn[r];
				temp.dep++;
				temp.pnt = head;
				tail++;
				data[tail] = temp;
				if (repeat()) tail--;
				else if(temp.front == 0) return 1;
			}
	} while (head < tail);
	return 0;
}

int main()
{
	cin >> n;
	data[1].front = n;
	data[1].pnt = 0;
	data[1].dep = 0;
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
		for (int i = dep-1;i >= 0;i--) print(data[ans[i]].front);
	}
	else cout << "no solution!"; 
}
