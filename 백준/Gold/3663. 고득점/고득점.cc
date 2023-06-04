#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

string S;
int N;
vector <int> arr;
int table[1005][1005][2];

int DP(int left, int right, int now);

void solve() {
	cin >> S;
	arr.clear();
	arr.push_back(0);

	for (int i = 0; i < S.length(); i++) {
		if (S[i] != 'A') arr.push_back(i);
	}

	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	N = S.size();

	memset(table, -1, sizeof(table));
	cout << DP(0, arr.size() - 1, 0) << '\n';

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int left, int right, int now) {
	if (left == right) return min((S[arr[right]] - 'A' + 26) % 26, ('A' - S[arr[right]] + 26) % 26);
	int& ret = table[left][right][now];
	if (ret != -1) return ret;
	ret = INF;
	if (now) {
		int cur = arr[right];
		int prev = arr[right - 1];
		int nxt = arr[left];

		int val = min((S[cur] - 'A' + 26) % 26, ('A' - S[cur] + 26) % 26);

		ret = min(ret, val + cur - prev + DP(left, right - 1, now));
		ret = min(ret, val + nxt + N - cur + DP(left, right - 1, 0));
	}
	else {
		int cur = arr[left];
		int prev = arr[right];
		int nxt = arr[left + 1];
		int val = min((S[cur] - 'A' + 26) % 26, ('A' - S[cur] + 26) % 26);

		ret = min(ret, val + nxt - cur + DP(left + 1, right, now));
		ret = min(ret, val + cur + N - prev + DP(left + 1, right, 1));
	}

	return ret;
}