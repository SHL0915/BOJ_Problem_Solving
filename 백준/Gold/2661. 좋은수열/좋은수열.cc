#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void BackTracking(int k, string now);
bool check(string s);

void solve() {
	cin >> N;
	BackTracking(1, "1");
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

void BackTracking(int k, string now) {
	if (k == N) {
		cout << now;
		exit(0);
	}
	else {
		for (int i = 1; i <= 3; i++) {
			char c = '0' + i;
			if (c == now.back()) continue;
			if (check(now + c)) BackTracking(k + 1, now + c);
		}
	}
	return;
}

bool check(string s) {
	int n = s.length();
	for (int i = 1; i <= n / 2; i++) { // 길이
		int flag = 0;
		for (int j = n - 1 - i; j > n - 1 - 2 * i; j--) {
			if (s[j + i] != s[j]) {
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		else return false;
	}
	return true;
}