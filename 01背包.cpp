#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)        //倒序
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            //二维  f[i,j]=max(f[i][j],f[i-1][j-v[i]+w[i])

            //如果正序：for(int j=v[i];j<=m;j++)
            //j-v[i]<j,j又是从小到大的，所以f[j-v[i]]在前面被计算过，j-v[i]表示的是f[i][j-v[i]  
            //倒序的话,j从大到小,j-v[i]还没有被计算，所以还表示的是f[i-1][j-v[i];
        }
    cout << f[m] << endl;
    return 0;
}
