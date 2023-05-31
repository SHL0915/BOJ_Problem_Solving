#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M;
pii A[1005], B[1005];
vector <pii> arr;

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
	for (int i = 0; i < M; i++) cin >> B[i].first >> B[i].second;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr.push_back({ A[i].first + B[j].first, A[i].second + B[j].second });
		}
	}

	sort(arr.begin(), arr.end());
	sort(arr.begin() + 1, arr.end(), [&](pii a, pii b) {
		ll res = ccw(arr[0], a, b);
		if (res) return res > 0;
		else return a < b;
		});

	vector <pii> ch;
	ch.push_back(arr[0]); ch.push_back(arr[1]);

	for (int i = 2; i < arr.size(); i++) {
		pii c = arr[i];
		while (ch.size() >= 2) {
			pii b = ch.back(); ch.pop_back();
			pii a = ch.back();
			if (ccw(a, b, c) > 0) {
				ch.push_back(b);
				break;
			}
		}
		ch.push_back(c);
	}

	cout << ch.size() << '\n';

	for (int i = 0; i < ch.size(); i++) cout << ch[i].first << " " << ch[i].second << '\n';

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

ll ccw(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}