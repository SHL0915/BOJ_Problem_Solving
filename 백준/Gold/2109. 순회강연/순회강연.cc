#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> arr[10000];
int parent[10001];

bool cmp(pair<int, int> A, pair<int, int > B) {
	return A.second > B.second;
}

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int D, P;
		cin >> P >> D;
		arr[i] = { D,P };
	}
	for (int i = 0; i <= 10000; i++) parent[i] = i;
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++) {
		if (Find(arr[i].first) == 0) continue;
		ans += arr[i].second;
		Union(Find(arr[i].first), Find(arr[i].first) - 1);
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