#include<bits/stdc++.h>
using namespace std;

float dt(int a1, int b1, int a2, int b2)
{
    return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
}

float area(float x, float y, float z)
{
    float p = (x + y + z) / 2;
    return sqrt(p * (p - x) * (p - y) * (p - z));
}


int main()
{
	int n, s, ans = 0;
    int a[100], b[100];
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
            {
                float ta = area(dt(a[i], b[i], a[j], b[j]), dt(a[j], b[j], a[k], b[k]), dt(a[k], b[k], a[i], b[i])); 
                //cout<<ta<<endl;
                if (ta <= s && ta > 0)
                    ans++;
                    
            }
    cout << ans;
	return 0;
} 

/*
5 5
1 1
1 2
2 1
1 99
1 100
 */