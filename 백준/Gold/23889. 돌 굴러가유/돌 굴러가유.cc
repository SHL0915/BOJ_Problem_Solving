#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
int arr[100005];
ll psum[100005];

void solve() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + arr[i];

	vector <int> stone;
	for (int i = 0; i < K; i++) {
		int a; cin >> a;
		stone.push_back(a);
	}

	vector<pii> v;
	for (int i = 0; i < stone.size() - 1; i++) v.push_back({ psum[stone[i + 1]] - psum[stone[i] - 1], stone[i] });
	v.push_back({ psum[N] - psum[stone.back() - 1], stone.back() });

	sort(v.begin(), v.end(), [&](pii a, pii b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
		});

	vector <int> ans;
	for (int i = 0; i < M; i++) ans.push_back(v[i].second);

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';

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