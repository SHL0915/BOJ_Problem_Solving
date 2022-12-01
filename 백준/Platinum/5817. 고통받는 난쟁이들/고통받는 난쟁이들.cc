#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
int arr[200001];
int pos[200001];
vector <ll> min_tree, max_tree;

void update_min(int node, int start, int end, int idx, ll val);
void update_max(int node, int start, int end, int idx, ll val);
ll min_query(int node, int start, int end, int left, int right);
ll max_query(int node, int start, int end, int left, int right);
void Swap(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	min_tree.resize(4 * N, INF);
	max_tree.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		pos[arr[i]] = i;
		update_min(1, 1, N, arr[i], pos[arr[i]]);
		update_max(1, 1, N, arr[i], pos[arr[i]]);
	}
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		if (A == 1) Swap(B, C);
		else {
			int temp1 = min_query(1, 1, N, B, C);
			int temp2 = max_query(1, 1, N, B, C);
			if (temp2 - temp1 == C - B) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}

void update_min(int node, int start, int end, int idx, ll val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		arr[val] = idx;
		min_tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update_min(node * 2, start, mid, idx, val);
	update_min(node * 2 + 1, mid + 1, end, idx, val);
	min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	return;
}

void update_max(int node, int start, int end, int idx, ll val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		arr[val] = idx;
		max_tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update_max(node * 2, start, mid, idx, val);
	update_max(node * 2 + 1, mid + 1, end, idx, val);
	max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
	return;
}

ll min_query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return min_tree[node];
	int mid = (start + end) / 2;
	return min(min_query(node * 2, start, mid, left, right), min_query(node * 2 + 1, mid + 1, end, left, right));
}

ll max_query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return max_tree[node];
	int mid = (start + end) / 2;
	return max(max_query(node * 2, start, mid, left, right), max_query(node * 2 + 1, mid + 1, end, left, right));
}

void Swap(int A, int B) {
	int height_A = arr[A];
	int height_B = arr[B];
	update_max(1, 1, N, height_A, B);
	update_max(1, 1, N, height_B, A);
	update_min(1, 1, N, height_A, B);
	update_min(1, 1, N, height_B, A);
	return;
}