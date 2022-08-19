//完全背包解法
#include<iostream>
#include<algorithm>

using namespace std;
const int N=1010,M=1e9+7;
int f[N];
int n;

int main()
{
    scanf("%d",&n);
    f[0]=1;       //合为0时，不选也是一种方案
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            f[j]=(f[j]+f[j-i])%M;
    cout<<f[n];
    return 0;
}
//其他解法
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N][N]; //f[i][j]表示合为i，个数为j的集合的数量；

int main()
{
    cin >> n;

    f[1][1] = 1;
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;

    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = (res + f[n][i]) % mod;

    cout << res << endl;

    return 0;
}
