//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=848&page=show_problem&problem=4504
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
//using namespace std;
//#define LL long long
//const int maxn = 22;
//const int INF = 1000000;
//int n, m, cherries;
//int grid[maxn][maxn];
//int mar[maxn][maxn][maxn][maxn];
//
//int calculate(int u, int d, int l, int r) {
//  int count = 0;
//  for (int i = u; i <= d; i++) {
//    for (int j = l; j <= r; j++) {
//      count += grid[i][j];
//      if (count >= 2) {
//        return 2;
//      }
//    }
//  }
//  return 0;
//}
//
//int dfs(int u, int d, int l, int r) {
//  if (u > d || l > r) {
//    return 0;
//  }
//  int count = calculate(u, d, l, r);
//  if (count == 0) {
//    mar[u][d][l][r] = 0;
//    return 0;
//  } else {
//    mar[u][d][l][r] = INF;
//    int &ans = mar[u][d][l][r];
//    int ls = r - l + 1;
//    int ss = d - u + 1;
//    for (int i = u; i < d; i++) {
//      ans = min(ans, dfs(u, i, l, r) + dfs(i + 1, d, l, r) + ls);
//      //      cout << ans << endl;
//    }
//    for (int j = l; j < r; j++) {
//      ans = min(ans, dfs(u, d, l, j) + dfs(u, d, j + 1, r) + ss);
//      //      cout << ans << endl;
//    }
//  }
//  //  cout << mar[u][d][l][r] << endl;
//  return mar[u][d][l][r];
//}
//
//int main() {
//  //  freopen(
//  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//  //      "r", stdin);
//  //  freopen("/Users/yuxiao/XcodeProject/DynamicalProgramming/"
//  //          "DynamicalProgramming/out",
//  //          "w", stdout);
//  int T, t;
//  cin >> T;
//  t = 1;
//  while (T--) {
//    cin >> n >> m >> cherries;
//    //    memset(mar, 1000, sizeof(mar));
//    for (int i = 0; i < n; i++) {
//      for (int j = 0; j < m; j++) {
//        grid[i][j] = 0;
//      }
//    }
//
//    for (int i = 0; i < cherries; i++) {
//      int x, y;
//      cin >> x >> y;
//      grid[--x][--y] = 1;
//    }
//    int res = dfs(0, n - 1, 0, m - 1);
//    cout << "Case " << t++ << ": " << res << endl;
//  }
//  return 0;
//}
