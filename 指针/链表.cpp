#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	node *next;
};
node *head,*p,*q;
int x;

int main()
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
	
	p = head ;
	while (p -> next != NULL)
	{
		cout << p -> x << endl;
		p = p -> next; 
	}
}
