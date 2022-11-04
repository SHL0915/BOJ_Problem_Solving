#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
long long ans;
vector <pair<long long, long long>> island, compressed;
vector <long long> x_pos, y_pos, tree;

bool cmp(pair<long long, long long> A, pair<long long, long long> B) {
	if (A.first == B.first) return A.second < B.second;
	return A.first > B.first;
}
void update(int node, int start, int end, int idx);
long long query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		ans = 0;
		island.clear();
		compressed.clear();
		x_pos.clear();
		y_pos.clear();
		tree.clear();
		for (int i = 0; i < N; i++) {
			long long x, y;
			cin >> x >> y;
			island.push_back({ x,y });
			x_pos.push_back(x);
			y_pos.push_back(y);
		}
		sort(x_pos.begin(), x_pos.end());
		sort(y_pos.begin(), y_pos.end());
		x_pos.erase(unique(x_pos.begin(), x_pos.end()), x_pos.end());
		y_pos.erase(unique(y_pos.begin(), y_pos.end()), y_pos.end());
		for (int i = 0; i < N; i++) {
			int x_idx, y_idx;
			x_idx = lower_bound(x_pos.begin(), x_pos.end(), island[i].first) - x_pos.begin();
			y_idx = lower_bound(y_pos.begin(), y_pos.end(), island[i].second) - y_pos.begin();
			compressed.push_back({ x_idx,y_idx });
		}
		sort(compressed.begin(), compressed.end(), cmp);				
		tree.resize(4 * N);
		for (int i = 0; i < N; i++) {			
			ans += query(1, 0, N - 1, 0, compressed[i].second);
			update(1, 0, N - 1, compressed[i].second);
		}
		cout << ans << '\n';
	}
	return 0;
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

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}