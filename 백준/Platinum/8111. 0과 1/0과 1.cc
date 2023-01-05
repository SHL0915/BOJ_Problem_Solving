#include <bits/stdc++.h>
using namespace std;

int T, N;
int table[101][20001][2];
int m[101];

int func(int pos, int mod, int now);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		m[0] = 1 % N;
		for (int i = 1; i <= 100; i++) m[i] = (m[i - 1] * 10) % N;	
		memset(table, -1, sizeof(table));
		if (func(0, 0, 0)) {
			cout << '\n';
			continue;
		}
		if (func(0, 1 % N, 1)) {
			cout << '\n';
			continue;
		}
		cout << "BRAK\n";
	}
	return 0;
}

int func(int pos, int mod, int now) {
	if (now == 1 && mod == 0) {
		cout << now;
		return 1;
	}
	if (pos == 99) return 0;
	int& ret = table[pos][mod][now];
	if (ret != -1) return ret;
	ret = 0;
	ret |= func(pos + 1, mod, 0);
	if (ret == 1) {
		cout << now;
		return ret;
	}
	ret |= func(pos + 1, (mod + m[pos + 1]) % N, 1);
	if (ret == 1) {
		cout << now;
		return ret;
	}
	return ret;
}