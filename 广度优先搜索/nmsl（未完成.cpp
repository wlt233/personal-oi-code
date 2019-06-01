#include<bits/stdc++.h>
using namespace std;
struct node{
	int a[30][2],b[9][9]; 
	int pnt,dep; 
}data[1000000],now,tempnode;

int dx[8] = {1,2,2,1,-1,-2,-2,-1},dy[8] = {-2,-1,1,2,2,1,-1,-2};
int head = 0, tail = 1; 
int nodedep[30];
int reptime = 0, tran = 0;



void print(int i)
{
	cout << "node:" << i << ' '<< "parent:" << data[i].pnt << ' '  << "depth:" << data[i].dep << endl;
	for (int k = 1; k <= data[i].dep; k++)
		cout << data[i].a[k][0] << ' ' ;
	cout << endl;
	for (int k = 1; k <= data[i].dep; k++)
		cout << data[i].a[k][1] << ' ' ;
	cout << endl;
	for (int k = 1; k <= data[i].dep; k++)
		cout << nodedep[k] << ' ' ;
	cout << endl;
	for (int j = 1;j<=8;j++)
	{
		for (int k = 1;k<=8;k++)
			cout << data[i].b[j][k] << ' ' ;
		cout << endl;
	}
}


bool inmap(int x,int y,int move)
{
	if (x+dx[move] <= 8 && x+dx[move] >= 1 && y+dy[move] <= 8 && y+dy[move] >= 1) return true;
	else return false;
}

int trans2();
bool repeat()
{	
	int tempx = tempnode.a[tempnode.dep][0], tempy = tempnode.a[tempnode.dep][1];
	for (int i = 1; i < tempnode.dep; i++)	
		if (tempnode.a[i][0] == tempx && tempnode.a[i][1] == tempy) return true;
	for (int i = nodedep[tempnode.dep-1]; i < nodedep[tempnode.dep]; i++)
	{
		int f = 0;
		for (int j = 1; j <= tempnode.dep; j++)
			for (int k = 0; k <= 1; k++)
				if (data[i].a[j][k] != tempnode.a[j][k]) f = 1;
		if (f == 0) 
		{
			reptime++;
			if (reptime >= 4)//阈值3 
			{
				reptime = 0;
				trans2();
			}
			return true;
		}
	}				
	return false;	 
}


bool ifsucc()
{
	for (int j = 1;j<=8;j++)
		for (int k = 1;k<=8;k++)
			if (tempnode.b[j][k] == 0) return false;
	return true;
}

int trans()
{
	for (int j = 8; j <= 1; j--)
		for (int k = 8; k <= 1; k--)
			if (now.b[j][k] == 0) 
			{
				now.a[now.dep][0] = j;
				now.a[now.dep][1] = k;
				data[head] = now;
				head--;
				return 0;
			}
} 
int trans2()
{
	tran = 50;
	for (int j = 1; j <= 8; j++)
		for (int k = 1; k <= 8; k++)
			if (now.b[j][k] == 0) 
			{
				now.a[now.dep][0] = j;
				now.a[now.dep][1] = k;
				data[head] = now;
				return 0;
			}
} 


int bfs()
{
	do{
		head++;
		now = data[head];
		int nowx = now.a[now.dep][0], nowy = now.a[now.dep][1];
		tran=0;
		for(int move = 0; move < 8; move++)
		{
			if (inmap(nowx,nowy,move))
			{
				tail++;tran++;
				tempnode = now;
				int setx = nowx+dx[move], sety = nowy+dy[move];
				tempnode.dep++; 
				nodedep[tempnode.dep] = tail;
				tempnode.pnt = head;
				tempnode.a[tempnode.dep][0] = setx;
				tempnode.a[tempnode.dep][1] = sety;
				int rephold = 0;
				for(int move2 = 0; move2 < 8; move2++)
					if (inmap(setx,sety,move2))
					{
						if(tempnode.b[setx+dx[move2]][sety+dy[move2]] == 0)tempnode.b[setx+dx[move2]][sety+dy[move2]] = 1; //tempnode.dep;
						else rephold++;
					}
				data[tail] = tempnode;
				//print(tail);
				if (repeat() 
				|| (rephold >= 2 &&tempnode.dep <= 4) 
				|| (rephold >= 3 &&tempnode.dep <= 8) 
				|| (rephold >= 4 &&tempnode.dep <= 10) 
				|| (rephold >= 5 &&tempnode.dep <= 12) 
				|| (rephold >= 7 &&tempnode.dep <= 15) 
				|| (rephold >= 8 &&tempnode.dep <= 20))//阈值1 
				{
					tail--;
					tran--; 
					nodedep[tempnode.dep] = nodedep[tempnode.dep]-1;
				}
				else if (ifsucc()) return 1;
			}
		}
		if (tran <= 1) trans();//阈值2
		for (int k = 1; k <= data[head].dep+1; k++)
			cout << nodedep[k] << ' ' ;
		cout << endl;
	} while (head < tail && data[tail].dep <= 20);
	return 0;
}


void out()
{
	cout<<"!!!!!!!!!!!!!!";
	int dep = data[tail].dep,pnt = tail;
	int ans[dep];
	ans[0] = tail;
	for (int i = 1;i < dep;i++)
	{
		pnt = data[pnt].pnt;
		ans[i] = pnt;
	}
	for (int i = dep-1;i >= 0;i--) print(ans[i]);
}


int main()
{
	data[1].a[0][0] = 1; data[1].a[0][1] = 1;
	data[1].pnt = 0;
	data[1].dep = 0;

	if (bfs() == 1) out();
	else cout << "无解！"; 
	
}


