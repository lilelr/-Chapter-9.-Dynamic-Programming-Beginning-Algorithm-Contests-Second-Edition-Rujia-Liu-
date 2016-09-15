// LIS 最长上升子序列的问题
// input
// 1
// 5
// 8 3 10 5 9
// out
// Case #1: 3
// O(n^2)
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
const int maxn = 100;
int nums[maxn];
int d[maxn];

int main() {
  freopen(
      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
      "r", stdin);
  freopen(
      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/"
      "out",
      "w", stdout);

  int T, t;
  cin >> T;
  t = 1;
  LL ans;
  int n;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> nums[i];
      d[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        if (nums[j] < nums[i]) {
          d[i] = max(d[i], d[j] + 1);
        }
      }
    }
    ans = d[n];
    printf("Case #%d: %lld\n", t++, ans);
  }
  return 0;
}
