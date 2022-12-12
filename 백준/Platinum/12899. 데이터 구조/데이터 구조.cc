#include <bits/stdc++.h>
using namespace std;

int N;
int tree[8000001];

void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int order);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int T, X;
		cin >> T >> X;
		if (T == 1) update(1, 1, 2000000, X, 1);
		else {
			int output = query(1, 1, 2000000, X);
			cout << output << "\n";
			update(1, 1, 2000000, output, -1);
		}
	}
	return 0;
}

void update(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] += val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

int query(int node, int start, int end, int order) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	if (order <= tree[node * 2]) return query(node * 2, start, mid, order);
	else return query(node * 2 + 1, mid + 1, end, order - tree[node * 2]);
}