#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, cnt;
pii arr[2505];
map <ll, ll> convert;
vector <ll> graph[10005];
ll rev[10005], A[10005], B[10005], mark[10005];

ll DFS(ll node) {
	mark[node] = 1;
	for (ll next : graph[node]) {
		if (B[next] == -1 || mark[B[next]] == 0 && DFS(B[next])) {
			A[node] = next;
			B[next] = node;
			return 1;
		}
	}
	return 0;
}

void solve() {
	cin >> N;
	for (ll i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
		ll res = arr[i].first + arr[i].second;
		if (convert[res] == 0) {
			convert[res] = ++cnt;
			rev[cnt] = res;
		}
		graph[i].push_back(convert[res]);
		res = arr[i].first - arr[i].second;
		if (convert[res] == 0) {
			convert[res] = ++cnt;
			rev[cnt] = res;
		}
		graph[i].push_back(convert[res]);
		res = arr[i].first * arr[i].second;
		if (convert[res] == 0) {
			convert[res] = ++cnt;
			rev[cnt] = res;
		}
		graph[i].push_back(convert[res]);
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		if (A[i] == -1) {
			memset(mark, 0, sizeof(mark));
			ans += DFS(i);
		}
	}

	if (ans != N) {
		cout << "impossible";
		return;
	}

	for (ll i = 1; i <= N; i++) {
		ll a = arr[i].first, b = arr[i].second;
		ll res = rev[A[i]];

		if (a + b == res) cout << a << " + " << b << " = " << res << '\n';
		else if (a - b == res) cout << a << " - " << b << " = " << res << '\n';
		else if (a * b == res) cout << a << " * " << b << " = " << res << '\n';
	}

	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}