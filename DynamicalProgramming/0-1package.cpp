//
//#include <algorithm>
//#include <cmath>
//#include <cstdio>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <set>
//#include <string>
//#include <vector>
// using namespace std;
//#define LL long long
//
//// input
//// 1
//// 3 10
//// 4 3 5
//// 10 1 6
////
//// out
//// Case #1: 16
//
// int n;        // 物品个数
// int cpacity;  //背包总容量
// int ans;      //所求的最大重量
//
// int weights[1005];   //物品的重量数组
// int volumes[1005];   //物品的体积数组
// int dp[1005][1005];  //计算最大重量的动态规划数组
//
// void solve1() {
//  // 法1
//  // dp[i][j]
//  //表示在背包容量为j时，放入第i,i+1,...n个物品时的最大重量
//  // i 逆序枚举，但 j的循环次序是无关重要的
//  for (int i = n; i >= 1; i--) {
//    for (int j = 0; j <= cpacity; j++) {
//      dp[i][j] =
//          (i == n ? 0 : dp[i + 1][j]);  //不放入第一个物品时，dp[i][j]至少等于
//      // dp[i+1][j]
//
//      if (j >= volumes[i]) {
//        //  dp[i + 1][j - volumes[i]] 表示放入背包容量为j -
//        //  volumes[i]，放入第i+1，i+2,..n个物品时的最大重量。
//        dp[i][j] = max(dp[i][j], dp[i + 1][j - volumes[i]] + weights[i]);
//      }
//    }
//  }
//
//  ans = dp[1][cpacity];
//}
//
// void solve2() {
//  // 法1
//  // dp[i][j]
//  //表示在背包容量为j时，放入第1,2,...,i个物品时的最大重量
//  // i 顺序枚举
//
//  for (int i = 1; i <= n; i++) {
//    for (int j = 0; j <= cpacity; j++) {
//      dp[i][j] = (i == 1 ? 0 : dp[i - 1][j]);
//      if (j > volumes[i]) {
//        dp[i][j] = max(dp[i][j], dp[i - 1][j - volumes[i]] + weights[i]);
//      }
//    }
//  }
//  ans = dp[n][cpacity];
//}
//
// void sovle3() {
//  // 紧接solve2 思路，用一维滚动数组节省空间
//  int f[1005];
//  memset(f, 0, sizeof(f));
//  for (int i = 1; i <= n; i++) {
//    for (int j = cpacity; j >= 0; j--) {
//      if (j >= volumes[i]) {
//        f[j] = max(f[j], f[j - volumes[i]] + weights[i]);
//      }
//    }
//  }
//
//  ans = f[cpacity];
//}
//
// int main() {
//  freopen(
//      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//      "r", stdin);
//  freopen(
//      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/"
//      "out",
//      "w", stdout);
//  int T, t;
//  t = 1;
//  cin >> T;
//  while (T--) {
//    ans = 0;
//    memset(dp, 0, sizeof(dp));
//    cin >> n >> cpacity;
//
//    // 注意下标从1开始
//    for (int i = 1; i <= n; i++) {
//      cin >> volumes[i];
//    }
//    for (int i = 1; i <= n; i++) {
//      cin >> weights[i];
//    }
//    //    solve2();
//    sovle3();
//    cout << "Case #" << t++ << ": " << ans << endl;
//  }
//  return 0;
//}
