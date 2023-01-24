#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 250000;

int N, M, K;
int and_tree[2 * SZ + 1], sum_tree[2 * SZ + 1];

void init_and();
void init_sum();
void update_and(int pos, int val);
void update_sum(int pos, int val);
int query_and(int left, int right);
int query_sum(int left, int right);
void DNC(int left, int right, int val);

void solve() {
	cin >> N >> K;
	fill(and_tree, and_tree + 2 * N, (1 << 30) - 1);
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		and_tree[i + N] = a;
		sum_tree[i + N] = (a == K);
	}
	init_and();
	init_sum();
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;		
			DNC(b, c, d);			
		}
		else {
			cin >> b >> c;
			cout << query_sum(b, c + 1) << '\n';
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void init_and() {
	for (int i = N - 1; i > 0; i--) and_tree[i] = (and_tree[i << 1] & and_tree[i << 1 | 1]);
}

void init_sum() {
	for (int i = N - 1; i > 0; i--) sum_tree[i] = (sum_tree[i << 1] + sum_tree[i << 1 | 1]);
}

void update_and(int pos, int val) {
	for (and_tree[pos += N] = val; pos > 1; pos >>= 1) and_tree[pos >> 1] = and_tree[pos] & and_tree[pos ^ 1];
}

void update_sum(int pos, int val) {
	for (sum_tree[pos += N] = (val == K); pos > 1; pos >>= 1) sum_tree[pos >> 1] = sum_tree[pos] + sum_tree[pos ^ 1];
}

int query_and(int left, int right) {
	int ret = (1 << 30) - 1;
	for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
		if (left % 2) ret &= and_tree[left++];
		if (right % 2) ret &= and_tree[--right];
	}
	return ret;
}

int query_sum(int left, int right) {
	int ret = 0;
	for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
		if (left & 1) ret += sum_tree[left++];
		if (right & 1) ret += sum_tree[--right];
	}
	return ret;
}

void DNC(int left, int right, int val) {
	if (left < right) {		
		int q = query_and(left, right + 1);
		if ((q | val) == q) return;
		int mid = (left + right) / 2;
		DNC(left, mid, val);
		DNC(mid + 1, right, val);
	}
	else {		
		int q = query_and(left, left + 1);
		q |= val;
		update_and(left, q);
		update_sum(left, q);
	}
}