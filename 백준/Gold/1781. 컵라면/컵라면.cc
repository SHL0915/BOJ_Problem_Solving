#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> arr[200000];
int parent[200001];

int Find(int node);
void Union(int A, int B);

bool cmp(pair<int, int> A, pair<int, int> B) {
	return A.first > B.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i <= N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		arr[i] = { B, A };
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++) {
		int capacity = Find(arr[i].second);
		if (capacity == 0) continue;
		ans += arr[i].first;
		Union(capacity, capacity - 1);
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