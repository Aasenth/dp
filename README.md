# dp
## 总结：
dp问题是算法中比较难的一类题目，他没有固定的模板，只能用这类的思想取分析推导  
#### dp问题可以从俩个角度去分析：一是状态表示，包括用几维的数组来表示，数组表示的是什么集合，以及数组中存储的是什么属性；二是状态计算，可以对集合进行划分，进而分析出状态转移方程去帮助求解  
#### dp问题中用上一状态来计算当前状态时，若用到k-1操作，循环下标建议从1开始，可以防止越界  
######  动态规划的时间复杂度为： 状态数量* 计算每一个状态需要的时间
### 笔记
1.01背包
f[j]=max(f[j],f[j-v[i]]+w[i]);// 一维   
f[i,j]=max(f[i][j],f[i-1][j-v[i]+w[i]])  //二维   
2.完全背包  
转态转移方程的优化推导：  
f[i , j ] = max( f[i-1,j] , f[i-1,j-v]+w ,  f[i-1,j-2*v]+2*w , f[i-1,j-3*v]+3*w , .....)  
f[i , j-v]= max(            f[i-1,j-v]   ,  f[i-1,j-2*v] + w , f[i-1,j-3*v]+2*w , .....)  
由上两式，可得出如下递推关系：   
                        f[i][j]=max(f[i,j-v]+w , f[i-1][j])  
3多重背包  
f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);  

4.多重背包优化  
可以采用”打包”的办法,二进制方法将多重背包优化为01背包  
每一组物品划分为1,2,4……2^(k-1),这些数的和可以表示0~(2^k)-1,  
S件物品，在这些分组基础上再加c,c的取值范围为2^（k-1）~2^k  
这样二进制划分后的数与c，这些数和可以表示0-S任何数  
5.数字三角形  
集合划分：划分为从左上方来的和右上方来的路径  
f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);  
注意：在初始化二维数组时，应将数组左右俩端一同初始化为负无穷；  
6.最长上升子序列  
集合：以第i个数结尾的子序列  
划分：以第i-1个数划分  
if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);  



