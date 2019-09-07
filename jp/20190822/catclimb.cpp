#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define ll long long

int n, w;
int cat[20];

int main()
{
    //freopen("shirt.in","r",stdin);
	//freopen("shirt.out","w",stdout);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> cat[i];
    sort(cat + 1, cat + n + 1);
    
    for (int i = 1; i <= n; i++) cout << cat[i] << ' ';
   
    //fclose(stdin);
    //fclose(stdout);


}