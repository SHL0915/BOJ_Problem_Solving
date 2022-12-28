#include <bits/stdc++.h>
using namespace std;

int X, Y, M, ans;
int mark[1001];

void DFS(int now);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> X >> Y >> M;
	DFS(0);
	cout << ans;
	return 0;
}

void DFS(int now) {
	if (now > M) return;
	if (mark[now] != 0) return;
	mark[now] = 1;
	ans = max(ans, now);
	DFS(now + X);
	DFS(now + Y);
	return;
}