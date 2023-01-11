#include <bits/stdc++.h>
using namespace std;

int k, ans;
int tree[1 << 22];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> k;
	for (int i = 2; i < (1 << (k + 1)); i++) {
		cin >> tree[i];
		ans += tree[i];
	}
	for (int i = k; i > 0; i--) {
		int l = (1 << i), h = (1 << (i + 1));
		for (int j = l; j < h; j += 2) {
			ans += tree[j] < tree[j + 1] ? tree[j + 1] - tree[j] : tree[j] - tree[j + 1];
			tree[j / 2] += max(tree[j], tree[j + 1]);
		}
	}	
	cout << ans;
	return 0;
}