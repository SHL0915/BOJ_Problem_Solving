#include <bits/stdc++.h>
using namespace std;

int N, M, K, cost;
int arr[10001];
int parent[10001];

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int v, w;
		cin >> v >> w;
		v = Find(v);
		w = Find(w);
		Union(v, w);
	}
	for (int i = 1; i <= N; i++) {
		int me = Find(0);
		int now = Find(i);
		if (me == now) continue;
		Union(me, now);
		cost += arr[now];
	}
	if (cost > K) cout << "Oh no";
	else cout << cost;
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
	if (arr[A] > arr[B]) parent[A] = B;
	else parent[B] = A;
	return;
}