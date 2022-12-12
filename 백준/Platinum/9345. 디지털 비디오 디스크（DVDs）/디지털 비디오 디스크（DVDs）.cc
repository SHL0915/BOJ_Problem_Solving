#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int T, N, K;
vector <int> max_seg, min_seg;

void update_min(int node, int start, int end, int idx, int val);
void update_max(int node, int start, int end, int idx, int val);
int query_min(int node, int start, int end, int left, int right);
int query_max(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		max_seg.clear();
		min_seg.clear();
		max_seg.resize(4 * N);
		min_seg.resize(4 * N, INF);
		for (int i = 1; i <= N; i++) {
			update_min(1, 1, N, i, i);
			update_max(1, 1, N, i, i);
		}
		for (int i = 0; i < K; i++) {
			int Q, A, B;
			cin >> Q >> A >> B;
			A++; B++;
			if (Q == 0) {
				int L = query_max(1, 1, N, A, A);
				int R = query_max(1, 1, N, B, B);
				update_max(1, 1, N, A, R);
				update_max(1, 1, N, B, L);
				update_min(1, 1, N, A, R);
				update_min(1, 1, N, B, L);
			}
			else {
				int L = query_min(1, 1, N, A, B);
				int R = query_max(1, 1, N, A, B);
				if (R == B && L == A) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	return 0;
}

void update_min(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		min_seg[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update_min(node * 2, start, mid, idx, val);
	update_min(node * 2 + 1, mid + 1, end, idx, val);
	min_seg[node] = min(min_seg[node * 2], min_seg[node * 2 + 1]);
	return;
}

void update_max(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		max_seg[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update_max(node * 2, start, mid, idx, val);
	update_max(node * 2 + 1, mid + 1, end, idx, val);
	max_seg[node] = max(max_seg[node * 2], max_seg[node * 2 + 1]);
	return;
}

int query_min(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return min_seg[node];
	int mid = (start + end) / 2;
	return min(query_min(node * 2, start, mid, left, right), query_min(node * 2 + 1, mid + 1, end, left, right));
}

int query_max(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return max_seg[node];
	int mid = (start + end) / 2;
	return max(query_max(node * 2, start, mid, left, right), query_max(node * 2 + 1, mid + 1, end, left, right));
}