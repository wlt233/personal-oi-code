#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAXN 2050
int tree[MAXN];
int n, f;
string str;

void post_order(int x)
{

    if (x * 2 <= f) post_order(x * 2);
    if (x * 2 + 1 <= f) post_order(x * 2 + 1);
    if(!tree[x])
    {
        if (tree[x * 2] == 1 && tree[x * 2 + 1] == 1) tree[x] = 1;
        else if (tree[x * 2] == 2 && tree[x * 2 + 1] == 2) tree[x] = 2;
        else tree[x] = 3;
    }
    if (tree[x] == 1) cout << 'B';
    else if (tree[x] == 2) cout << 'I';
    else cout << 'F';
}

int main()
{

    cin >> n;
    f = (1 << (n + 1)) - 1;
    //cout << f;
    cin >> str;
    for (int i = 1; i <= 1 << n; i++)
    {
        //c = getchar();     
        //这里我本来用的事getchar一个个读的
        //问题是本地验证都对然后洛谷无限爆零
        //无奈只好用string了
        tree[i - 1 + (1 << n)] = str[i - 1] - '0' + 1; 
    }
    post_order(1);
    return 0;
}

/*

00B 11I 01F
1   2   3

3
10001011

*/
