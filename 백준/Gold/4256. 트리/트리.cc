#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int preorder[1001];
int inorder[1001];

void postorder(int p_left, int p_right, int i_left, int i_right);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> preorder[i];
	for (int i = 0; i < N; i++) cin >> inorder[i];
	postorder(0, N - 1, 0, N - 1);
	cout << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

void postorder(int p_left, int p_right, int i_left, int i_right) {
	if (p_left > p_right || i_left > i_right) return;
	int node = preorder[p_left];
	int idx;
	for (int i = i_left; i <= i_right; i++) {
		if (inorder[i] == node) {
			idx = i;
			break;
		}
	}
	int delt = idx - i_left;
	postorder(p_left + 1, p_left + delt, i_left, idx - 1);
	postorder(p_left + delt + 1, p_right, idx + 1, i_right);
	cout << node << " ";
	return;
}