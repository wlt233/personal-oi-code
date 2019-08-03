#include<iostream>
#include<stack>
#include<cstdio> 

using namespace std;

#define MAXN 1001
stack<int> s;



int main()
{
    char ch;
    int sum = 0; //sum在while循环外定义
    while ((ch = getchar()) != '@')
    {
        //cout << ch << endl;
        if (ch >= '0' && ch <= '9')
        {
            sum = sum * 10 + ch - '0';
            //cout << "sum = " << sum << endl;
        }
        else if (ch == '.')
        {
            s.push(sum);
            sum = 0;
        }
        else if (ch != '@')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            //cout << a << ' ' << b << endl;
            switch (ch)
            {
                case '+': s.push(a + b); break;
                case '-': s.push(b - a); break; //#
                case '*': s.push(a * b); break;
                case '/': s.push(b / a); break; //这两处必须注意是b在前a在后
            }
        } 
    }
    cout << s.top();
}
