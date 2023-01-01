#include <bits/stdc++.h>
using namespace std;
typedef pair < int, pair<int, int>> piii;

int N;
long long ans;
vector <piii> graph;
int parent[100001];
int sz[100001];

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		graph.push_back({ v, {a,b} });
	}
	sort(graph.begin(), graph.end(), greater<>());
	for (int i = 0; i < graph.size(); i++) {		
		int a = Find(graph[i].second.first);
		int b = Find(graph[i].second.second);
		if (a == b) continue;
		Union(a, b);
		ans = max(ans, (long long)graph[i].first * (sz[Find(a)] - 1));
	}
	cout << ans;
	return 0;
}

int Find(int node) {
	if (node == parent[node]) return parent[node];
	else return parent[node] = Find(parent[node]);
}

void Union(int A, int B) {
	A = Find(A);
	B = Find(B);
	if (A == B) return;
	if (A > B) {
		parent[A] = B;
		sz[B] += sz[A];
	}
	else {
		parent[B] = A;
		sz[A] += sz[B];
	}
	return;
}