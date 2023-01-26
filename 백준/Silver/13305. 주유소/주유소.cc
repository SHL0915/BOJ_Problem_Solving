#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100001];
int road[100001];

void solve() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> road[i];
		road[i] += road[i - 1];
	}
	for (int i = 0; i < N; i++) cin >> arr[i];
	int now = 0;
	ll ans = 0;
	for (int i = 1; i < N; i++) {
		if (arr[i] < arr[now]) {
			ans += arr[now] * (road[i] - road[now]);
			now = i;
		}
	}
	ans += arr[now] * (road[N - 1] - road[now]);
	cout << ans;
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