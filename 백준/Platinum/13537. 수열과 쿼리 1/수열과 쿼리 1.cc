#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Q {
	int left, right, idx, k, ans;
};

int N, M;
vector <Q> v;
priority_queue <pair<int, int>> pq;
vector <int> tree;

bool cmp1(Q A, Q B) {
	return A.k > B.k;
}

bool cmp2(Q A, Q B) {
	return A.idx < B.idx;
}

void update(int node, int start, int end, int idx) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] += 1;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx);
	update(node * 2 + 1, mid + 1, end, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		pq.push({ input,i + 1 });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int left, right, k;
		cin >> left >> right >> k;
		v.push_back({ left, right, i, k, 0 });
	}
	sort(v.begin(), v.end(), cmp1);
	tree.resize(4 * N);
	for (int i = 0; i < v.size(); i++) {
		while (pq.size() && pq.top().first > v[i].k) {
			update(1, 1, N, pq.top().second);
			pq.pop();
		}
		v[i].ans = query(1, 1, N, v[i].left, v[i].right);
	}
	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < v.size(); i++) cout << v[i].ans << '\n';
	return 0;
}