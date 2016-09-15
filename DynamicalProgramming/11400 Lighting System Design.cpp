////
///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=847&problem=2395&mosmsg=Submission+received+with+ID+18004148
//// O(n^2)
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
// const int maxn = 1005;
// struct lamp {
//  int voltage;  //电压
//  int cost;     //该类型灯泡的价格
//  int k;        //该类型灯泡的电源价格
//  int number;   //所需该类型灯泡的数量
//  //按电压从小到大排序的比较函数
//  bool operator<(const lamp& b) const { return voltage < b.voltage; }
//} lamp[maxn];
//
// int n;
// int sum[maxn];
//// d[i] 表示购买前i种灯泡所需的最小费用，包括灯泡的价格*数量，以及电源费用
// int d[maxn];
// int main() {
//  //  freopen(
//  //
//  "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//  //      "r", stdin);
//  //  freopen(
//  // "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/"
//  //      "out",
//  //      "w", stdout);
//
//  while (cin >> n && n) {
//    for (int i = 1; i <= n; i++) {
//      cin >> lamp[i].voltage >> lamp[i].k >> lamp[i].cost >> lamp[i].number;
//    }
//    //按电压从小到大排序
//    sort(lamp + 1, lamp + n + 1);
//    sum[0] = 0;
//    for (int i = 1; i <= n; i++) {
//      sum[i] = sum[i - 1] + lamp[i].number;
//    }
//    d[0] = 0;
//    for (int i = 1; i <= n; i++) {
//      //// 前i个灯泡全买类型i
//      d[i] = sum[i] * lamp[i].cost + lamp[i].k;  //初始化
//      for (int j = 1; j <= i; j++) {
//        // 第 j+1 到i 共( sum[i] - sum[j] ) 个灯泡全买类型i
//        d[i] = min(d[i], d[j] + (sum[i] - sum[j]) * lamp[i].cost + lamp[i].k);
//      }
//    }
//    cout << d[n] << "\n";
//  }
//
//  return 0;
//}
