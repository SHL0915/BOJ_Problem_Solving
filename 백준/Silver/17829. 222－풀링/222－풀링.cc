#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1025][1025];

int DNC(int x, int y, int len);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	cout << DNC(0, 0, N);
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

int DNC(int x, int y, int len) {
	if (len == 1) return arr[y][x];
	int ret[4];
	ret[0] = DNC(x, y, len / 2);
	ret[1] = DNC(x + len / 2, y, len / 2);
	ret[2] = DNC(x, y + len / 2, len / 2);
	ret[3] = DNC(x + len / 2, y + len / 2, len / 2);
	sort(ret, ret + 4);
	return ret[2];
}