#include <bits/stdc++.h>
using namespace std;

int N, M, D, S, ans;
set <int> milk[51][101];
set <int> milkEaten[101];
set <int> candidate;
int mark[101][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> D >> S;
	for (int i = 0; i < D; i++) {
		int p, m, t;
		cin >> p >> m >> t;
		milkEaten[m].insert(p);
		for (int i = t + 1; i <= 100; i++) milk[p][i].insert(m);
	}
	for (int i = 1; i <= 100; i++) {
		mark[i][0] = 1;
		mark[i][1] = 1;
	}
	int now, next;
	for (int i = 0; i < S; i++) {
		int p, t;
		cin >> p >> t;
		now = i % 2;
		next = now ^ 1;
		for (int j = 1; j <= 100; j++) mark[j][next] = 0;
		for (int j = 1; j <= 100; j++) {
			if (mark[j][now] && milk[p][t].count(j)) mark[j][next] = 1;
		}
	}
	for (int i = 1; i <= 100; i++) {
		if (mark[i][next] == 0) continue;		
		ans = max(ans, (int)milkEaten[i].size());
	}
	cout << ans;
	return 0;
}