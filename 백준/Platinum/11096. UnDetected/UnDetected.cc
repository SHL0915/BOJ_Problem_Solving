#include <bits/stdc++.h>
using namespace std;

struct dat {
	int x, y, r;
};

int N;
dat arr[205];
int parent[205];
vector<pair<double, pair<int, int>>> graph;

double dist(int x1, int y1, int x2, int y2) {
	long long ret = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return sqrt(ret);
}

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i].x >> arr[i].y >> arr[i].r;
	for (int i = 0; i <= N + 1; i++) parent[i] = i;
	for (int i = 1; i <= N; i++) {
		if (arr[i].x <= arr[i].r) Union(Find(i), Find(0));
		if (200 - arr[i].x <= arr[i].r) Union(Find(i), Find(N + 1));
		for (int j = 1; j < i; j++) {
			double d = dist(arr[i].x, arr[i].y, arr[j].x, arr[j].y);
			d -= (arr[i].r + arr[j].r);
			if (d < 0) Union(Find(i), Find(j));
		}
		if (Find(0) == Find(N + 1)) {
			cout << i - 1;
			return 0;
		}
	}
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
	if (A > B) parent[A] = B;
	else parent[B] = A;
	return;
}