#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100001];
string output[2] = {"Whiteking", "Blackking"};

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	ll res = 0;
	for (int i = 0; i < N; i++) res ^= (arr[i] - 2);
	string s;
	cin >> s;
	if (s == output[1]) swap(output[0], output[1]);
	if (res) cout << output[0];
	else cout << output[1];
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