#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[1000000];

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		if (Find(A) == Find(B)) {
			cout << i + 1;
			return 0;
		}
		else Union(A, B);
	}
	cout << 0;
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