#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, curr;
vector <int> val;
int out_degree[20005];
vector <pii> edge;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, d;
		char c;
		cin >> a >> c >> b;
		if (c == 'L') d = a - b;
		else d = a + b;
		val.push_back(a);
		val.push_back(d);
		edge.push_back({ a,d });
	}
	cin >> curr;

	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());

	for (int i = 0; i < N; i++) {
		int a, b;
		a = edge[i].first, b = edge[i].second;
		a = lower_bound(val.begin(), val.end(), a) - val.begin();
		b = lower_bound(val.begin(), val.end(), b) - val.begin();
		out_degree[a]++;
	}

	for (int i = 0; i < val.size(); i++) {
		if (out_degree[i] == 0) {
			cout << val[i];
			return;
		}
	}

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