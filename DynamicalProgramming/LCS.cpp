//// LIS 最长上升子序列的问题
//// input
//// 1
//// 5
//// 8 3 10 5 9
//// 4
//// 1 3 10
//// out
//// Case #1: 2
//// O(nm)
//#include <algorithm>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <set>
//#include <string>
//#include <vector>
// using namespace std;
//#define LL long long
// const int maxn = 100;
// int numsA[maxn];
// int numsB[maxn];
//// d[i][j] 表示numsA 前i个数和numsB前j个数组成的最长公共子序列
// int d[maxn][maxn];
//
// int main() {
//  freopen(
//      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//      "r", stdin);
//  freopen(
//      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/"
//      "out",
//      "w", stdout);
//
//  int T, t;
//  cin >> T;
//  t = 1;
//  LL ans;
//  int n, m;
//  while (T--) {
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//      cin >> numsA[i];
//    }
//    cin >> m;
//    for (int i = 1; i <= m; i++) {
//      cin >> numsB[i];
//    }
//    d[0][0] = 0;
//    for (int i = 1; i <= n; i++) {
//      d[i][0] = 0;
//    }
//    for (int j = 1; j <= m; j++) {
//      d[0][j] = 0;
//    }
//
//    for (int i = 1; i <= n; i++) {
//      for (int j = 1; j <= m; j++) {
//        // 状态转移方程
//        if (numsA[i] == numsB[j]) {
//          d[i][j] = d[i - 1][j - 1] + 1;
//        } else {
//          d[i][j] = max(d[i - 1][j], d[i][j - 1]);
//        }
//      }
//    }
//    ans = d[n][m];
//    printf("Case #%d: %lld\n", t++, ans);
//  }
//  return 0;
//}
