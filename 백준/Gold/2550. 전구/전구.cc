#include <bits/stdc++.h>
using namespace std;

int N, M, pos;
int org[10001];
int key[10001];
int table[10001][2];
vector <int> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> org[i];
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		key[A] = i;
	}
	for (int i = 0; i < N; i++) {
		table[i][0] = 1;
		table[i][1] = i;
		for (int j = i - 1; j >= 0; j--) {
			if (key[org[j]] < key[org[i]]) {
				if (table[j][0] + 1 > table[i][0]) {
					table[i][0] = table[j][0] + 1;
					table[i][1] = j;
				}
			}
		}
		M = max(M, table[i][0]);
	}
	for (int i = 0; i < N; i++) {
		if (table[i][0] == M) {
			pos = i;
			break;
		}
	}
	while (1) {
		v.push_back(org[pos]);
		if (table[pos][1] == pos) break;
		pos = table[pos][1];
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	return 0;
}