#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int inorder[100001];
int postorder[100001];

void preorder(int in_left, int in_right, int post_left, int post_right);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> inorder[i];
	for (int i = 0; i < N; i++) cin >> postorder[i];
	preorder(0, N - 1, 0, N - 1);
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void preorder(int in_left, int in_right, int post_left, int post_right) {
	if (in_left > in_right || post_left > post_right) return;
	int node = postorder[post_right];
	cout << node << " ";
	int idx;
	for (int i = in_left; i <= in_right; i++) {
		if (inorder[i] == node) {
			idx = i;
			break;
		}
	}	
	int delt = idx - in_left;
	preorder(in_left, idx - 1, post_left, post_left + delt - 1);
	preorder(idx + 1, in_right, post_left + delt, post_right - 1);
	return;
}