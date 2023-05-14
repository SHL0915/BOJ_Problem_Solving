#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005], parent[100005];
vector <ll> val, cycle[100005];

void Union(int a, int b);
int Find(int a);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		val.push_back(arr[i]);
		parent[i] = i;
	}
	sort(val.begin(), val.end());

	for (int i = 1; i <= N; i++) {
		int idx = lower_bound(val.begin(), val.end(), arr[i]) - val.begin() + 1;
		Union(i, idx);
	}

	for (int i = 1; i <= N; i++) cycle[Find(i)].push_back(i);
	
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		if (cycle[i].size() < 2) continue;
		ll a = 0, b = 0, tot = 0;

		for (int j = 1; j < cycle[i].size(); j++) tot += val[cycle[i][j] - 1];
		a = tot + val[cycle[i][0] - 1] * (cycle[i].size() - 1);
		b = tot + val[0] * (cycle[i].size() - 1) + 2 * (val[0] + val[cycle[i][0] - 1]);

		ans += min(a, b);
	}

	cout << ans;
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

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;	
	return;
}

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}