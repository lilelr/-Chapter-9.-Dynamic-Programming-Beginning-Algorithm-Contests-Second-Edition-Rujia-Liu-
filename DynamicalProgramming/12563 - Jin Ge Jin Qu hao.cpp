//// 0-1背包问题
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
//
//int n;
//LL t;
//int songs[51];
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
//  int T, caseN;
//  cin >> T;
//  caseN = 1;
//  LL ans;
//  LL totalLen;
//  while (T--) {
//    totalLen = 0;
//    ans = 0;
//    cin >> n >> t;
//    for (int i = 1; i <= n; i++) {
//      cin >> songs[i];
//    }
//    LL res[t];
//
//    LL totalLengths[t];
//    memset(res, -1, sizeof(res));
//    memset(totalLengths, 0, sizeof(totalLengths));
//    // res[j] 代表歌曲总时长刚好为j的歌曲最多个数
//    res[0] = 0;
//    for (int i = 1; i <= n; i++) {
//      for (LL j = t - 1; j >= 1; j--) {
//        if (j >= songs[i] && res[j - songs[i]] >= 0) {
//          res[j] = max(res[j], res[j - songs[i]] + 1);
//          ans = max(ans, res[j]);
//          //          totalLengths[j] =
//          //              max(totalLengths[j], totalLengths[j - songs[i]] +
//          //              songs[i]);
//        }
//      }
//    }
//    //    ans = res[t - 1];
//    for (LL k = t - 1; k >= 1; k--) {
//      if (ans == res[k]) {
//        totalLen = k;
//        break;
//      }
//    }
//    totalLen = totalLen + 678;
//    ans += 1;
//    printf("Case %d: %lld %lld\n", caseN++, ans, totalLen);
//  }
//  return 0;
//}
