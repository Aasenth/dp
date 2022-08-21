# dp
## 总结：
dp问题是算法中比较难的一类题目，他没有固定的模板，只能用这类的思想取分析推导  
#### dp问题可以从俩个角度去分析：一是状态表示，包括用几维的数组来表示，数组表示的是什么集合，以及数组中存储的是什么属性；二是状态计算，可以对集合进行划分，进而分析出状态转移方程去帮助求解  
#### dp问题中用上一状态来计算当前状态时，若用到k-1操作，循环下标建议从1开始，可以防止越界  
######  动态规划的时间复杂度为： 状态数量* 计算每一个状态需要的时间
## 笔记
### 背包问题
#### 1.01背包
f[j]=max(f[j],f[j-v[i]]+w[i]);// 一维   
f[i,j]=max(f[i][j],f[i-1][j-v[i]+w[i]])  //二维   
二维优化为一维后，二层循环要采用倒序，为了保证计算f]j]时f[j-v[i]]还没有被计算，这样f[j-v[i]]就依然表示的是二维中的f[i-1][j-v[i];  
#### 2.完全背包  
转态转移方程的优化推导：    
f[i , j ] = max( f[i-1,j] , f[i-1,j-v]+w ,  f[i-1,j-2*v]+2*w , f[i-1,j-3*v]+3*w , .....)  
f[i , j-v]= max(            f[i-1,j-v]   ,  f[i-1,j-2*v] + w , f[i-1,j-3*v]+2*w , .....)  
由上两式，可得出递推关系    f[i][j]=max(f[i,j-v]+w , f[i-1][j])  
可以通过01背包的思想再度优化为一维，不同点在于二层循环中为正序，理由同01背包；  
#### 3多重背包  
f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);  

#### 4.多重背包优化  
可以采用”打包”的办法,二进制方法将多重背包优化为01背包  
每一组物品划分为1,2,4……2^(k-1),这些数的和可以表示0~(2^k)-1,  
S件物品，在这些分组基础上再加c,c的取值范围为2^（k-1）~2^k  
这样二进制划分后的数与c，这些数和可以表示0-S任何数  
划分完成后转化为01背包问题  
### 线性dp
#### 5.数字三角形  
集合划分：划分为从左上方来的和右上方来的路径  
数组存储：max  
f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);  
注意：在初始化二维数组时，应将数组左右俩端一同初始化为负无穷；  
#### 6.最长上升子序列  
集合：以第i个数结尾的子序列  
划分：以第i-1个数划分  
if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);  
#### 7.最长公共子序列  
集合：所有A序列的前i个字符与B序列的前j个字符的公共子序列  
数组存储：max  
划分：以a[i]与b[j]是否包含在子序列当中划分为四个集合（00,01,10,11）  
f[i][j]=max(f[i-1][j],f[i][j-1]);
if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
### 计数类dp
#### 8.整数划分
1.完全背包解法  
转化为：把1,2,3, … n分别看做n个物体的体积，这n个物体均无使用次数限制，问恰好能装满总体积为n的背包的总方案数  
2.其他解法  
集合：总合为i,个数为j的方案集合  
数组存储：数量  
划分：方案中最小值是不是1来划分  
f[i][j] = (f[i - 1][j - 1] + f[i - j][j])
### 数位统计dp
#### 9.计数问题
数位统计问题偏向于数奥问题，一定要分情况讨论  




