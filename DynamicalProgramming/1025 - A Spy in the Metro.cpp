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
const int maxn = 55;
const int maxt = 205;
const int INF = 1000000000;

int mtime[maxn];  // n-1 个数，表示从i到i+1车站的所需时间，1<=i<=n-1
int has_train[maxt][maxn][2];  // has_train[i][j][k]表示在状态
// 第i时刻在j车站是否有往左出发的车辆(k=1)；k=0则是往右出发的车

// 时间是单向流逝的，是一个天然的“序”。影响到决策只有当前时间和当前所处车站。
//状态定义，表示i时刻在车站j所需等待的最少时间,i,j都是按序变化的
int dp[maxt][maxn];
// 在状态dp[i][j] 有三种决策：
// 决策1： 等1个单位时间
// 决策2： 搭乘往右开的车（如果有）
// 决策3： 搭乘往左开的车（如果有）

int main() {
  //  freopen(
  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
  //      "r", stdin);
  //  freopen(
  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/"
  //      "out",
  //      "w", stdout);

  int T, n, kcase;
  //  cin >> T;
  kcase = 1;
  while (cin >> n >> T && n) {
    int M1, M2, d;
    for (int i = 1; i <= n - 1; i++) {
      cin >> mtime[i];
    }

    memset(has_train, 0, sizeof(has_train));
    cin >> M1;  //输入从车站1出发的车辆个数
    while (M1--) {
      cin >> d;
      //计算某一辆从车站1出发的车到达其余各站的时间
      for (int j = 1; j <= n - 1; j++) {
        if (d <= T) {
          has_train[d][j][0] = 1;
        }
        d += mtime[j];
      }
    }

    cin >> M2;  //输入从车站n出发的车辆个数
    while (M2--) {
      cin >> d;
      //计算某一辆从车站n出发的车到达其余各站的时间
      for (int j = n - 1; j >= 1; j--) {
        if (d <= T) {
          has_train[d][j + 1][1] = 1;
        }
        d += mtime[j];
      }
    }

    //边界条件
    for (int i = 1; i <= n - 1; i++) {
      dp[T][i] = INF;  //初始化等待时间为无穷大
    }
    dp[T][n] = 0;  //由于在T时刻n车站与间谍会面，因此等待时间为0

    for (int i = T - 1; i >= 0; i--) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = dp[i + 1][j] + 1;  //等待一个时间单位
        if (j < n && has_train[i][j][0] && i + mtime[j] <= T) {
          dp[i][j] = min(dp[i][j], dp[i + mtime[j]][j + 1]);  //右
        }

        if (j > 1 && has_train[i][j][1] && i + mtime[j - 1] <= T) {
          dp[i][j] = min(dp[i][j], dp[i + mtime[j - 1]][j - 1]);  //左
        }
      }
    }
    cout << "Case Number " << kcase++ << ": ";
    if (dp[0][1] >= INF) {
      cout << "impossible\n";
    } else {
      cout << dp[0][1] << endl;
    }
  }
  return 0;
}
