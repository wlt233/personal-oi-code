#include <iostream>

using namespace std;

int rc[1005][1005]; //0 - 400
int rc2[1005][1005];


int ans = 0, fans = 0;

int main()
{
    int r, c;
    char p;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            {
                cin >> p;
                if (p == '#')
                {
                    rc[i][j] = 1;
                    rc2[i][j] = 1;
                }
            }
    

 


    int a = 1;
    for (int a = 1; a <= r; a++)
    {
        int b = 1;
        for (int b = 1; b <= c; b++)
        {
            if (rc[a][b] == 1)
            {
                int c = a;
                while (rc[c + 1][b] == 1) c++;
                int wi = c - a + 1;
                int d = b;
                while (rc[a][d + 1] == 1) d++;
                int lo = d - b + 1;
                //cout << "lo=" <<lo<<endl;
                //cout << "wi=" <<wi<<endl;
                for (int k = b; k <= d; k++)
                {
                    c = a;
                    while (rc2[c + 1][k] == 1)
                        c++;
                    if (c - a + 1 != wi) fans = 1;
                }

                for (int k = d; k >= b; k--)
                {
                    c = a;
                    while (rc2[c + 1][k] == 1)
                        c++;
                    if (c - a + 1 != wi) fans = 1;
                }

                for (int k = c; k >= a; k--)
                {
                    d = b;
                    rc[k][d] = 0;
                    while (rc2[k][d + 1] == 1)
                        d++;
                    if (d - b + 1 != lo) fans = 1;
                }



                for (int k = a; k <= c; k++)
                {
                    d = b;
                    rc[k][d] = 0;
                    while (rc2[k][d + 1] == 1)
                    {
                        d++;
                        rc[k][d] = 0;
                    }
                    if (d - b + 1 != lo) fans = 1;
                }
                
                



                ans++;
                b = d + 1;
            }
        }
    }
    if (fans == 1) cout << "Bad placement.";
    else cout << "There are " << ans << " ships." << endl;
    /*
    for (int i = 1; i <= 10; i++)         // xy[x][y]  \ y 0 1 2 list
    {                                        //           x      
        for (int j = 1; j <= 10; j++)     //           0
            cout << rc[i][j] << ' ';         //           1
        cout << endl;                        //          raw
    }
    */
}


/*

6 8
......##
##.....#
##.....#
.......#
#......#
#..#...#

6 8
.....#.#
##.....#
##.....#
.......#
#......#
#..#...#

6 8
.....###
.....#.#
.....###
........
........
........

6 6
.....#
##...#
##...#
..#..#
.....#
######


*/