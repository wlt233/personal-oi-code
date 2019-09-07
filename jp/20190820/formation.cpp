#include <iostream>
#include <algorithm>
using namespace std;

int a[50001], b[50001], c[50001], n;


int main()
{
    //freopen("formation.in","r",stdin);
    //freopen("formation.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int in;
    for (int i = 1; i <= n; i++) 
    {
        cin >> in;
        b[i] = a[in];
    }
    
    c[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int nowmax = 0;
        for (int j = 1; j < i; j++)
            if (b[i] > b[j])
                if (nowmax < c[j]) nowmax = c[j];
        c[i] = nowmax + 1; 
    }
    int maxans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] > maxans) maxans = c[i];
    }
    cout << maxans << endl;
    
    //fclose(stdin);
    //fclose(stdout);
}

