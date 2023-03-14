#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 720;

int M;
int arr[1501];

int convert(string s);

void solve() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		arr[i] = convert(s);
	}

	int ans = 0x3f3f3f3f;
	
	for (int i = 1; i <= 720; i++) {
		set <int> s;
		for (int j = 0; j < M; j++) {
			s.insert(((arr[j] - i * j) + mod * 2000) % mod);
		}
		ans = min(ans, (int)s.size());
	}

	cout << ans;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int convert(string s) {
	int ret = 0;
	int first = 0;
	for (int i = 0; i < 2; i++) {
		first *= 10;
		first += s[i] - '0';
	}
	ret += first * 60;
	int second = 0;
	for (int i = 3; i < 5; i++) {
		second *= 10;
		second += s[i] - '0';
	}
	ret += second;
	return ret;
}