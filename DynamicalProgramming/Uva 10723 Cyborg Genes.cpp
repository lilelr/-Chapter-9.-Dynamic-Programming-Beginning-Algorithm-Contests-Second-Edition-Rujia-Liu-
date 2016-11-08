//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=848&page=show_problem&problem=1664
//// 最长公共子序列
////首先这个题目肯定是按最长公共子序列的形式进行dp的，因为只有保证消去的一部分是最长公共子序列才能保证最后生成的序列最短。
////
////因此，在记录方案数的时候我们也按最长公共子序列的生成过程来记录即可，我们不妨用p[i][j]记录最长公共子序列的字符数，用f[i][j]表示到第一个字符串第i个位置、第二个字符串第j个位置时生成的序列最短的方案种数。
////
////当a[i]!=b[j]时，p[i][j]=max{p[i-1][j]，p[i][j-1]}，那么如果p[i][j]==p[i-1][j]，f[i][j]+=f[i-1][j]，如果p[i][j]==p[i][j-1]，f[i][j]+=f[i][j-1]。用文字翻译过来就是说因为a[i]和b[j]是不同的，所以f[i][j]等于以a[i]结尾的最短的字符串的方案种数，加上以b[j]结尾的最短的字符串的方案种数。
////
////当a[i]==b[j]时，p[i][j]=p[i-1][j-1]+1，f[i][j]+=f[i-1][j-1]。试想，我们这样算会不会少算某些部分呢？因为毕竟也可以在a[i]和b[j]不配成一对的情况下生成最短的字符串呀。实际上，是可以证明f[i-1][j-1]包含了上述的情况的。譬如我们假设b[j]和a[i]前面的某个字符配成一对，同时生成了最短的字符串，那么这个字符串必然是以a[i]结尾的某个最短字符串，而以a[i]结尾的所有最短字符串的个数显然已经包含在f[i-1][j-1]之中了，因为f[i-1][j-1]本身就表示的是以a[i]为结尾的最短字符串的方案总数。
////
////实际上，这个类似证明求最长公共子序列时如果a[i]==b[j]，那么取p[i][j]=p[i-1][j-1]+1一定是最优的。
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
//const int maxn = 32;
//int dp[maxn][maxn];
//long long int w[maxn][maxn];
//char s1[maxn];
//char s2[maxn];
//const int INF = 10e+9;
//int n1, n2;
//int main() {
//  freopen(
//      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//      "r", stdin);
//  freopen("/Users/yuxiao/XcodeProject/DynamicalProgramming/"
//          "DynamicalProgramming/out",
//          "w", stdout);
//
//  int T, t;
//  cin >> T;
//  t = 1;
//  while (T--) {
//    scanf("%s", s1 + 1);
//    scanf("%s", s2 + 1);
//    n1 = strlen(s1 + 1);
//    n2 = strlen(s2 + 1);
//    memset(w, 0, sizeof(w));
//    for (int i = 0; i <= n1; i++) {
//      for (int j = 0; j <= n2; j++) {
//        dp[i][j] = INF;
//      }
//    }
//    dp[0][0] = 0;
//    w[0][0] = 1; // 如果两个字符串第一个字母相等时，则w[1][1] = w[0][0] =1
//    for (int i = 1; i <= n1; i++) {
//      dp[i][0] = 0;
//      w[i][0] = 1;
//    }
//    for (int i = 1; i <= n2; i++) {
//      dp[0][i] = 0;
//      w[0][i] = 1;
//    }
//    for (int i = 1; i <= n1; i++) {
//      for (int j = 1; j <= n2; j++) {
//        if (s1[i] == s2[j]) {
//          dp[i][j] = dp[i - 1][j - 1] + 1;
//          w[i][j] += w[i - 1][j - 1];
//        } else {
//          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//
//          //// 两个尾元素不等时则一种可能是 AB
//          if (dp[i][j] == dp[i - 1][j]) {
//            w[i][j] += w[i - 1][j];
//          }
//          // 两个尾元素不等时则另一种可能是 BA
//          if (dp[i][j] == dp[i][j - 1]) {
//            w[i][j] += w[i][j - 1];
//          }
//        }
//        //        cout << i << j << ":" << dp[i][j] << endl;
//      }
//    }
//
//    printf("Case #%d: %d %lld\n", t++, n1 + n2 - dp[n1][n2], w[n1][n2]);
//  }
//  return 0;
//}
