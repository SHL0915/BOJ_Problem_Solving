#include <bits/stdc++.h>
using namespace std;

int N, M, K, cnt;
int parent[51];
vector <int> arr[51];

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	cin >> K;
	for (int i = 0; i <= N; i++) parent[i] = i;
	for (int i = 0; i < K; i++) {
		int A;
		cin >> A;
		Union(0, A);		
	}
	for (int i = 0; i < M; i++) {
		int A;
		cin >> A;
		arr[i].resize(A);
		for (int j = 0; j < A; j++) {
			cin >> arr[i][j];
			Union(arr[i][0], arr[i][j]);
		}
	}
	for (int i = 0; i < M; i++) if (Find(arr[i][0]) != 0) cnt++;
	cout << cnt;
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