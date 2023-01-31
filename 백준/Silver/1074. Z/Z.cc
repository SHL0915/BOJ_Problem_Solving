#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans, cnt;
int r, c;

void DNC(int x, int y, int len);

void solve() {
	cin >> N >> r >> c;
	DNC(0, 0, 1 << N);
	cout << ans - 1;
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

void DNC(int x, int y, int len) {
	if (len == 1) {
		cnt++;
		if (x == c && y == r) {
			ans = cnt;
			return;
		}
		else return;
	}
	if (c < x + len / 2) {
		if (r < y + len / 2) DNC(x, y, len / 2);
		else {
			cnt += (len / 2) * (len / 2) * 2;
			DNC(x, y + len / 2, len / 2);
		}
	}
	else {
		if (r < y + len / 2) {
			cnt += (len / 2) * (len / 2);
			DNC(x + len / 2, y, len / 2);
		}
		else {
			cnt += (len / 2) * (len / 2) * 3;
			DNC(x + len / 2, y + len / 2, len / 2);
		}
	}	
	return;
}