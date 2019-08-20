#include<iostream>
using namespace std;

int a[501], b[501], n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    b[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int nowmax = 0;
        for (int j = 1; j < i; j++)
            if (a[i] >= a[j])
                if (b[j] > nowmax) nowmax = b[j];
        b[i] = nowmax + 1;
    }


    //Q1
    int maxans = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (b[i] > maxans) maxans = b[i];
        //cout << b[i] <<endl;
    }
    cout << maxans << endl;



}

/*
14
13 7 9 16 38 24 37 18 44 19 21 22 63 15
*/