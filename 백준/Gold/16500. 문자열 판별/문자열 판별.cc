#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int N;
string arr[101];
int table[101];

int DP(int pos);

void solve() {
	cin >> S;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << DP(0);
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

int DP(int pos) {
	if (pos == S.length()) return 1;
	int& ret = table[pos];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i].length() > S.length() - pos) continue;
		int flag = 0;
		for (int j = 0; j < arr[i].length(); j++) {
			if (arr[i][j] != S[pos + j]) {
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		ret |= DP(pos + arr[i].length());
	}

	return ret;
}