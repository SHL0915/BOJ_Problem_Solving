#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
vector <ll> tree;

void update(int pos, ll val);
ll query(int left, int right);

void solve() {
	cin >> N >> M >> K;
	tree.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		ll a; cin >> a;
		update(i, a);
	}
	for (int i = 0; i < M + K; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(b, c + 1) << '\n';
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

void update(int pos, ll val) {
	for(tree[pos += N] = val; pos > 0; pos >>= 1) tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
    return;
}

ll query(int left, int right) {
	ll ret = 0;
    for(left += N, right += N; left < right; left >>= 1, right >>= 1){
        if(left & 1) ret += tree[left++];
        if(right & 1) ret += tree[--right];
    }
    return ret;
}