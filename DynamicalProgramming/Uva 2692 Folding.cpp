//// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4505
//// 题意：折叠一个字符串，使得其成为一个尽量短的字符串  例如AAAAAA变成6（A）
//
////而且这个折叠是可以嵌套的，例如 NEEEEERYESYESYESNEEEEERYESYESYES 会变成
////2(N5(E)R3(YES))。
////
////析：用dp[i][j] 表示字符串中的第 i 个到第 j
////个字符压缩后的最短长度。那么就有两种方式，一种就是自身压缩都最短，另一种就是两段分别压缩，
////
////然后再接起来最短。
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
//const int maxn = 104;
//string dp[maxn][maxn];
//int INT = 200;
//int n;
//string str;
//
//int cal(int i, int j) {
//  int len = j - i + 1;
//  int mid = len / 2;
//  for (int k = 1; k <= mid; k++) {
//    if (len % k == 0) {
//      int ok = 1;
//      for (int x = i; x + k <= j; x++) {
//        if (str[x] != str[x + k]) {
//          ok = 0;
//          break;
//        }
//      }
//      if (ok) {
//        return k;
//      }
//    }
//  }
//  return 0;
//}
//
//int main() {
//  //  freopen(
//  //      "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//  //      "r", stdin);
//  //  freopen("/Users/yuxiao/XcodeProject/DynamicalProgramming/"
//  //          "DynamicalProgramming/out",
//  //          "w", stdout);
//
//  while (cin >> str) {
//    n = str.size();
//    //    memset(dp, 0, sizeof(dp));
//    for (int i = 0; i < n; i++) {
//      dp[i][i] = str[i];
//    }
//    for (int i = n - 2; i >= 0; i--) {
//      for (int j = i + 1; j < n; j++) {
//
//        int ans = INT, x = i;
//
//        for (int k = i; k < j; k++) {
//          if (ans > dp[i][k].size() + dp[k + 1][j].size()) {
//            ans = dp[i][k].size() + dp[k + 1][j].size();
//            x = k;
//          }
//        }
//
//        dp[i][j] = dp[i][x] + dp[x + 1][j];
//        //        cout << i << j << " " << dp[i][j] << endl;
//        int rplen = cal(i, j);
//        if (rplen) {
//          if (i == 0) {
//            int few = 1;
//          }
//          //          int num = (j - i + 1) / rplen;
//          //          string temp = (string)num + "(";
//          //          temp += dp[i][i + rplen - 1];
//          //          temp += ")";
//          char s[5];
//          sprintf(s, "%d", (j - i + 1) / rplen);
//          string temp = (string)s + "(" + dp[i][i + rplen - 1] + ")";
//          if (ans >= temp.size()) {
//            ans = temp.size();
//            dp[i][j] = temp;
//          }
//        }
//      }
//    }
//    cout << dp[0][n - 1] << endl;
//  }
//
//  //  cin >> str;
//  //  n = str.size();
//  //  cout << cal(0, n - 1);
//  return 0;
//}
