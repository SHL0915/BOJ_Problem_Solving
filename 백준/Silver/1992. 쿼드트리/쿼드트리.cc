#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[65][65];

void DNC(int x, int y, int len);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) arr[i][j] = s[j] - '0';
	}
	DNC(0, 0, N);
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
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) cnt += arr[y + i][x + j];
	}
	if (cnt == len * len) {
		cout << 1;
		return;
	}
	if (cnt == 0) {
		cout << 0;
		return;
	}
	cout << '(';
	DNC(x, y, len / 2);
	DNC(x + len / 2, y, len / 2);
	DNC(x, y + len / 2, len / 2);
	DNC(x + len / 2, y + len / 2, len / 2);
	cout << ')';
	return;
}