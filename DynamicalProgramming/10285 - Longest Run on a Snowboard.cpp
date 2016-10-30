// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=848&problem=1226&mosmsg=Submission+received+with+ID+18282880
// 排序（优先队列） + 动态规划
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define LL long long
const int maxn = 10001;
int r, c;
int dp[maxn][maxn];
int data[maxn][maxn];
struct Item {
  int x;
  int y;
  int h;

  Item(){};
  bool operator<(const Item &b) const {
    if (h < b.h) {
      return true;
    }
    return false;
  }
} grid[maxn];

bool checked(int i, int j) {
  if (i < 0 || i >= r || j < 0 || j >= c) {
    return false;
  }
  return true;
}
int main() {
  //  freopen(
  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
  //      "r", stdin);
  //  freopen("/Users/yuxiao/XcodeProject/DynamicalProgramming/"
  //          "DynamicalProgramming/out",
  //          "w", stdout);

  int T, t;
  cin >> T;
  t = 1;
  int res;
  string name;
  while (T--) {
    cin >> name >> r >> c;
    res = 1;
    int len = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        grid[len].x = i;
        grid[len].y = j;
        cin >> grid[len].h;
        data[i][j] = grid[len].h;
        len++;
      }
    }
    sort(grid, grid + len);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++) {
      int x = grid[i].x;
      int y = grid[i].y;
      int h = grid[i].h;
      int &ans = dp[x][y];
      if (checked(x - 1, y)) {
        if (data[x - 1][y] < h) {
          ans = max(ans, dp[x - 1][y] + 1);
        }
      }
      if (checked(x + 1, y)) {
        if (data[x + 1][y] < h) {
          ans = max(ans, dp[x + 1][y] + 1);
        }
      }
      if (checked(x, y - 1)) {
        if (data[x][y - 1] < h) {
          ans = max(ans, dp[x][y - 1] + 1);
        }
      }
      if (checked(x, y + 1)) {
        if (data[x][y + 1] < h) {
          ans = max(ans, dp[x][y + 1] + 1);
        }
      }

      res = max(res, ans);
    }
    cout << name << ": " << res + 1 << endl;
  }
  return 0;
}
