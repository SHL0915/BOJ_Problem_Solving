#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, m = INF;
long long ans;
int org[100001];
pair<int, int> arr[100001];
int par[100001];
vector <pair<int, int>> graph;
vector <int> v[100001];

int Find(int a);
void Union(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> org[i];
		arr[i] = { org[i], i };
		par[i] = i;		
		m = min(m, org[i]);
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) graph.push_back({ i, arr[i].second });
	for (int i = 0; i < graph.size(); i++) {
		int a = graph[i].first;
		int b = graph[i].second;
		Union(a, b);
	}
	for (int i = 1; i <= N; i++) v[Find(i)].push_back(org[i]);
	for (int i = 1; i <= N; i++) {
		if (v[i].size() >= 2) {
			long long sum = 0, base = INF, sz = v[i].size();
			for (int j = 0; j < v[i].size(); j++) {
				sum += v[i][j];
				base = min(base, (long long)v[i][j]);
			}
			if (base + m * (sz + 1) < base * (sz - 2)) ans += (sum + base + m * (sz + 1));
			else ans += (sum + base * (sz - 2));
		}
	}
	cout << ans;
	return 0;
}

int Find(int a) {
	if (par[a] == a) return par[a];
	else return par[a] = Find(par[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) par[a] = b;
	else par[b] = a;
	return;
}