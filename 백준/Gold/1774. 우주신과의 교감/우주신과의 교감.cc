#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
pii arr[1001];
int parent[1001];
vector <pair<double, pii>> graph;

double dist(pii a, pii b);
int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) graph.push_back({ dist(arr[i],arr[j]), {i,j} });
	}
	sort(graph.begin(), graph.end());
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		cnt++;
	}
	double ans = 0;
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == N - 1) break;
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		double c = graph[i].first;
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		ans += c;
		cnt++;
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
	cout << fixed;
	cout.precision(2);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

double dist(pii a, pii b) {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

int Find(int a) {
	if (a == parent[a]) return parent[a];
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