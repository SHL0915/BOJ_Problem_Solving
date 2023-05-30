#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll pow_10[15];
unordered_map <ll, int> dist;
unordered_map <ll, int> id;
queue <ll> q;

void BFS();
ll convert(string& s);
ll f(ll n, int i, int j, int k, int l);
ll revf(ll n, int i, int j, int k, int l);

void solve() {
	cin >> N;
	string S = "";
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (a == 10) a = 0;
		S += '0' + a;
	}

	string T = "";
	for (int i = 1; i <= N; i++) {
		int now = i;
		if (now == 10) now = 0;
		T += '0' + now;
	}

	if (S == T) {
		cout << 0;
		return;
	}

	dist[convert(S)] = 0;
	dist[convert(T)] = 0;

	id[convert(S)] = 0;
	id[convert(T)] = 1;


	q.push(convert(S)); q.push(convert(T));

	while (q.size()) BFS();

	cout << 6;

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	pow_10[0] = 1;
	for (int i = 1; i < 15; i++) pow_10[i] = pow_10[i - 1] * 10;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void BFS() {
	ll now = q.front(); q.pop();

	if (id[now] == 1 && dist[now] == 2) return;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			for (int k = 0; k < N - (i + j); k++) {
				int l = N - (i + j + k);
				ll next;

				if (id[now] == 0) next = f(now, i, j, k, l);
				else next = revf(now, i, j, k, l);

				if (dist.count(next)) {
					if (id[next] != id[now]) {
						cout << dist[now] + dist[next] + 1;
						exit(0);
					}
					else continue;
				}
				else {
					dist[next] = dist[now] + 1;
					id[next] = id[now];
					q.push(next);
				}
			}
		}
	}

	return;
}

ll convert(string& s) {
	ll ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}

ll f(ll n, int i, int j, int k, int l) {
	ll d = n % pow_10[l];
	n /= pow_10[l];
	ll c = n % pow_10[k];
	n /= pow_10[k];
	ll b = n % pow_10[j];
	n /= pow_10[j];
	ll a = n % pow_10[i];
	n /= pow_10[i];

	ll ret = c;
	ret *= pow_10[i];
	ret += a;
	ret *= pow_10[l];
	ret += d;
	ret *= pow_10[j];
	ret += b;

	return ret;
}



ll revf(ll n, int i, int j, int k, int l) {
	ll d = n % pow_10[l];
	n /= pow_10[l];
	ll c = n % pow_10[k];
	n /= pow_10[k];
	ll b = n % pow_10[j];
	n /= pow_10[j];
	ll a = n % pow_10[i];
	n /= pow_10[i];

	ll ret = b;
	ret *= pow_10[l];
	ret += d;
	ret *= pow_10[i];
	ret += a;
	ret *= pow_10[k];
	ret += c;

	return ret;
}