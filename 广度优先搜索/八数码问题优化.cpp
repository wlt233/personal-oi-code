#include<bits/stdc++.h>
using namespace std;
struct node{
	int a[4][4]; 
	int x,y;//坐标 
	int pnt,dep,cost; //父节点 深度 权重 
}data[1000],now,tempnode;//建立数据库  

int dx[4] = {0,1,0,-1},dy[4] = {-1,0,1,0};
int head = 0, tail = 1; 
int succ[4][4] = {{0,0,0,0},{0,1,2,3},{0,8,0,4},{0,7,6,5}};

//输出函数 
void print(int i)
{
	cout << "node:" << i << ' ' << "parent:" << data[i].pnt << ' '  << "depth:" << data[i].dep << endl;
	for (int j = 1;j<=3;j++)
	{
		for (int k = 1;k<=3;k++)
			cout << data[i].a[j][k] << ' ' ;
		cout << endl;
	}
}


bool gothere(int move)
{
	if (now.x + dx[move] <= 3 && now.x + dx[move] >= 1 && now.y + dy[move] <= 3 && now.y + dy[move] >= 1) return true;
	else return false;
}

bool repeat()
{
	int f = 0;
	for (int i = 1;i < tail;i++)
	{
		int f = 0;
		for (int j = 1;j<=3;j++)
			for (int k = 1;k<=3;k++)
				if (data[i].a[j][k] != tempnode.a[j][k]) f = 1;
		if (f == 0) return true;
	}		
	return false;			

}


bool ifsucc()
{
	int f = 1;
	for (int j = 0;j<=3;j++)
		for (int k = 0;k<=3;k++)
			if (tempnode.a[j][k] != succ[j][k]) f = 0;
	if (f == 1) return true;
	else return false;
}


void calcost()
{
	int cost = 9;
	for (int j = 1;j<=3;j++)
			for (int k = 1;k<=3;k++)
				if (succ[j][k] == tempnode.a[j][k]) cost--;
	cost += tempnode.dep;
	tempnode.cost = cost;
	
}


void check()
{
	if (tempnode.cost < data[head+1].cost)
	{
		for (int i = tail; i >= head + 1; i--)
			data[i+1] = data[i];
		data[head+1] = tempnode;
	} 		
	else if (tempnode.cost > 6) tail--;//加了这行优化 tail就是7，不加就11 
		
	
}


int bfs()
{
	do{
		head++;
		now = data[head];
		for(int move = 0;move < 4;move ++)
		{
			if (gothere(move))
			{
				tail++;
				tempnode = now;
				tempnode.a[tempnode.y][tempnode.x] = tempnode.a[tempnode.y + dy[move]][tempnode.x + dx[move]];
				tempnode.x = tempnode.x + dx[move]; 
				tempnode.y = tempnode.y + dy[move]; 
				tempnode.a[tempnode.y][tempnode.x] = 0;
				tempnode.dep ++;
				tempnode.pnt = head;
				calcost();
				data[tail] = tempnode;
				if (repeat())tail--;
				else if (ifsucc()) return 1;
				else check();
				//print(tail);
			}
		}
	} while (head < tail);
	return 0;
}


void out()
{
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
	int temp[4][4] = {{0,0,0,0},{0,2,8,3},{0,1,6,4},{0,7,0,5}};
	for (int j = 0;j<=3;j++)
		for (int k = 0;k<=3;k++)
			data[1].a[j][k] = temp[j][k];
	data[1].x = 2;
	data[1].y = 3;
	data[1].pnt = 0;
	data[1].dep = 0;//初始状态入队 
	print(1);
	
	if (bfs() == 1) out();
	else cout << "无解！"; 
	
}


/*
//写入节点表格（曲线救国 （顺便把其他参数也写了 
void write(int i, int x, int y, int pnt, int dep)
{
	for (int j = 0;j<=3;j++)
		for (int k = 0;k<=3;k++)
			data[i].a[j][k] = temp[j][k];
	data[i].x = x;
	data[i].y = y;
	data[i].pnt = pnt;
	data[i].dep = dep;
}
*/

