#include <bits/stdc++.h>
using namespace std;

int N, K, now;
vector <int> tree;

void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int order);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	tree.resize(4 * N);
	for (int i = 1; i <= N; i++) update(1, 1, N, i, 1);
	now = 1;
	cout << "<";
	for (int i = 0; i < N; i++) {
		now += K - 1;
		if (now > N - i) now %= (N - i);
		if (now == 0) now = N - i;
		int output = query(1, 1, N, now);
		if (i == N - 1) cout << output;
		else cout << output << ", ";
		update(1, 1, N, output, 0);
	}
	cout << ">";
	return 0;
}

void update(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = val;
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
	else return query(2 * node + 1, mid + 1, end, order - tree[node * 2]);	
}