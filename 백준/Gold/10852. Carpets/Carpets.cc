#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int W, H, N;
map <pii, int> arr;
int mark[101][101];

void BackTracking();
int check(pii pos, pii area, int val);
void fill(pii pos, pii area, int val);

void solve() {
	cin >> W >> H;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		int a, b;
		cin >> a >> b;
		arr[{a, b}] += k;
	}

	BackTracking();

	cout << "no";
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

void BackTracking() {
	pii pos = { -1, -1 };
	int flag = 0;
	for (int i = 0; i < H; i++) {
		if (flag) break;
		for (int j = 0; j < W; j++) {
			if (mark[i][j] == 0) {
				pos = { j,i };
				flag = 1;
				break;
			}
		}
	}

	if (pos.first == -1) {
		cout << "yes";
		exit(0);
	}

	for (auto i = arr.begin(); i != arr.end(); i++) {
		if ((*i).second == 0) continue;
		(*i).second--;
		pii a = (*i).first;
		pii b = a; swap(b.first, b.second);

		if (W - pos.first >= a.first && H - pos.second >= a.second) {
			if (check(pos, a, 1)) {
				fill(pos, a, 1);
				BackTracking();
				fill(pos, a, 0);
			}
		}

		if (W - pos.first >= b.first && H - pos.second >= b.second) {
			if (check(pos, b, 1)) {
				fill(pos, b, 1);
				BackTracking();
				fill(pos, b, 0);
			}
		}
		(*i).second++;
	}

	return;
}

int check(pii pos, pii area, int val) {
	for (int i = 0; i < area.second; i++) {
		for (int j = 0; j < area.first; j++) {
			if (mark[pos.second + i][pos.first + j] == val) return 0;
		}
	}
	return 1;
}

void fill(pii pos, pii area, int val) {
	for (int i = 0; i < area.second; i++) {
		for (int j = 0; j < area.first; j++) {
			mark[pos.second + i][pos.first + j] = val;
		}
	}
	return;
}