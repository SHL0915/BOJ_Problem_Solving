#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
long long arr[100001];
vector <int> tree;

void update(int node, int start, int end, int idx);
int query(int node, int start, int end, int left, int right);
long long DNC(int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr[0] = INF;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	tree.resize(4 * N);
	for (int i = 1; i <= N; i++) update(1, 1, N, i);
	cout << DNC(1, N);
	return 0;
}

void update(int node, int start, int end, int idx) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = idx;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx);
	update(node * 2 + 1, mid + 1, end, idx);
	if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
	else tree[node] = tree[node * 2 + 1];
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	int A = query(node * 2, start, mid, left, right);
	int B = query(node * 2 + 1, mid + 1, end, left, right);
	if (arr[A] < arr[B]) return A;
	else return B;
}

long long DNC(int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		long long A = DNC(left, mid);
		long long B = DNC(mid + 1, right);
		int lpos = mid, rpos = mid, h;
		long long C = 0;
		while (1) {
			h = arr[query(1, 1, N, lpos, rpos)];
			C = max(C, (long long)(rpos - lpos + 1) * h);
			if (lpos == left && rpos == right) break;
			if (lpos == left) rpos++;
			else if (rpos == right) lpos--;
			else {
				if (arr[lpos - 1] > arr[rpos + 1]) lpos--;
				else rpos++;
			}
		}		
		return max({ A,B,C });
	}
	else return arr[mid];
}