#include<iostream>
#include<algorithm>

using namespace std;

const int N=12010,M=2010; //逐一枚举最大是N*logS(12*1000)
int n,m;
int v[N],w[N];
int f[M];   //体积

int main()
{
    cin>>n>>m;
    //将每一组物品打包成log s组，转化为01背包问题
    int cnt=0;         //分组的组别
    for(int i=1;i<=n;i++)    //i表示对哪件物品分组
    {
        int a,b,s;
        cin>>a>>b>>s;    //体积，价值，数量
        int k=1;        //组内的个数
        while(k<=s)
        {
            cnt++;
            v[cnt]=k*a;    //总体积
            w[cnt]=k*b;    //总价值
            s-=k;
            k*=2;
        }
        if(s>0)   //剩余的那一组
        {
            cnt++;
            v[cnt]=a*s;
            w[cnt]=b*s;
        }
    }
    n=cnt;
    //正式转化为01背包问题
    for(int i=1;i<=n;i++)
     for(int j=m;j>=v[i];j--)
      f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[m];
    return 0;
}
