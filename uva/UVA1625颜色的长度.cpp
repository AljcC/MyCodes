/*
例如，序列GBBY和YRRGB，分别已经移走了1个和3个元素（例如，已经合并成龙YRRG）。下次再从序列2移走
一个元素（即G）时，Y和G需要加1。下次再从序列1移走一个元素（即B）时，只有Y需要加1（因为G已经结束了）

这样，可以事先算出每个颜色在两个序列中的开始和结束位置，就可以在动态规划时在O(1)时间内算出状态d(i,j)
中“有多少个颜色已经出现但尚未结束”。从而在O(1)时间内完成状态转移。状态总是为O(mn)个，总时间复杂度
也是O(mn)

定义c[i,j]表示已经移走了i和j个元素时，已经开始但尚未完成的字符数量
定义d[i,j]表示已经移走了i和j个元素时，L(c)总和的最小值
动态转移方程： d[i][j] = min(d[i-1][j]+c[i-1][j], d[i][j-1]+c[i][j-1]);
*/
//https://www.luogu.org/problemnew/show/uva1625
//code by LJC
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	
	return 0;
}