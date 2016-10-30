//// 线性结构上的动态规划  回文子串
//// O(n^2)
//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2395
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
//const int maxn = 1005;
//int n, case_index, vistied[maxn][maxn], p[maxn][maxn], d[maxn];
//char s[maxn];
//
//// 递归判断回文，并记录
//int is_palindrome(int i, int j) {
//  if (i >= j) {
//    return 1;
//  }
//  if (s[j] != s[i]) {
//    return 0;
//  }
//  if (vistied[i][j] == case_index) {
//    return p[i][j];
//  }
//
//  vistied[i][j] = case_index;
//  p[i][j] = is_palindrome(i + 1, j - 1);
//  return p[i][j];
//}
//
//int main() {
//  //  freopen(
//  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//  //      "r", stdin);
//  //  freopen(
//  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/"
//  //      "out",
//  //      "w", stdout);
//
//  int T, t;
//  cin >> T;
//  t = 1;
//  memset(vistied, 0, sizeof(vistied));
//  case_index = 1;
//  while (T--) {
//    scanf("%s", s + 1);  // s[0] = "\0"
//    n = strlen(s + 1);
//    d[0] = 0;
//    for (int i = 1; i <= n; i++) {
//      d[i] = i + 1;
//      for (int j = 0; j < i; j++) {
//        if (is_palindrome(j + 1, i)) {
//          d[i] = min(d[i], d[j] + 1);
//        }
//      }
//    }
//    printf("%d\n", d[n]);
//    case_index++;
//  }
//  return 0;
//}
