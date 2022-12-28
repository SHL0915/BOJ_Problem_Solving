#include <bits/stdc++.h>
using namespace std;

int N, M;
double input;
pair <int, int> arr[5001];
int table[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		int ans = 0;
		cin >> N >> input;
		input *= 100;
		input += 0.5;
		M = (int)input;
		if (N == 0 && M == 0) break;
		memset(table, 0, sizeof(table));
		for (int i = 1; i <= N; i++) {			
			cin >> arr[i].first >> input;
			input *= 100;
			input += 0.5;
			arr[i].second = (int)input;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= M; j++) {
				if (j - arr[i].second >= 0) table[j] = max(table[j], table[j - arr[i].second] + arr[i].first);
				ans = max(ans, table[j]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}