#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, ans, cnt;
pair<pii, pii> L[3000];
int parent[3000];
int sz[3000];
int mark[3000];

int func(pair<pii, pii> A, pair<pii, pii> B);
int CCW(pii A, pii B, pii C);
int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		sz[i] = 1;
		cin >> L[i].first.first >> L[i].first.second >> L[i].second.first >> L[i].second.second;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (func(L[i], L[j])) {
				int A = Find(i), B = Find(j);
				Union(A, B);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		ans = max(ans, sz[i]);
		if (mark[Find(i)] == 0) {
			cnt++;
			mark[Find(i)] = 1;
		}
	}
	cout << cnt << '\n' << ans;
	return 0;
}

int func(pair<pii, pii> A, pair<pii, pii> B) {
	pii p1 = A.first, p2 = A.second, p3 = B.first, p4 = B.second;
	int ccw1 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	int ccw2 = CCW(p3, p4, p1) * CCW(p3, p4, p2);
	if (ccw1 == 0 && ccw2 == 0) {
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return (p1 <= p4 && p3 <= p2);
	}
	else return (ccw1 <= 0 && ccw2 <= 0);
}

int CCW(pii A, pii B, pii C) {
	long long a = A.first * B.second + B.first * C.second + C.first * A.second;
	long long b = B.first * A.second + C.first * B.second + A.first * C.second;
	if (a > b) return 1;
	else if (a == b) return 0;
	else return -1;
}

int Find(int node) {
	if (node == parent[node]) return parent[node];
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