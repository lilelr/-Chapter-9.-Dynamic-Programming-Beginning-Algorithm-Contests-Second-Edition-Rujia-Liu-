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
// const int maxn = 100 + 5;
// int n;
// int grid[maxn][maxn];  //邻接矩阵
// int depths[maxn];      //各个节点的嵌套矩阵深度
//
////矩阵定义
// struct Mretrangle {
//  int width;
//  int height;
//  Mretrangle() {}
//
//  Mretrangle(int x, int y) : width(x), height(y) {}
//  //自定义嵌套关系
//  bool operator<(const Mretrangle& b) const {
//    if (width < b.width && height < b.height) {
//      return true;
//    }
//
//    if (width < b.height && height < b.width) {
//      return true;
//    }
//
//    return false;
//  }
//
//} m_retrangles[maxn];
//
////动态规划和深度优先搜索
// int dp(int i) {
//  int& ans = depths[i];
//  if (ans > 0) {
//    return ans;
//  }
//  ans = 1;
//  for (int j = 0; j < n; j++) {
//    if (grid[i][j]) {
//      ans = max(ans, dp(j) + 1);
//    }
//  }
//  return ans;
//}
//
////打印字典序最小的路径
// void print_path(int i, bool flag) {
//  if (!flag) {
//    cout << "->" << i;
//  }
//  for (int j = 0; j < n; j++) {
//    if (grid[i][j] && depths[i] == depths[j] + 1) {
//      print_path(j, false);
//      break;
//    }
//  }
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
//
//  int T, t;
//  cin >> T;
//  t = 1;
//  int ans;
//  while (T--) {
//    cin >> n;
//    ans = 0;
//    int x, y;
//    memset(grid, 0, sizeof(grid));
//    for (int i = 0; i < n; i++) {
//      cin >> x >> y;
//      m_retrangles[i] = Mretrangle(x, y);
//    }
//    //构造图
//    for (int i = 0; i < n; i++) {
//      for (int j = 0; j < n; j++) {
//        if (j != i) {
//          if (m_retrangles[i] < m_retrangles[j]) {
//            grid[i][j] = 1;  //构造边
//          }
//        }
//      }
//    }
//
//    //    for (int i = 0; i < n; i++) {
//    //      for (int j = 0; j < n; j++) {
//    //        if (grid[i][j]) {
//    //          cout << i << "->" << j << " " << grid[i][j] << endl;
//    //        }
//    //      }
//    //    }
//
//    memset(depths, 0, sizeof(depths));
//    //记录起点
//    int first = -1;
//    for (int i = 0; i < n; i++) {
//      depths[i] = dp(i);
//      if (ans < depths[i]) {
//        ans = depths[i];
//        first = i;
//      }
//    }
//    cout << first;
//    //打印路径
//    print_path(first, true);
//    cout << endl;
//    //    cout << endl;
//    printf("Case #%d: %d\n", t++, ans);
//  }
//  return 0;
//}
