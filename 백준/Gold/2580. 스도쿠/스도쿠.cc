#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[9][9];
vector <pii> pos;

void BackTracking(int k);
bool check(int x, int y, int k);

void solve() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) pos.push_back({ j,i });
		}
	}
	BackTracking(0);
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

void BackTracking(int k) {	
	if (k == pos.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout << arr[i][j] << " ";
			cout << '\n';
		}
		exit(0);
	}
	else {
		int x = pos[k].first, y = pos[k].second;
		for (int i = 1; i <= 9; i++) {
			if (check(x, y, i)) {
				arr[y][x] = i;
				BackTracking(k + 1);
				arr[y][x] = 0;
			}
		}
	}
	return;
}

bool check(int x, int y, int k) {
	for (int i = 0; i < 9; i++) {
		if (arr[y][i] == k) return false;
		if (arr[i][x] == k) return false;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[(y / 3) * 3 + i][(x / 3) * 3 + j] == k) return false;
		}
	}
	return true;
}