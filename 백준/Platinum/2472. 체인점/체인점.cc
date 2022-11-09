#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

const int INF = 1000000000;

struct cmp {
	bool operator() (pair<int, int> A, pair<int, int> B) {
		return A.first > B.first;
	}
};

struct DT {
	int first, second, third, idx;
};

int N, A, B, C, M, X, Y, Z, T, Q;
vector <pair<int, int>> graph[100001];
int dist[100001];
vector <int> compressed, tree;
DT score[100001];
set <int> s;

void Dijkstra(int start);
void compress();
bool func1(DT A, DT B) {
	return A.first < B.first;
}
bool func2(DT A, DT B) {
	return A.second < B.second;
}
bool func3(DT A, DT B) {
	return A.third < B.third;
}
int query(int node, int start, int end, int left, int right);
void update(int node, int start, int end, int idx, int val);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> A >> B >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y >> Z;
		graph[X].push_back({ Y,Z });
		graph[Y].push_back({ X,Z });
	}
	Dijkstra(A);
	compressed.resize(N);
	compress();
	for (int i = 1; i <= N; i++) {
		score[i].first = dist[i];
		score[i].idx = i;
	}
	Dijkstra(B);
	compressed.resize(N);
	compress();
	for (int i = 1; i <= N; i++) score[i].second = dist[i];
	Dijkstra(C);
	compressed.resize(N);
	compress();
	for (int i = 1; i <= N; i++) score[i].third = dist[i];
	sort(score + 1, score + 1 + N, func1);
	tree.resize(4 * N, INF);
	for (int i = 1; i <= N; i++) {
		int val = query(1, 0, N - 1, 0, score[i].second - 1);
		if (val == INF) s.insert(score[i].idx);
		else if (val >= score[i].third) s.insert(score[i].idx);
		update(1, 0, N - 1, score[i].second, score[i].third);
	}
	sort(score + 1, score + 1 + N, func2);
	tree.resize(4 * N, INF);
	for (int i = 1; i <= N; i++) {
		int val = query(1, 0, N - 1, 0, score[i].first - 1);
		if (val == INF) s.insert(score[i].idx);
		else if (val >= score[i].third) s.insert(score[i].idx);
		update(1, 0, N - 1, score[i].first, score[i].third);
	}
	sort(score + 1, score + 1 + N, func3);
	tree.resize(4 * N, INF);
	for (int i = 1; i <= N; i++) {
		int val = query(1, 0, N - 1, 0, score[i].first - 1);
		if (val == INF) s.insert(score[i].idx);
		else if (val >= score[i].second) s.insert(score[i].idx);
		update(1, 0, N - 1, score[i].first, score[i].second);
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> Q;
		if (s.count(Q) == 0) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (pq.size()) {
		int idx = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (dist[idx] < val) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			int next = graph[idx][i].first;
			int next_val = val + graph[idx][i].second;
			if (dist[next] > next_val) {
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
		}
	}
}

void compress() {
	for (int i = 1; i <= N; i++) compressed[i - 1] = dist[i];
	sort(compressed.begin(), compressed.end());
	compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
	for (int i = 1; i <= N; i++) dist[i] = lower_bound(compressed.begin(), compressed.end(), dist[i]) - compressed.begin();
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

void update(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = min(tree[node], val);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	return;
}