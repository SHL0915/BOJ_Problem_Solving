#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> piiii;

int N, Q, pos;
pair<int, int> left_right;
int parent[100000];
piiii arr[100000];

bool cmp(piiii A, piiii B) {
	if (A.first.first == B.first.first) return A.first.second > B.first.second;
	return A.first.first < B.first.first;
}

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		arr[i] = { {A,B},{C,i} };
	}
	sort(arr, arr + N, cmp);
	left_right = { arr[pos].first.first, arr[pos].first.second };
	for (int i = 1; i < N; i++) {
		if (arr[i].first.first <= left_right.second) {
			Union(Find(arr[pos].second.second), Find(arr[i].second.second));
			left_right.second = max(left_right.second, arr[i].first.second);
		}
		else {
			pos = i;
			left_right = { arr[pos].first.first, arr[pos].first.second };
		}
	}
	for (int i = 0; i < Q; i++) {
		int A, B;
		cin >> A >> B;
		if (Find(A - 1) == Find(B - 1)) cout << 1 << '\n';
		else cout << 0 << '\n';
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