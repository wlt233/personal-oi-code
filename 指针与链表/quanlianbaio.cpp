#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	node *next;
};
node *head,*p,*q;
int x;

void create(int l)
{
	head = new node;
	p = head;
	for (int j=1;j<l;j++)
	{
		cin >> x;
		p -> x = x;
		q = new node;
		p -> next = q;
		q -> next = NULL;
		p = q;
	}
	cin >> x;
	p -> x = x;
	p -> next = head;
}

void ls(int l)
{
	p = head;
	for (int j=1;j<=l;j++)
	{
		cout << p -> x << endl;
		p = p -> next; 
	
	}
	
}

void del(int i)
{
	node *p,*s;
	int j=1;
	p = head;
	while((p -> next != NULL)&&(j<i-1))
	{
		p = p -> next;
		j++;
	}
	if (p -> next == NULL) cout << "no this position!";
	else
	{
		s = p -> next;
		p -> next = p -> next -> next;
	}
}

int main()
{
	int l,y;
	cin >> l;
	create(l);
	ls(l);
	cin >> y;
	del(y);
	ls(l-1);
}
