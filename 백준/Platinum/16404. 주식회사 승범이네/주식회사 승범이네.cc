#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt, input;
vector <int> graph[100001];
vector <long long> tree, lazy;
int s[100001], e[100001];

void DFS(int node);
void update_lazy(int node, int start, int end);
void update(int node, int start, int end, int left, int right, long long diff);
long long query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	cin >> input;
	for (int i = 2; i <= N; i++) {
		cin >> input;
		graph[input].push_back(i);
	}
	DFS(1);
	tree.resize(4 * N);
	lazy.resize(4 * N);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		if (A == 1) {
			long long C;
			cin >> C;
			update(1, 1, N, s[B], e[B], C);
		}
		else cout << query(1, 1, N, s[B], s[B]) << '\n';
	}
	return 0;
}

void DFS(int node) {
	cnt++;
	s[node] = cnt;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	e[node] = cnt;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node] * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int left, int right, long long diff) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] += diff;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, diff);
	update(node * 2 + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

long long query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}