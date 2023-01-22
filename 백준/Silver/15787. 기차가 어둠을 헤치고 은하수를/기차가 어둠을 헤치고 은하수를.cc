#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[100001];
set <int> s;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c; c--;
			arr[b] |= (1 << c);
		}
		else if (a == 2) {
			cin >> c; c--;
			if (arr[b] & (1 << c)) arr[b] ^= (1 << c);
		}
		else if (a == 3) {
			arr[b] <<= 1;
			arr[b] %= (1 << 20);
		}
		else arr[b] >>= 1;
	}
	for (int i = 1; i <= N; i++) s.insert(arr[i]);
	cout << s.size();
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