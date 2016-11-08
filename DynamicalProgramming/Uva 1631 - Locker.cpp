//题目链接：点击打开链接
//题意：有一个n位密码锁，每一位都是0~9，可以循环旋转，每次可以让1~3个相邻数字同时往上或者往下旋转一格。
//输入初始状态和终止状态，问最少需要转几次。
//思路： 很显然是个DP题目， 由于每次可以让相邻的1~3个数字同时旋转，
//所以状态的表示上就要考虑相邻3个位置。
//那么可以用d[i][a][b][c]表示当前到了第i位，第i位上当前是a，i+1位是b，i+2位是c。
//那么显然必须让i位上变成目标数字了，
//因为接下来就转移到i+1位了，说明前i位已经全部转到目标态了。
//那么转移也就很显然了， 计算出a上转和下转的次数，
//然后b、c位的数字有选择的转多少次。
//细节参见代码：
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
const int maxn = 1000 + 10;
const int INF = 100000000;
char str[maxn], secret[maxn];
int d[maxn][12][12][12], visited[maxn][12][12][12];
// int rot[maxn];
int kase;
int len;
int dp(int i, int a, int b, int c) {
  int &ans = d[i][a][b][c];
  if (i >= len) {
    return 0;
  }
  if (visited[i][a][b][c] == kase) {
    //    printf("i%d a%d b%d c%d %d\n", i, a, b, c, ans);
    return d[i][a][b][c];
  }
  visited[i][a][b][c] = kase;
  ans = INF;

  int t = secret[i] - '0';
  int cur = a;
  if (cur <= t) {
    int up = t - cur;
    //    if (up == 0) {
    //      int testz = 0;
    //    }
    for (int j = 0; j <= up; j++) {
      for (int k = 0; k <= j; k++) {
        //        if (i == 0 && k == 1 && j == 1) {
        //          int testy = 2;
        //        }
        ans = min(ans,
                  dp(i + 1, (b + j) % 10, (c + k) % 10, str[i + 3] - '0') + up);
      }
    }
    int down = 10 - up;
    for (int j = 0; j <= down; j++) {
      for (int k = 0; k <= j; k++) {
        ans = min(ans, dp(i + 1, (10 + b - j) % 10, (10 + c - k) % 10,
                          str[i + 3] - '0') +
                           down);
      }
    }

  } else {
    int down = cur - t;
    for (int j = 0; j <= down; j++) {
      for (int k = 0; k <= j; k++) {
        ans = min(ans, dp(i + 1, (10 + b - j) % 10, (10 + c - k) % 10,
                          str[i + 3] - '0') +
                           down);
      }
    }
    int up = 10 - down;
    for (int j = 0; j <= up; j++) {
      for (int k = 0; k <= j; k++) {
        ans = min(ans,
                  dp(i + 1, (b + j) % 10, (c + k) % 10, str[i + 3] - '0') + up);
      }
    }
  }
  return ans;
}

int main() {
  //  freopen(
  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
  //      "r", stdin);
  //  freopen("/Users/yuxiao/XcodeProject/DynamicalProgramming/"
  //          "DynamicalProgramming/out",
  //          "w", stdout);

  int res;
  kase = 1;
  while (scanf("%s%s", str, secret) != EOF) {
    len = strlen(str);

    for (int i = len; i <= len + 3; i++) {
      str[i] = secret[i] = '0';
    }
    str[len + 4] = secret[len + 4] = '\0';
    res = dp(0, str[0] - '0', str[1] - '0', str[2] - '0');
    printf("%d\n", res);
    kase++;
  }
  return 0;
}
