#include <iostream>

using namespace std;

int xy[505][505]; //0 - 400

int main()
{
    int n, x, y, x0, y0, ans = 0;
    cin >> n;
    cin >> x >> y;
    int t = x;
    x += 200;
    y += 200;
    xy[x][y]++;
    x0 = x;
    y0 = y;
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> y;
        x += 200;
        y += 200;
        xy[x][y]++;
        
        if (y0 == y)
        {
            if (x0 > x)
            {
                for (int j = x + 1; j < x0 ; j++)
                    xy[j][y] = 2;
            }
            else 
            {
                for (int j = x0 + 1; j < x ; j++)
                    xy[j][y] = 2;
            }
        }
        x0 = x;
        y0 = y;
    }



    for (int li = t; li <= 399; li++)
    {
        int x1 = li, x2 = li + 1;
        int a = 0;
        while(a < 400)
        {
            a++;                                    //  x1,a   x1,b
            if (xy[x1][a] != 0 && xy[x2][a] != 0)   //  x2,a   x2,b
            {
                int b = a + 1;
                while (xy[x1][b] == 0 || xy[x2][b] == 0)
                    b++;
                if (xy[x1][b] != 0 && xy[x2][b] != 0)
                {

  for (int i = 199; i <= 230; i++)         // xy[x][y]  \ y 0 1 2 list
    {                                        //           x      
        for (int j = 199; j <= 230; j++)     //           0
            cout << xy[i][j] << ' ';         //           1
        cout << endl;                        //          raw
    }

                     ans += b - a;
                    xy[x1][a]--; xy[x2][a]--; xy[x1][b]--; xy[x2][b]--; 
                }
               
            }
        }
    }
    cout << ans << endl;


    /*
    for (int i = 199; i <= 210; i++)         // xy[x][y]  \ y 0 1 2 list
    {                                        //           x      
        for (int j = 199; j <= 210; j++)     //           0
            cout << xy[i][j] << ' ';         //           1
        cout << endl;                        //          raw
    }
    */
}


/*
12
0 0
3 0
3 1
2 1
2 2
3 2
3 3
0 3
0 2
1 2
1 1
0 1
*/