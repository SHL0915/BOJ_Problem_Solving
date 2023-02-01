#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int M, N;
int x[10001];
int y[1000001];
int pi[10001];
pii cmp[10001];
int tree[2000005];
vector <int> x_val, y_val, ans;

void kmp();
void makePi();
bool check(int i, int j, int type);
void update(int pos, int val);
int query(int left, int right);

void solve() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		cin >> x[i];
		x_val.push_back(x[i]);
	}
	for (int i = 0; i < N; i++) {
		cin >> y[i];
		y_val.push_back(y[i]);
	}

	sort(x_val.begin(), x_val.end());
	sort(y_val.begin(), y_val.end());
	x_val.erase(unique(x_val.begin(), x_val.end()), x_val.end());
	y_val.erase(unique(y_val.begin(), y_val.end()), y_val.end());

	for (int i = 0; i < M; i++) x[i] = lower_bound(x_val.begin(), x_val.end(), x[i]) - x_val.begin() + 1;
	for (int i = 0; i < N; i++) y[i] = lower_bound(y_val.begin(), y_val.end(), y[i]) - y_val.begin() + 1;
	
	kmp();
	
	if (ans.size() == 0) cout << 0;
	else {
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
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

void kmp() {
	makePi();
	memset(tree, 0, sizeof(tree));
	int n = N, m = M, pos = 0, k = 0;
	while (pos + m <= n) {
		if (k < m && check(pos + k, k, 1)) {
			update(y[pos + k], 1);
			k++;
			if (k == m) ans.push_back(pos + 1);
		}
		else {
			if (k == 0) pos++;
			else {
				for (int i = pos; i < pos + k - pi[k - 1]; i++) update(y[i], -1);
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

void makePi() {	
	for (int i = 0; i < M; i++) {
		update(x[i], 1);
		cmp[i] = { query(1,x[i]), query(x[i] + 1,M + 1) };
	}
	memset(tree, 0, sizeof(tree));

	int n = M, pos = 1, k = 0;
	while (pos + k < n) {
		if (check(pos + k, k, 0)) {
			update(x[pos + k], 1);
			k++;
			pi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				for (int i = pos; i < pos + k - pi[k - 1]; i++) update(x[i], -1);
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

bool check(int i, int j, int type) {
	if (type) return cmp[j] == make_pair(query(1, y[i]), query(y[i] + 1, N + 1));
	else return cmp[j] == make_pair(query(1, x[i]), query(x[i] + 1, M + 1));
}

void update(int pos, int val) {
	for (tree[pos += N] += val; pos > 1; pos >>= 1) tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
}

int query(int left, int right) {
	int ret = 0;
	for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
		if (left & 1) ret += tree[left++];
		if (right & 1) ret += tree[--right];
	}
	return ret;
}