#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int D, P;
pair <int, int> arr[351];
int table[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> D >> P;
	for (int i = 0; i < P; i++) cin >> arr[i].first >> arr[i].second;
	memset(table, -1, sizeof(table));
	table[0] = INF;
	for (int i = 0; i < P; i++) {
		for (int j = D; j >= 0; j--) {
			if (arr[i].first > j) break;
			table[j] = max(table[j], min(table[j - arr[i].first], arr[i].second));
		}
	}
	cout << table[D];
	return 0;
}