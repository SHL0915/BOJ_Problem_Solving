#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, A, B;
pair<int, int> arr[1000005];
int parent[1000005];
int sz[1000005];
int mark[1000005];

int Find(int node);
void Union(int A, int B);
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first > b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i]++;
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) {
		ll now = arr[i].first;
		ll idx = arr[i].second;
		ll left = 0, right = 0;
		if (mark[idx - 1] == 1) {
			left = sz[Find(idx - 1)];
			Union(idx, idx - 1);
		}
		if (mark[idx + 1] == 1) {
			right = sz[Find(idx + 1)];
			Union(idx, idx + 1);
		}
		mark[idx] = 1;
		A += now * (left + 1) * (right + 1);
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i] = 1;
		mark[i] = 0;
	}
	sort(arr + 1, arr + N + 1, cmp);
	for (int i = 1; i <= N; i++) {
		ll now = arr[i].first;
		ll idx = arr[i].second;
		ll left = 0, right = 0;
		if (mark[idx - 1] == 1) {
			left = sz[Find(idx - 1)];
			Union(idx, idx - 1);
		}
		if (mark[idx + 1] == 1) {
			right = sz[Find(idx + 1)];
			Union(idx, idx + 1);
		}
		mark[idx] = 1;
		B += now * (left + 1) * (right + 1);
	}
	cout << A - B;
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