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
const int maxn = 35;
int n;
int blocks[maxn][3];
int status[maxn][3];

/**
 *  以height_index边为高，以其他两条边围成的矩形为立方体的底，并把它们记录在v[2]数组中
 *
 *  @param v      记录为底的两条边长
 *  @param index  立方体的序号
 *  @param height_index 当前立方体的高的序号边
 */
void get_dimensions(int* v, int index, int height_index) {
  int idx = 0;
  for (int i = 0; i < 3; i++) {
    if (i != height_index) {
      v[idx++] = blocks[index][i];
    }
  }
}

// 第i个立方体第j条边，j = 0,1,2
int dp(int i, int j) {
  int& ans = status[i][j];
  if (ans > 0) {
    return ans;
  }
  int v1[2], v2[2];
  get_dimensions(v1, i, j);
  for (int a = 0; a < n; a++) {
    for (int b = 0; b < 3; b++) {
      get_dimensions(v2, a, b);
      if (v2[0] < v1[0] && v2[1] < v1[1]) {
        ans = max(ans, dp(a, b));
      }
    }
  }
  ans += blocks[i][j];  //以第i个立方体的第j条边为高
  return ans;
}

int main() {
//  freopen(
//      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//      "r", stdin);
//  freopen(
//      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/"
//      "out",
//      "w", stdout);
//
  int kcase = 1;
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        scanf("%d", &blocks[i][j]);
      }
      //排序，把第i个立方体的长、宽、高按从小到达排序,注意sort(begin(),end())
      sort(blocks[i], blocks[i] + 3);
    }
    memset(status, 0, sizeof(status));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        ans = max(ans, dp(i, j));
      }
    }
    printf("Case %d: maximum height = %d\n", kcase++, ans);
  }
  return 0;
}
