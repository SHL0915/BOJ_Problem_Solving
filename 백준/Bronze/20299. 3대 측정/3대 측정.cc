#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, L;
vector <pair<int, pii>> arr;

void solve() {
	cin >> N >> K >> L;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a >= L && b >= L && c >= L && a + b + c >= K) arr.push_back({ a,{b,c} });
	}

	cout << arr.size() << '\n';
	for (int i = 0; i < arr.size(); i++) cout << arr[i].first << " " << arr[i].second.first << " " << arr[i].second.second << " ";

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