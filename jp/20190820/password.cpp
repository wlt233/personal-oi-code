#include <iostream>
#include <algorithm>
using namespace std;

int n, key;
int a[41];
int ans = 0;


int sum = 0;

int dfs(int now)
{
    for (int i = now; i <= n; i++)
        if (sum + a[i] <= key)
        {
            sum += a[i];
            if (sum == key)
            {
                ans++;
            }
            else dfs(i + 1);
            sum -= a[i];
        }

}


int cmp (const void * a, const void * b)
{
   return ( *(int*)a < *(int*)b );
}



int main()
{
    //freopen("password.in","r",stdin);
    //freopen("password.out","w",stdout);
    cin >> n >> key;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t > key)
        {
            n--;
            i--;
        }
        else if (t == key)
        {
            n--;
            i--;
            ans++;
        }
        else a[i] = t;
    }

    qsort(a + 1, n, sizeof(int), cmp);

    dfs(1);

    //for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << ans;
    
    //fclose(stdin);
    //fclose(stdout);
}



/*
6 3
2 1 3 5 1 2 
5 2
1 1 1 2 2
*/