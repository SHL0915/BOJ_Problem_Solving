#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int mark[10];
int bt[10];

void BackTracking(int k);

void solve() {
	cin >> N >> M;
	BackTracking(0);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void BackTracking(int k) {	
	if (k == M) {
		for (int i = 0; i < M; i++) cout << bt[i] << " ";
		cout << '\n';
		return;
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (mark[i] == 0) {
				bt[k] = i;
				mark[i] = 1;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
}