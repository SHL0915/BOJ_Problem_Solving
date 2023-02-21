#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string arr[1001];

bool cmp(string a, string b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, cmp);
	if (arr[0] == "0") {
		cout << 0;
		return;
	}
	for (int i = 0; i < N; i++) cout << arr[i];
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

bool cmp(string a, string b) {
	string l = a + b;
	string r = b + a;
	for (int i = 0; i < l.length(); i++) {
		if (l[i] > r[i]) return true;
		else if (l[i] < r[i]) return false;
	}
	return false;
}