#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct p{
    int skill, sex;
    int before, delta;
    bool ke, used;
    int next;
}dance[100001];


int n, ans = 0;
int ansl[2][50000];

int main()
{
    //freopen("DancingLessons.in","r",stdin);
    //freopen("DancingLessons.out","w",stdout);
    cin >> n;
    char t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (t == 'B') dance[i].sex = 1;
        else dance[i].sex = 2;
        dance[i].before = i - 1;
        dance[i].next = i + 1;
        dance[i].used = 0;
    }
    for (int i = 1; i <= n; i++) 
    {
        cin >> dance[i].skill;
        dance[i].delta = abs(dance[i - 1].skill - dance[i].skill);
        dance[i].ke = (dance[i].sex != dance[i - 1].sex);
    }
    dance[0].used = 1;
    int f = 0;
    while (f == 0)
    {
        int mindelta = 0x7fff; 
        int deltap;
        for (int i = 1; i <= n; i++)
        {
            if (dance[i].delta < mindelta && dance[i].ke && !dance[i].used && !dance[dance[i].before].used && dance[i].before != 0) 
            {
                mindelta = dance[i].delta;
                dance[i].delta = 0x7fff;
                dance[dance[i].before].delta = 0x7fff;
                deltap = i;

            }
        }
        
        if (mindelta != 0x7fff)
        {
            //cout << "t " << dance[dance[deltap].before].before << dance[deltap].next << endl;
            dance[dance[deltap].next].before = dance[dance[deltap].before].before;
            dance[dance[dance[deltap].before].before].next = dance[deltap].next;
            dance[dance[deltap].next].delta = dance[dance[deltap].next].skill - dance[dance[dance[deltap].next].before].skill;
            dance[dance[deltap].next].ke = (dance[dance[deltap].next].sex != dance[dance[dance[deltap].next].before].sex);
            dance[dance[deltap].before].used = 1; dance[deltap].used = 1;
            ans++;
            ansl[0][ans] = dance[deltap].before;
            ansl[1][ans] = deltap;
        }
        else (f = 1);
    
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++)
    {
        cout << ansl[0][i] << ' ' << ansl[1][i] << endl;
    } 

    //fclose(stdin);
    //fclose(stdout);

    //for (int i = 1; i <= n; i++) cout << dance[i].sex << dance[i].skill << dance[i].delta << dance[i].ke <<endl;
}


/*
4
BGBG
4 2 4 3

6
BGGGGB
1 1 4 5 1 4

4
BBBB
1 9 1 9

4
GBGB
5 1 1 4


7
BBBGGBG
1 2 3 4 5 6 7
*/
