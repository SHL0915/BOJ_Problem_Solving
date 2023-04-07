#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;

int N, P, ans, cnt, min_val = 0x3f3f3f;
int parent[10001];
int cost[10001];
vector <piii> graph;

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> P;
	for (int i = 0; i <= N; i++) parent[i] = i;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		min_val = min(min_val, cost[i]);
	}
	for (int i = 0; i < P; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph.push_back({ cost[A] + cost[B] + C * 2, {A,B} });
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == N - 1) break;
		int A = Find(graph[i].second.first);
		int B = Find(graph[i].second.second);
		if (A == B) continue;
		Union(A, B);
		ans += graph[i].first;
		cnt++;		
	}
	ans += min_val;
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