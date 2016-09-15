////
///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=847&problem=4093&mosmsg=Submission+received+with+ID+18003790
//// 共 （n^2) 个状态，每个状态有两种决策，因此算法复杂度为O(n^2)
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
// const int maxn = 55;
//
// int n;
// double x[maxn], y[maxn];
// double dist[maxn][maxn];
//// d(i,j) 表示 1~max（i,j)
////
///全部走过，且两个人当前的位置分别为i和j时，还需走多长的距离。不难发现，d(i,j)
//// = d(j,i)
////因此，从现在规定的状态中i>j,这样，不管是哪一个人，下一步只能走到i+1,i+2...这些点
// double d[maxn][maxn];
//
// int main() {
//  //  freopen(
//  //
//  "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/in",
//  //      "r", stdin);
//  //  freopen(
//  // "/Users/yuxiao/XcodeProject/DynamicalProgramming/DynamicalProgramming/"
//  //      "out",
//  //      "w", stdout);
//  while (scanf("%d", &n) == 1) {
//    for (int i = 1; i <= n; i++) {
//      scanf("%lf%lf", &x[i], &y[i]);
//    }
//
//    for (int i = 1; i <= n; i++) {
//      for (int j = 1; j <= n; j++) {
//        //计算每两点之间距离
//        dist[i][j] =
//            sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] -
//            y[j]));
//      }
//    }
//
//    //逆推
//    for (int i = n - 1; i >= 2; i--) {
//      for (int j = 1; j < i; j++) {
//        if (i == n - 1) {
//          //// 边界
//          d[i][j] = dist[i][n] + dist[j][n];
//        } else {
//          d[i][j] =
//              // 下一步，i走到第i+1个点，j不动，或者，j走到i+1个点，i不动
//              min(d[i + 1][j] + dist[i][i + 1], d[i + 1][i] + dist[j][i + 1]);
//        }
//      }
//    }
//    printf("%.2lf\n", d[2][1] + dist[1][2]);
//  }
//  return 0;
//}
