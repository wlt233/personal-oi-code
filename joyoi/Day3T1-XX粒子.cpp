#include<bits/stdc++.h>
using namespace std;
int main()
{
	char xx[200024];
    cin >> xx;
    int l = strlen(xx);
    //cout << xx << l << endl;
    for (int i = 0; i < l; i++)
    {
        int a = i;
        int b = a + 1;
        if (xx[a] == xx[b])
        {
            xx[a] = 'N';
            xx[b] = 'N';
            if (a - 1 >= 0) a--;
            if (b + 1 < l) b++;
           
            while (xx[a] == xx[b] && xx[a] != 'N')
            {
                xx[a] = 'N';
                xx[b] = 'N';
                if (a - 1 >= 0) a--;
                if (b + 1 < l) b++;
            }

        }
    }
    //cout << xx << l << endl;

    for (int i = 0; i < l; i++)
    {
        if (xx[i] != 'N')cout<<xx[i];
    }




    return 0;
} 
