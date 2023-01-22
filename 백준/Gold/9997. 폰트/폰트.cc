#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt;
int arr[26];

void BF(int k, int state);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s; 
		for (int j = 0; j < s.length(); j++) arr[i] |= (1 << (s[j] - 'a'));
	}
	BF(0, 0);
	cout << cnt;
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

void BF(int k, int state) {
	if (k == N) {
		cnt += (state == (1 << 26) - 1);
		return;
	}
	else {
		BF(k + 1, state);
		BF(k + 1, state | arr[k]);
	}
	return;
}