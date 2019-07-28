#include<iostream>
#include<cstdio>
//#include<stack>
//stack <int> s;
using namespace std;
#define MAXN 200025
int stack[MAXN];
int p = 0;
int c;

void push(int x)
{
    if (p >= MAXN)
        ;//cout << "stack overflow";
    else 
    {
        stack[p] = x;
        p += 1;
    }
}

void pop()
{
    if (p == 0)
        ;//cout << "stack is empty";
    else
        p -= 1;
    
}

int top()
{
    if (p == 0)
    {
        //cout << "stack is empty";
        return -1;
    }
    else 
        return stack[p - 1];
}

int main()
{
    while ((c = getchar()) != '\n')
    {
        if (top() == c)
        {
            pop();
        }
        else
        {
            push(c);
        }
        
    }

    for (int i = 0; i <= p - 1; i++)
        cout << char(stack[i]);
}