////动态规划 递推法求硬币集合问题
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
//
//////input
//// 1
//// 3
//// 1 5 10
//// 20
//
// const int maxn = 100;
// const int INF = (1 << 30);
//
// int min_coins[maxn],
//    path_min_coins[maxn];  //所需最小的硬币数量，以及记录硬币的序号的path数组
// int max_coins[maxn], path_max_coins[maxn];
// int coins[maxn];  //银币值
// int sum;          //所需满足的硬币之和
// int n;            //共n枚硬币
//
////打印所需硬币的序号
// void print_ans(int* path, int sum) {
//  while (sum) {
//    cout << path[sum] << " ";
//    sum -= coins[path[sum]];
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
//  while (T--) {
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//      cin >> coins[i];
//    }
//    cin >> sum;
//    for (int i = 1; i <= sum; i++) {
//      min_coins[i] = INF;
//      max_coins[i] = -INF;
//    }
//    min_coins[0] = 0;
//    max_coins[0] = 0;
//
//    for (int i = 1; i <= sum; i++) {
//      for (int j = 0; j < n; j++) {
//        if (i >= coins[j]) {
//          //当min 值相同时，取最小的i值，故判断不用 “>="
//          if (min_coins[i] > min_coins[i - coins[j]] + 1) {
//            min_coins[i] = min_coins[i - coins[j]] + 1;
//            path_min_coins[i] = j;
//          }
//
//          if (max_coins[i] < max_coins[i - coins[j]] + 1) {
//            max_coins[i] = max_coins[i - coins[j]] + 1;
//            path_max_coins[i] = j;
//          }
//        }
//      }
//    }
//    printf("Case #%d:\n", t++);
//    cout << "min:  " << min_coins[sum] << endl;
//    print_ans(path_min_coins, sum);
//    cout << endl;
//    cout << "max:  " << max_coins[sum] << endl;
//    print_ans(path_max_coins, sum);
//    cout << endl;
//  }
//  return 0;
//}
