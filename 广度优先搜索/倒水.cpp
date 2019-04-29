#include<bits/stdc++.h>
using namespace std;


struct node{
	int water[4];
	int pnt,dep;
}data[100],now,temp;
int capa[4] = {0,80,50,30}; 
int head = 0, tail = 1;

bool repeat()
{
	for (int i = 1;i < tail;i++)
		if (data[i].water[1] == temp.water[1] && data[i].water[2] == temp.water[2]) return true;
	return false;
}

int bfs()
{
	do{ 
		head++;
		now = data[head];
		//cout <<"now" <<' '<<now.water[1] << ' ' << now.water[2] << ' ' << now.water[3] << endl;
		for (int i = 1;i <= 3;i++)//从i倒 
			for (int j = 1;j <= 3;j++)//倒到j 
				if (now.water[i] > 0 && now.water[j] < capa[j] && i != j)
				{
					tail++;
					temp = now;
					temp.dep++;
					temp.pnt = head;
					if ((capa[j] - temp.water[j]) >= temp.water[i])
					{
						//cout <<"new1b"<<" "<<i<<" "<<temp.water[i]<<" "<<j<<" "<<temp.water[j]<<" "<<endl;
						temp.water[j] += temp.water[i];
						temp.water[i] = 0;
						//cout <<"new1a"<<" "<<i<<" "<<temp.water[i]<<" "<<j<<" "<<temp.water[j]<<" "<<endl;
					}
					else 
					{
						//cout <<"new2b"<<" "<<i<<" "<<temp.water[i]<<" "<<j<<" "<<temp.water[j]<<" "<<endl;
						temp.water[i] -= (capa[j] - temp.water[j]);
						temp.water[j] = capa[j];
						//cout <<"new2a"<<" "<<i<<" "<<temp.water[i]<<" "<<j<<" "<<temp.water[j]<<" "<<endl;
					}
					data[tail] = temp;
					if (repeat()) tail--;
					else if(temp.water[1] == 40 && temp.water[2] == 40) return 1;
				}	
	} while (head < tail);
	return 0;
}

int main()
{
	data[1].water[1] = 80;
	data[1].pnt = 0;
	data[1].dep = 0;
	//cout << data[1].water[1] << ' ' << data[1].water[2] << ' ' << data[1].water[3] << endl;
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
		for (int i = dep-1;i >= 0;i--) cout << data[ans[i]].water[1] << ' ' << data[ans[i]].water[2] << ' ' << data[ans[i]].water[3] << endl;
	}
	else cout << "无解！"<<endl;
}
