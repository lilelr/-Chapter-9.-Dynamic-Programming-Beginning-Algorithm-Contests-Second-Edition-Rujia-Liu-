////多阶段决策问题，多段图的最短路
//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=847&problem=52&mosmsg=Submission+received+with+ID+17994108
////#include <algorithm>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <set>
//#include <string>
//using namespace std;
//#define LL long long
//
//const int maxn = 105;
//const LL INF = 100000000000000;
//int grid[maxn][maxn];
//int m, n;
//LL ans;
//LL dp[maxn][maxn];
//int path[maxn][maxn];
//
//int main() {
//  //  freopen(
//  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//  //      "r", stdin);
//  //  freopen(
//  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/"
//  //      "out",
//  //      "w", stdout);
//  //
//  while (scanf("%d%d", &m, &n) == 2 && m) {
//    ans = INF;
//    for (int i = 0; i < m; i++) {
//      for (int j = 0; j < n; j++) {
//        scanf("%d", &grid[i][j]);
//      }
//    }
//    for (int k = 0; k < m; k++) {
//      dp[k][n - 1] = grid[k][n - 1];
//    }
//
//    int first = 0;
//
//    if (n == 1) {
//      for (int i = 0; i < m; i++) {
//        if (grid[i][0] < ans) {
//          ans = grid[i][0];
//          first = i;
//        }
//      }
//    }
//
//    for (int j = n - 2; j >= 0; j--) {
//      for (int i = 0; i < m; i++) {
//        int directions[3] = {i - 1, i, i + 1};
//        if (i == 0) {
//          directions[0] = m - 1;
//        }
//        if (i == m - 1) {
//          directions[2] = 0;
//        }
//
//        sort(directions, directions + 3);
//
//        int record_row = directions[0];
//        dp[i][j] = INF;
//        for (int k = 0; k < 3; k++) {
//          if (dp[directions[k]][j + 1] + grid[i][j] < dp[i][j]) {
//            dp[i][j] = dp[directions[k]][j + 1] + grid[i][j];
//            record_row = directions[k];
//          }
//        }
//        path[i][j] = record_row;
//
//        if (j == 0) {
//          if (dp[i][j] < ans) {
//            ans = dp[i][j];
//            first = i;
//          }
//        }
//      }
//    }
//    cout << first + 1;
//    int next = first;
//    for (int j = 0; j < n - 1; j++) {
//      cout << " " << path[next][j] + 1;
//      next = path[next][j];
//    }
//    cout << endl;
//    cout << ans << endl;
//  }
//  return 0;
//}
