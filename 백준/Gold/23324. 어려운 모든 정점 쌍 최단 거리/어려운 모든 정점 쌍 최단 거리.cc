#include <bits/stdc++.h>
using namespace std;

int N, M, K, u, v;
int parent[100001];
long long sz[100001];
vector <pair<int, int>> graph;

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i]++;
	}
	for (int i = 1; i <= M; i++) {
		int A, B;
		cin >> A >> B;
		if (i == K) {
			u = A;
			v = B;
			continue;
		}
		graph.push_back({ A,B });
	}
	for (int i = 0; i < graph.size(); i++) {
		int A = graph[i].first;
		int B = graph[i].second;
		if (Find(A) == Find(B)) continue;
		Union(Find(A), Find(B));
	}
	if (Find(u) == Find(v)) cout << 0;
	else cout << sz[Find(u)] * sz[Find(v)];
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