#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B, N, M;

int x_arr[2001], y_arr[2001];
int parent[4005005];
vector <pair<ll, pii>> edge;

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> A >> B >> N >> M;
	for (int i = 0; i < N; i++) cin >> x_arr[i];
	for (int i = 0; i < M; i++) cin >> y_arr[i];

	for (int i = 0; i < 4005005; i++) parent[i] = i;

	sort(x_arr, x_arr + N);
	sort(y_arr, y_arr + M);

	vector <int> delt_x, delt_y;
	delt_x.push_back(x_arr[0]);
	for (int i = 1; i < N; i++) delt_x.push_back(x_arr[i] - x_arr[i - 1]);
	delt_x.push_back(A - x_arr[N - 1]);

	delt_y.push_back(y_arr[0]);
	for (int i = 1; i < M; i++) delt_y.push_back(y_arr[i] - y_arr[i - 1]);
	delt_y.push_back(B - y_arr[M - 1]);

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j < N; j++) {
			int now = i * (N + 1) + j, next = i * (N + 1) + j + 1;
			edge.push_back({ delt_y[i], {now, next} });
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int now = j * (N + 1) + i, next = (j + 1) * (N + 1) + i;
			edge.push_back({ delt_x[i], {now, next} });
		}
	}

	sort(edge.begin(), edge.end());

	int cnt = 0;
	ll ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (cnt == (N + 1) * (M + 1) - 1) break;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		ll cost = edge[i].first;

		if (Find(a) == Find(b)) continue;
		cnt++;
		Union(a, b);
		ans += cost;
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

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}