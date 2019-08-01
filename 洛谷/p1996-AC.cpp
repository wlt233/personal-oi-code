#include<iostream>
using namespace std;

#define MAXN 10000
int queue[MAXN];
int head = 0, tail = 0;

void push(int x)
{
    tail++;
    if (tail == MAXN) tail = 0;
    if (tail == head) cout << "queue overflow";
    queue[tail] = x;
}

void pop()
{
    head++;
}

int top()
{
    return queue[head + 1];
}


int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)push(i);
    while (tail - head > 1)
    {
        for (int j = 1; j <= m - 1; j++)
        {
            push(top());
            pop();
        }
        cout << top() << ' ';
        pop();
    }
    if (top() != 0)cout << top();
}