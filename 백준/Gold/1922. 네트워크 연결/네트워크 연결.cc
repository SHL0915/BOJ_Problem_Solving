#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;

int N, M, cnt, ans;
int parent[1001];
vector <piii> graph;

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph.push_back({ C,{A,B} });
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < M; i++) {
		if (cnt == N - 1) break;
		int A = graph[i].second.first;
		int B = graph[i].second.second;
		int cost = graph[i].first;
		if (Find(A) == Find(B)) continue;
		Union(Find(A), Find(B));
		ans += cost;
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