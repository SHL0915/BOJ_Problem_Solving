#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, ans = INF, t = 1;
pair<int, int> pos = { 1500, 1500 };
int arr[3000][3000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr[pos.second][pos.first] = 1;
	for (int i = 0; i < N; i++) {
		string s;
		int A;
		cin >> s >> A;
		for (int j = 0; j < A; j++) {
			t++;
			switch (s[0]) {
			case 'N': pos.first--; break;
			case 'S': pos.first++; break;
			case 'E': pos.second++; break;
			case 'W': pos.second--; break;
			}
			if (arr[pos.second][pos.first] == 0) arr[pos.second][pos.first] = t;
			else {
				ans = min(ans, t - arr[pos.second][pos.first]);
				arr[pos.second][pos.first] = t;
			}
		}
	}
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}