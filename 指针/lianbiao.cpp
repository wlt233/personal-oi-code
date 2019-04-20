#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	node *next;
};
node *head,*p,*q;
int x;

void create()
{
	head = new node;
	p = head;
	cin >> x;
	while(x != -1)
	{
		p -> x = x;
		q = new node;
		p -> next = q;
		q -> next = NULL;
		p = q;
		cin >> x;
	}
}

void ls()
{
	p = head ;
	while (p -> next != NULL)
	{
		cout << p -> x << endl;
		p = p -> next; 
	}
	
}

void del(node *head,int i)
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
	create();
	ls();
	int y;
	cin >> y;
	del(head,y);
}
