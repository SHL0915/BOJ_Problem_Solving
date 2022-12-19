#include <bits/stdc++.h>
using namespace std;

int N, M, K, ans;
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
		int A, B;
		cin >> A >> B;
		Union(Find(A), Find(B));
	}

	for (int i = 1; i <= N; i++) {
		int now = Find(i);
		if (now == Find(0)) continue;
		ans += arr[now];
		Union(Find(now), Find(0));
	}
	if (ans > K) cout << "Oh no";
	else cout << ans;
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
	if (arr[A] > arr[B]) parent[A] = B;
	else parent[B] = A;
	return;
}