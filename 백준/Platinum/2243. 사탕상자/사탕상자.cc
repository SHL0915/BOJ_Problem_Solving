#include <iostream>
#include <vector>
using namespace std;

const long long MAX = 1000001LL;

int N;
vector <long long> tree;

void update(int node, int start, int end, int idx, long long diff);
long long query(int node, int start, int end, int left, int right);
int Binary_search(int left, int right, long long data);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	tree.resize(4 * MAX);
	for (int i = 0; i < N; i++) {
		long long A, B, C;
		cin >> A;
		if (A == 1) {
			cin >> B;
			int flavor = Binary_search(1, MAX, B);
			update(1, 1, MAX, flavor, -1);
			cout << flavor << '\n';
		}
		else {
			cin >> B >> C;
			update(1, 1, MAX, B, C);
		}
	}
	return 0;
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] += diff;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int Binary_search(int left, int right, long long data) {
	int mid = (left + right) / 2;
	if (left < right) {
		if (query(1, 1, MAX, left, mid) < data) return Binary_search(mid + 1, right, data - query(1, 1, MAX, left, mid));
		else return Binary_search(left, mid, data);
	}
	else return mid;
}