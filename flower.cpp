#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a[105]={0};
    int f[105][105];
    int m, n;
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++ )
        cin >> a[i];
    
    for (int i = 1; i <= a[1]; i++)
        f[1][i] = 1;
    
    for (int i =1 ; i <= n; i++)
        f[i][0] = 1;
    
    for (int i = 2; i <= n; i++ )
        for (int j = 1; j <= m; j++ )
            for (int k = 0; (k <= a[i]) && (j >= k); k++)
            {
                f[i][j] += f[i-1][j-k];
                f[i][j] %= 1000007;
            }
    cout << f[n][m] << endl;
    
    return 0;
}
