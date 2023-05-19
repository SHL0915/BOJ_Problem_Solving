#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M, K, cnt;
ll arr[1000005];
int parent[1000005];
vector <pair<ll, pii>> edge;
int disconnected[1000005];

void Union(int a, int b);
int Find(int a);

void solve() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N + 1; i++) parent[i] = i;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		edge.push_back({ arr[i], {i, N + 1} });
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (abs(a - b) == 1) disconnected[min(a, b)] = 1;
		else disconnected[N] = 1;
	}

	if (M <= 1) {
		cout << "YES";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (disconnected[i]) continue;
		if (i == N) {
			if (Find(i) == Find(1)) continue;
			Union(i, 1);
			cnt++;
		}
		else {
			if (Find(i) == Find(i + 1)) continue;
			Union(i, i + 1);
			cnt++;
		}
	}

	sort(edge.begin(), edge.end());
	ll sum = 0;

	for (int i = 0; i < edge.size(); i++) {
		if (cnt == N) break;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		ll cost = edge[i].first;
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		sum += cost;
	}

	if (sum > K) cout << "NO";
	else cout << "YES";
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