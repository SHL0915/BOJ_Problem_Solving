#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, K;
int arr[500001];
vector <pair<int, int>> tree;
pair<int, int> m = { -INF, -INF };

void update(int node, int start, int end, int idx, int val);
pair<int, int> query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	tree.resize(4 * N);
	string s;
	cin >> s;
	for (int i = 1; i <= N; i++) {
		arr[i] = s[i - 1] - '0';
		update(1, 1, N, i, arr[i]);
	}
	int pos = 1;
	while (pos <= N) {
		if (pos + K > N) break;
		if (K) {
			pair<int, int> temp = query(1, 1, N, pos, pos + K);
			temp.second *= -1;
			K -= temp.second - pos;
			cout << arr[temp.second];
			pos = temp.second + 1;			
		}
		else cout << arr[pos++];		
	}
	return 0;
}

void update(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = { val,-idx };
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);	
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

pair<int, int> query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return m;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}