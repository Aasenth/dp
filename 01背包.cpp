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
        for (int j = m; j >= v[i]; j--)        //����
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            //��ά  f[i,j]=max(f[i][j],f[i-1][j-v[i]+w[i])

            //�������for(int j=v[i];j<=m;j++)
            //j-v[i]<j,j���Ǵ�С����ģ�����f[j-v[i]]��ǰ�汻�������j-v[i]��ʾ����f[i][j-v[i]  
            //����Ļ�,j�Ӵ�С,j-v[i]��û�б����㣬���Ի���ʾ����f[i-1][j-v[i];
        }
    cout << f[m] << endl;
    return 0;
}
