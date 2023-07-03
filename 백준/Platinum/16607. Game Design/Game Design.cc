#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S, A;
vector <pii> ans;

void solve() {
	cin >> S;

	A += S[0];

	for (int i = 1; i < S.length(); i++) {
		if (S[i] != S[i - 1]) A += S[i];
	}

	int x = 0, y = 0;
	pii s;

	for (int i = 0; i < A.length() - 1; i++) {
		if (A[i] == 'L') {
			pii to = { -(1 << i) - 1, y };
			for (int j = 0; j < ans.size(); j++) {
				pii now = ans[j];
				if (now.second == y) {
					if (now.first < x) to.first = max(to.first, now.first);
				}
			}

			x = to.first + 1;
			ans.push_back(to);
			s = to;
		}
		else if (A[i] == 'R') {
			pii to = { (1 << i) + 1, y };
			for (int j = 0; j < ans.size(); j++) {
				pii now = ans[j];
				if (now.second == y) {
					if (now.first > x) to.first = min(to.first, now.first);
				}
			}

			x = to.first - 1;
			ans.push_back(to);
			s = to;
		}
		else if (A[i] == 'D') {
			pii to = { x, -(1 << i) - 1 };
			for (int j = 0; j < ans.size(); j++) {
				pii now = ans[j];
				if (now.first == x) {
					if (now.second < y) to.second = max(to.second, now.second);
				}
			}

			y = to.second + 1;
			ans.push_back(to);
			s = to;
		}
		else {
			pii to = { x, (1 << i) + 1 };
			for (int j = 0; j < ans.size(); j++) {
				pii now = ans[j];
				if (now.first == x) {
					if (now.second > y) to.second = min(to.second, now.second);
				}
			}

			y = to.second - 1;
			ans.push_back(to);
			s = to;
		}
	}

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	char last = A.back();

	if (last == 'L') {		
		for (int i = 0; i < ans.size(); i++) {
			pii now = ans[i];
			if (now.second == y) {
				if (now.first < x) {
					cout << "impossible";
					return;
				}
			}
		}
		x -= (1 << 20);
	}
	else if (last == 'R') {
		for (int i = 0; i < ans.size(); i++) {
			pii now = ans[i];
			if (now.second == y) {
				if (now.first > x) {
					cout << "impossible";
					return;
				}
			}
		}
		x += (1 << 20);
	}
	else if (last == 'D') {		
		for (int i = 0; i < ans.size(); i++) {
			pii now = ans[i];
			if (now.first == x) {
				if (now.second < y) {
					cout << "impossible";
					return;
				}
			}
		}
		y -= (1 << 20);
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			pii now = ans[i];
			if (now.first == x) {
				if (now.second > y) {
					cout << "impossible";
					return;
				}
			}
		}
		y += (1 << 20);
	}
	
	cout << -x << " " << -y << '\n';
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first - x << " " << ans[i].second - y << '\n';
	}

	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}