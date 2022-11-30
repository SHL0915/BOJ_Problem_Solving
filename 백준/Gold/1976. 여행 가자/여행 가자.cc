#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
int parent[200];

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A;
			if (A) Union(i, j);
		}
	}
	cin >> A;
	A = Find(A);
	for (int i = 1; i < M; i++) {
		cin >> B;
		if (Find(A) != Find(B - 1)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

int Find(int node) {
	if (parent[node] == node) return parent[node];
	else return parent[node] = Find(parent[node]);
}

void Union(int A, int B) {
	A = Find(A);
	B = Find(B);
	if(A == B) return;
	if (A > B) parent[A] = B;
	else parent[B] = A;
	return;
}