#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pair<pii, pii> arr[100001];
vector <pair<int, pii>> graph;
int parent[100001];

bool cmpx(pair<pii, pii> a, pair<pii, pii> b);
bool cmpy(pair<pii, pii> a, pair<pii, pii> b);
bool cmpz(pair<pii, pii> a, pair<pii, pii> b);
int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first;
		arr[i].second.second = i;
	}
	sort(arr, arr + N, cmpx);
	for (int i = 1; i < N; i++) graph.push_back({ arr[i].first.first - arr[i - 1].first.first, { arr[i].second.second,arr[i - 1].second.second} });
	sort(arr, arr + N, cmpy);
	for (int i = 1; i < N; i++) graph.push_back({ arr[i].first.second - arr[i - 1].first.second, { arr[i].second.second,arr[i - 1].second.second} });
	sort(arr, arr + N, cmpz);
	for (int i = 1; i < N; i++) graph.push_back({ arr[i].second.first - arr[i - 1].second.first, { arr[i].second.second,arr[i - 1].second.second} });
	sort(graph.begin(), graph.end());
	int cnt = 0;
	ll ans = 0;
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == N - 1) break;
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		int c = graph[i].first;
		if (Find(a) == Find(b)) continue;
		cnt++;
		ans += c;
		Union(a, b);
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

bool cmpx(pair<pii, pii> a, pair<pii, pii> b) {
	return a.first.first < b.first.first;
}

bool cmpy(pair<pii, pii> a, pair<pii, pii> b) {
	return a.first.second < b.first.second;
}

bool cmpz(pair<pii, pii> a, pair<pii, pii> b) {
	return a.second.first < b.second.first;
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