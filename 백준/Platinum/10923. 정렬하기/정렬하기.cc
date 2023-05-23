#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[505], pos[505], target[505], tarpos[505];
pii query[15005];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		pos[arr[i]] = i;
		target[i] = i;
	}
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> query[i].first >> query[i].second;

	for (int i = M; i >= 1; i--) {
		int a = query[i].first, b = query[i].second;
		swap(target[a], target[b]);
	}

	for (int i = 0; i < N; i++) tarpos[target[i]] = i;

	vector <pii> ans;

	int pt = 0;
	for (int i = 1; i <= M; i++) {
		int a = query[i].first, b = query[i].second;
		swap(target[a], target[b]);
		swap(arr[a], arr[b]);
		swap(tarpos[target[a]], tarpos[target[b]]);
		swap(pos[arr[a]], pos[arr[b]]);

		while (pt < N && pos[pt] == tarpos[pt]) pt++;
		if (pt == N) {
			ans.push_back({ 0,0 });
			continue;
		}

		int p1 = pos[pt];
		int p2 = tarpos[pt];
		ans.push_back({ p1,p2 });

		swap(arr[p1], arr[p2]);
		swap(pos[arr[p1]], pos[arr[p2]]);
	}

	cout << ans.size() << '\n';
	for (pii i : ans) cout << i.first << " " << i.second << '\n';
	
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