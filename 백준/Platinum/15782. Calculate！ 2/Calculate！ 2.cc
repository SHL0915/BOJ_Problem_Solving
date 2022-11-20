#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt;
vector <int> tree[100001];
vector <long long> seg, lazy;
int s[100001], e[100001], mark[100001], arr[100001];

void DFS(int node);
void createSeg(int node, int start, int end);
void update_lazy(int node, int start, int end);
void update(int node, int start, int end, int left, int right, long long val);
long long query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}
	DFS(1);
	seg.resize(4 * N);
	lazy.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		long long A;
		cin >> A;
		arr[s[i]] = A;
	}
	createSeg(1, 1, N);
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B;
		if (A == 1) cout << query(1, 1, N, s[B], e[B]) << '\n';
		else {
			cin >> C;
			update(1, 1, N, s[B], e[B], C);
		}
	}
	return 0;
}

void DFS(int node) {
	if (mark[node] != 0) return;
	mark[node] = 1;
	cnt++;
	s[node] = cnt;
	for (int i = 0; i < tree[node].size(); i++) DFS(tree[node][i]);
	e[node] = cnt;
}

void createSeg(int node, int start, int end) {
	if (start == end) {
		seg[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	createSeg(node * 2, start, mid);
	createSeg(node * 2 + 1, mid + 1, end);
	seg[node] = (seg[node * 2] ^ seg[node * 2 + 1]);
	return;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		if((end - start + 1) % 2 == 1) seg[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
	return;
}

void update(int node, int start, int end, int left, int right, long long val) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] ^= val;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node] = (seg[node * 2] ^ seg[node * 2 + 1]);
	return;
}

long long query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) ^ query(node * 2 + 1, mid + 1, end, left, right));
}