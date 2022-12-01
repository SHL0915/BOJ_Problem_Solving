#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;

int M, N, MST, sum, cnt;
vector <piii> graph;
int parent[200001];

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> M >> N;
		if (M == 0 && N == 0) break;
		MST = 0, sum = 0, cnt = 0;
		graph.clear();
		for (int i = 0; i <= M; i++) parent[i] = i;
		for (int i = 0; i < N; i++) {
			int A, B, C;
			cin >> A >> B >> C;
			graph.push_back({ C,{A,B} });
			sum += C;
		}
		sort(graph.begin(), graph.end());
		for (int i = 0; i < N; i++) {
			if (cnt == M - 1) break;
			int A = Find(graph[i].second.first);
			int B = Find(graph[i].second.second);
			if (A == B) continue;
			Union(A, B);
			MST += graph[i].first;
			cnt++;
		}
		cout << sum - MST << '\n';
	}
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