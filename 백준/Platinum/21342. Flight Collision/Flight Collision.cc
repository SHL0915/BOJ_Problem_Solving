#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

struct cmp {
	bool operator() (pair<pii, pii> a, pair<pii, pii> b) {
		return a.first.first * b.first.second > a.first.second * b.first.first;
	}
};

int N;
pii arr[100005];
int mark[100005];
int parent1[100005], parent2[100005];

void Union1(int a, int b);
void Union2(int a, int b);
int Find1(int a);
int Find2(int a);

void solve() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		parent1[i] = i;
		parent2[i] = i;
	}

	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	priority_queue <pair<pii, pii>, vector<pair<pii, pii>>, cmp> pq;

	for (int i = 0; i < N - 1; i++) {
		ll a = arr[i + 1].first - arr[i].first;
		ll b = arr[i].second - arr[i + 1].second;
		if (b <= 0) continue;
		pq.push({ {a, b}, {i, i + 1} });
	}

	while (pq.size()) {
		pair <pii, pii> t = pq.top(); pq.pop();
		int a = t.second.first, b = t.second.second;
		if (mark[a] == 1 || mark[b] == 1) continue;
		mark[a] = 1; mark[b] = 1;

		Union1(a, b);
		Union2(a, b);

		a = Find1(a); b = Find2(b);

		while (1) {
			a = Find1(a);
			if (a > 0) {
				if (mark[a - 1] == 1) {
					Union1(a, a - 1);
					Union2(a, a - 1);
				}
				else break;
			}
			else break;
		}

		while (1) {
			b = Find2(b);
			if (b < N - 1) {
				if (mark[b + 1] == 1) {
					Union1(b, b + 1);
					Union2(b, b + 1);
				}
				else break;
			}
			else break;
		}

		a = Find1(a); b = Find2(b);

		if (a > 0 && b < N - 1) {
			ll f = arr[b + 1].first - arr[a - 1].first;
			ll s = arr[a - 1].second - arr[b + 1].second;
			if (s <= 0) continue;
			pq.push({ {f, s}, {a - 1, b + 1} });
		}
	}

	vector <int> ans;
	for (int i = 0; i < N; i++) {
		if (mark[i] == 0) ans.push_back(i);
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << ' ';

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

void Union1(int a, int b) {
	a = Find1(a);
	b = Find1(b);
	if (a == b) return;
	if (a > b) parent1[a] = b;
	else parent1[b] = a;
	return;
}

void Union2(int a, int b) {
	a = Find2(a);
	b = Find2(b);
	if (a == b) return;
	if (a < b) parent2[a] = b;
	else parent2[b] = a;
	return;
}

int Find1(int a) {
	if (a == parent1[a]) return parent1[a];
	else return parent1[a] = Find1(parent1[a]);
}

int Find2(int a) {
	if (a == parent2[a]) return parent2[a];
	else return parent2[a] = Find2(parent2[a]);
}