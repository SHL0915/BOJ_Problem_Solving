#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MAX = 2000003;

int N;
vector <ll> arr;
int mark[2000005];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i; j < arr.size(); j++) {
			if (arr[i] * arr[j] >= MAX) break;
			mark[arr[i] * arr[j]] = 1;
		}
	}

	for (int i = 0; i <= MAX; i++) {
		if (mark[i] == 0) {
			cout << i;
			return;
		}
	}
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