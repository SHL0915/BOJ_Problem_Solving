#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[1000001];

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		if (A == 0) Union(B, C);
		else {
			if (Find(B) == Find(C)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}

int Find(int node) {
	if (parent[node] == node) return node;
	else {
		parent[node] = Find(parent[node]);
		return parent[node];
	}
}

void Union(int A, int B) {
	A = Find(A);
	B = Find(B);
	if (A == B) return;
	else {
		parent[B] = A;
		return;
	}
}