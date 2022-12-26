#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

vector <int> s;
int table[5][5][100001];

int DP(int left, int right, int now);
int calc(int now, int next);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		int A;
		cin >> A;
		if (A == 0) break;
		s.push_back(A);
	}
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0);
	return 0;
}

int DP(int left, int right, int now) {
	int& ret = table[left][right][now];
	if (now == s.size()) return 0;
	if (ret != -1) return ret;
	ret = INF;
	int next = s[now];
	ret = min(ret, calc(left, next) + DP(next, right, now + 1));
	ret = min(ret, calc(right, next) + DP(left, next, now + 1));
	return ret;
}

int calc(int now, int next) {
	if (now == 0) return 2;
	if (now == next) return 1;
	if ((now + next) % 2) return 3;
	else return 4;
}