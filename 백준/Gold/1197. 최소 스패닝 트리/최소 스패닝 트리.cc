#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;

int V, E, ans, cnt;
vector <piii> graph;
int parent[10001];

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	for (int i = 1; i <= V; i++) parent[i] = i;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph.push_back({ C, {A,B} });
	}
	sort(graph.begin(), graph.end());	
	for (int i = 0; i < E; i++) {
		if (cnt == V - 1) break;
		int A = Find(graph[i].second.first);
		int B = Find(graph[i].second.second);
		if (Find(A) == Find(B)) continue;
		Union(A, B);
		ans += graph[i].first;
		cnt++;
	}
	cout << ans;
	return 0;
}

int Find(int node) {
	if (parent[node] == node) return parent[node];
	else return parent[node] = Find(parent[node]);
}

void Union(int A, int B) {
	A = Find(A);
	B = Find(B);
	if (A == B) return;
	if (A > B) parent[A] = B;
	else parent[B] = A;
	return;
}